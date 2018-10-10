#include "setpin.h"

char dorb(uint8_t position){
	uint8_t port;

	if (position > 7){
		port = 1;
	}
	
	else if (position <= 7){
		port = 0;
	}
	return port;
}

uint8_t finalpos(uint8_t position){
	uint8_t finalpin;
	finalpin = position % 8;
	return finalpin;
}

uint8_t setmode(uint8_t mode, uint8_t position){
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