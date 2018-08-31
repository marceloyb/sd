#include <avr/io.h>
#include <avr/portpins.h>
#include <util/delay.h>
//#include <time.h>
//#include <stdlib.h>

#define swt_bit (reg, pos) (reg ^= (1 << pos))	// mudança de estado
#define clr_bit (reg, pos) (reg &= ~(1 << pos))	// limpar os bits de uma pos
#define set_bit (reg, pos) (reg |= (1 << pos))	// setar bits 

// #define F_CPU 16000000UL

int main(void)
{	

//	srand(time(NULL));   // should only be called once
//	int r = rand() % 200; 

	DDRB = (1<<PB0);    
        DDRB |= (1<<PB1);   //set_bit(DDRB, PB1);
        DDRB |= (1<<PB2);   //set_bit(DDRB, PB2);

	while (1) {
		PORTB |= (1<<PB0);
		_delay_ms(2000);
		PORTB &= ~(1<<PB0);
		_delay_ms(200);

                PORTB |= (1<<PB2);
                _delay_ms(6000);
                PORTB &= ~(1<<PB2);
                _delay_ms(600);

                PORTB |= (1<<PB1);
        	_delay_ms(6000);
		PORTB &= ~(1<<PB1);
		_delay_ms(600);

	}

	return 0;
}
