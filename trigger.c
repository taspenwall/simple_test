//trigger.c

#include <stdlib.h>
#include <stdio.h>
#include "sim_avr.h"
#include "trigger.h"



static const char * _trigger_irq_names[1] = {
    [IRQ_TRIGGER_PULL]= ">trigger_pull"
};
	
void trigger_init(avr_t *avr, trigger_t * t){
    //avr_alloc_irq(&avr->irq_pool, 0, IRQ_BUTTON_COUNT, &name);
    t->irq = avr_alloc_irq(&avr->irq_pool, 0, IRQ_TRIGGER_COUNT, _trigger_irq_names);
    t->avr = avr;

}


void trigger_press(trigger_t *t){
    avr_raise_irq(t->irq+IRQ_TRIGGER_IN,0);

}

