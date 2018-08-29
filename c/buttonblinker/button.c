#include <avr/io.h>
#include <avr/portpins.h>
#include <util/delay.h>

#define swt_bit(reg, pos) (reg ^= (1 << pos))	// mudança de estado
#define clr_bit(reg, pos) (reg &= ~(1 << pos))	// limpar os bits de uma pos
#define set_bit(reg, pos) (reg |= (1 << pos))	// setar bits 
#define isset_bit(reg, pos) (reg & (1 << pos)) // check if bit set

int main(void){	
        // PB1 port9 button
        // PB0 port8 led
        // bit in as input
        // DDR = set input or output
        // PIN = read value from circuit
        // PORT = set power from circuit
        clr_bit(DDRB, PB1);
    

        set_bit(DDRB, PB0);

        set_bit(PORTB, PB1);
        
	while (1) {
		
            if(!isset_bit(PINB, PB1)){
                swt_bit(PORTB, PB0);
                while (!isset_bit(PINB,PB1)); // Aguarde o botão ser solto
                _delay_ms(10);
        
            }
                
	}

	return 0;
}
