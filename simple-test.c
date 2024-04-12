// this is the x86 program for simple-test

#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>


#include "sim_avr.h"
#include "sim_gdb.h"
#include "sim_elf.h"
#include "trigger.h"

#include "avr_ioport.h"



avr_t * avr = NULL;
trigger_t t;

volatile int state = cpu_Running;




int main(int argc, char *argv[]){


    elf_firmware_t f = {{0}};
	const char * fname = "attiny13_simple_test.axf";

    elf_read_firmware(fname, &f);

    
    printf("firmware %s f=%d mmcu=%s\n", fname, (int) f.frequency, f.mmcu);

    avr = avr_make_mcu_by_name(f.mmcu);

    if (!avr) {
		printf("loading avr failed");
		exit(1);
	}

    avr_init(avr);
    avr_load_firmware(avr, &f);

    avr->gdb_port = 1234;
	avr->state = cpu_Stopped;
	avr_gdb_init(avr);  

    
    printf("connect GDB enter char to contine and set a break point to enter the trigger");
    char input = getchar();
    char dummy = getchar(); //  when I hit enter I seem to read that as a char

    
    //while ((state != cpu_Done) && (state != cpu_Crashed) && (state != cpu_Stopped)) 
    while ((state != cpu_Done) && (state != cpu_Crashed)){
       
        state = avr_run(avr); //this sould run until the breakpoint
    }
    /*
    printf("enter char to fire trigger\n");
    input = getchar();
    dummy = getchar();

    printf("setting trigger");
    
    trigger_init(avr, &t);
    
    avr_raise_irq(t.irq + IRQ_TRIGGER_IN, 0);

    printf("enter char to drop back into running mode");
    input = getchar();
    dummy = getchar();

    while ((state != cpu_Done) && (state != cpu_Crashed)){ //run to end of program
        state = avr_run(avr);
    }
    */
    printf("end of program"); 
    input += dummy; //get rig of the unused var message
    

    
    return 0;



      

}
