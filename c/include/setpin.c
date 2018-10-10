#include "setpin.h"

uint8_t finalpos(uint8_t position){
	uint8_t finalpin;
	finalpin = position % 8;
	return finalpin;
}

void setpinmode(uint8_t mode, uint8_t position){
	// input = clr
	// output = set
	uint8_t pin;


	pin = finalpos(position);

	if (position >= 8){
		// input
		if (mode == 0){
			clr_bit(DDRB, pin);
		}
		// output
		if (mode == 1){
			set_bit(DDRB, pin);
		}

		// pullup
	}
	if (position < 8){
		// input
		if (mode == 0){
			clr_bit(DDRD, pin);
		}
		// output
		if (mode == 1){
			set_bit(DDRD, pin);
		}

		// pullup
	}

}

void setpinvalue(uint8_t value, uint8_t position){
	// input = clr
	// output = set
	uint8_t pin;


	pin = finalpos(position);

	if (position >= 8){
		// value
		if (value == 0){
			clr_bit(PORTB, pin);
		}
		// high
		if (value == 1){
			set_bit(PORTB, pin);
		}
	}
	if (position < 8){
		// low
		if (value == 0){
			clr_bit(PORTD, pin);
		}
		// high
		if (value == 1){
			set_bit(PORTD, pin);
		}
	}

}