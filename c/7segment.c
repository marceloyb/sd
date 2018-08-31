#include <avr/io.h>
#include <avr/portpins.h>
#include <util/delay.h>
#include "headers/7segment.h"
#include "headers/bitop.h"
#include "headers/button.h"


/* 7 segment: 8 mid
  _2 
7|_|3
6|_|4
 5


*/
short int increment(short int *i){
    *i = (*i+1)%5;
    return *i;
}


int main(void){	
        // PB1 port9 button
        // PB0 port8 led
        // bit in as input
        // DDR = set input or output
        // PIN = read value from circuit
        // PORT = set power from circuit
        
        // PD4 = 2 | PD5 = 3
        // PD6 = 4 | PD7 = 5
        // PB0 = 6 | PB1 = 7
        // PB2 = 8
        DDRB = 0b11110111;
        DDRD = 0b11111111;

        short int i = 0;

        set_button(DDRB, PORTB, PB3);
       
        while(1){
            switch(i){
            //0
            case 0:          
                displaysegment(0);
                break;                
            // 1
            case 1:
                displaysegment(1);
                break;
            // 2
            case 2:
                displaysegment(2);
                break;

            case 3: 
                displaysegment(3);
                break;

            case 4:
                displaysegment(4);
                break;

            }

            button_op(PINB, PB3, increment, &i); 
        }
        
        
	return 0;
}
