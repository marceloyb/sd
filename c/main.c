#include <avr/io.h>
#include <avr/portpins.h>
#include <util/delay.h>
#include "include/setpin.h"
#include "include/led.h"
#define swt_bit(reg, pos) (reg ^= (1 << pos))	// mudança de estado
#define clr_bit(reg, pos) (reg &= ~(1 << pos))	// limpar os bits de uma pos
#define set_bit(reg, pos) (reg |= (1 << pos))	// setar bits 
#define isset_bit(reg, pos) (reg & (1 << pos)) // check if bit set

#define input 0
#define output 1
int main(void){	
        // PB1 port9 button
        // PB0 port8 led
        // bit in as input
        // DDR = set input or output
        // PIN = read value from circuit
        // PORT = set power from circuit
//        clr_bit(DDRB, PB1);
//   		DDRB = 00000010; 
//		PORTB = 00000010;
		setpinmode(output, 9);
//        set_bit(DDRD, PD3);
    setpinvalue(high, 9);
    
    while(1){
		  blink_led(9, 300);
    }
//		while (1) {
		
         //   if(!isset_bit(PINB, PB1)){
  //              swt_bit(PORTB, PB0);
               // while (!isset_bit(PINB,PB1)); // Aguarde o botão ser solto
    //            _delay_ms(300);
        
           // }
                
//	}

	return 0;
}
