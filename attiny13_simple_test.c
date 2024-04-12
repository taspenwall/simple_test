// simpe proiogram to test using interupt in gdb
#include <avr/interrupt.h>
#include  <avr/io.h>
#include <util/delay.h>


#include "avr_mcu_section.h"
AVR_MCU(1000000, "attiny13");

volatile uint8_t trig = 0;
ISR(INT0_vect){
    trig ++;
    PORTB |= (1<<PB2); // to signal we threw an interrupt

    
}

int main(){

    DDRB |= (1<<PB2) | (1<<PB4);

    
    DDRB &= ~(1<<PB1);  //set pb1 as input (don't really need)

    MCUCR &= ~(1<<ISC00) & ~(1<<ISC01); //set low level interupt.
    GIMSK |= (1<<INT0); //enable interupt for INT0

    sei();

    
    while (!trig){
        
    }

    PORTB |= (1<<PB4); //to signal we are out of the loop

}