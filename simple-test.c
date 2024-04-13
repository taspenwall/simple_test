/* simple_test.c 

 This is a project to use and emualte an avr using avrsim 
    avrsim is by Michel Pollet <buserror@gmail.com> and copyrighted 2008, 2009
please see https://github.com/buserror/simavr for license and reference
*/
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

    
    printf("connect GDB and press enter\n");
    printf("to break and trigger interrupt... step one instruction");
    char dummy = getchar(); //  when I hit enter I seem to read that as a char

    
    
    while ((state != cpu_Crashed) && (state != cpu_Done) && (state != cpu_StepDone))
     {  
        state = avr_run(avr); 
    
    

    printf("setting interrupt!!! press enter to go back to gdb\n");
    
    trigger_init(avr, &t);
    trigger_press(&t);
    
    dummy = getchar();

    printf("back in gdb quit gdb to end program\n");
    while((state != cpu_Done) && (state != cpu_Crashed)){
        state=avr_run(avr);
    }


    dummy += 1;
    return 0;



      

}
