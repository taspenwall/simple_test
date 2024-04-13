/* trigger.h
  This is a project to use and emualte an avr using avrsim 
    avrsim is by Michel Pollet <buserror@gmail.com> and copyrighted 2008, 2009
please see https://github.com/buserror/simavr for license and reference
*/


#include "sim_irq.h"
#include "sim_avr.h"

enum {
    IRQ_TRIGGER_IN = 0,
    IRQ_TRIGGER_COUNT
};

enum {
    IRQ_TRIGGER_PULL = 0,
};


typedef struct trigger_t{
    avr_irq_t * irq;
    struct avr_t * avr;
    uint8_t value;
} trigger_t;

void trigger_init(avr_t *avr, trigger_t *t);

void trigger_press(trigger_t *t);