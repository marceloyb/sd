#include <avr/io.h>
#include <avr/portpins.h>
#include <util/delay.h>

#define swt_bit(reg, pos) (reg ^= (1 << pos))	// mudança de estado
#define clr_bit(reg, pos) (reg &= ~(1 << pos))	// limpar os bits de uma pos
#define set_bit(reg, pos) (reg |= (1 << pos))	// setar bits 
#define isset_bit(reg, pos) (reg & (1 << pos)) // check if bit set

/* 7 segment: 8 mid
  _2 
7|_|3
6|_|4
 5


*/


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
        clr_bit(DDRB, PB3);
        set_bit(PORTB, PB3);
        // 2
        while(1){
            switch(i){
            //0
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

            // button
            if(!isset_bit(PINB, PB3)){
                i = (i+1)%5;
                while(!isset_bit(PINB, PB3))
                    _delay_ms(10);
                while(!isset_bit(PINB,PB3)){
                    
                }
            }
        }
        
        
	return 0;
}
