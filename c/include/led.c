#include "led.h"



void led_on(uint8_t position){
	// input = clr
	// output = set
	uint8_t pin;

	pin = finalpos(position);

	if (position >= 8){
		set_bit(PORTB, pin);
	}

	if (position < 8){
		set_bit(PORTD, pin);
	}

}

void led_off(uint8_t position){
	// input = clr
	// output = set
	uint8_t pin;

	pin = finalpos(position);

	if (position >= 8){
		clr_bit(PORTB, pin);
	}

	if (position < 8){
		clr_bit(PORTD, pin);
	}

}

void blink_led(uint8_t position, double delay){

	uint8_t pin;

	pin = finalpos(position);

	if (position >= 8){
		swt_bit(PORTB, pin);
		_delay_ms(delay);
	}

	if (position < 8){
		swt_bit(PORTD, pin);
		_delay_ms(delay);
	}	

}