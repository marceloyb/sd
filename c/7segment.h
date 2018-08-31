#include "bitop.h"
#ifndef _7segment_h
#define _7segment_h
        

int displaysegment(int number){ 
            // 0
        switch(number){
            case 0:          
                clr_bit(PORTD, PD6);
                clr_bit(PORTD, PD4);
                clr_bit(PORTD, PD5);
                clr_bit(PORTD, PD7);
                clr_bit(PORTB, PB0);
                clr_bit(PORTB, PB1);
                set_bit(PORTB, PB2);
                break;
            // 1
            case 1:
                set_bit(PORTD, PD4);
                clr_bit(PORTD, PD5);
                clr_bit(PORTD, PD6);
                set_bit(PORTD, PD7);
                set_bit(PORTB, PB0);
                set_bit(PORTB, PB1);
                set_bit(PORTB, PB2);
                break;
            // 2
            case 2:
                clr_bit(PORTD, PD4);
                clr_bit(PORTD, PD5);
                set_bit(PORTD, PD6);
                clr_bit(PORTD, PD7);
                clr_bit(PORTB, PB0);
                set_bit(PORTB, PB1);
                clr_bit(PORTB, PB2);
                
                break;

            case 3: 
                clr_bit(PORTD, PD4);
                clr_bit(PORTD, PD5);
                clr_bit(PORTD, PD6);
                clr_bit(PORTD, PD7);
                set_bit(PORTB, PB0);
                set_bit(PORTB, PB1);
                clr_bit(PORTB, PB2);
                break;

            case 4:
                set_bit(PORTD, PD4);
                clr_bit(PORTD, PD5);
                clr_bit(PORTD, PD6);
                set_bit(PORTD, PD7);
                set_bit(PORTB, PB0);
                clr_bit(PORTB, PB1);
                clr_bit(PORTB, PB2);

                break;
        }
}

#endif


