/*  trigger.c
    This is a project to use and emualte an avr using avrsim 
    avrsim is by Michel Pollet <buserror@gmail.com> and copyrighted 2008, 2009
please see https://github.com/buserror/simavr for license and reference
*/
#include <stdlib.h>
#include <stdio.h>
#include "sim_avr.h"
#include "avr_ioport.h"
#include "trigger.h"



static const char * _trigger_irq_names[1] = {
    [IRQ_TRIGGER_PULL]= ">trigger_pull"
};
	
void trigger_init(avr_t *avr, trigger_t * t){
    //avr_alloc_irq(&avr->irq_pool, 0, IRQ_BUTTON_COUNT, &name);
    t->irq = avr_alloc_irq(&avr->irq_pool, 0, IRQ_TRIGGER_COUNT, _trigger_irq_names);
    t->avr = avr;
    avr_connect_irq(t->irq + IRQ_TRIGGER_IN, avr_io_getirq(avr, AVR_IOCTL_IOPORT_GETIRQ('B'), 1)); //PB1 for INT0 pin. port B pin #1 
     //PB1 also calles interrupt vector PCINT1 on the at13, I'm not sure how avrsim handles that?  MAybe with no ISR it just doesn't care? 

}   


void trigger_press(trigger_t *t){
    avr_raise_irq(t->irq+IRQ_TRIGGER_IN,0); // should the 0 be a 1 to set the pin state?? Do I need to set it to 0 before I set it to 1??

}

