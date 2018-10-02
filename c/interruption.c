#include <avr/io.h>
#include <avr/portpins.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "include/7segment.h"
#include "include/bitop.h"
#include "include/button.h"


ISR(INT0_vect);
ISR(INT1_vect);

int main(void){	
        // PB1 port9 button
        // PB0 port8 led
        // bit in as input
        // DDR = set input or output
        // PIN = read value from circuit
        // PORT = set power from circuit
        
        // pb4 = button1 pb5 = button2
        short int i = 0;

//        set_button(DDRB, PORTB, PB1);
//        set_button(DDRB, PORTB, PB2);
        
       
        DDRB = 0b00000001;
        PORTB = 0b11111110;
 
        DDRD = 0x00;
        PORTD = 0xFF;
        UCSR0B = 0x00;
        EICRA = 1<<ISC01;
        EIMSK = (1<<INT1) | (1<<INT0);
        sei();
 
        
        while(1){}
}

ISR(INT0_vect){
    swt_bit(PORTB, PB0);
}


ISR(INT1_vect){
    swt_bit(PORTB, PB0);
    _delay_ms(200);
}


