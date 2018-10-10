#include <avr/io.h>
#include <avr/portpins.h>
#include <util/delay.h>
#include "bitop.h"
#include "setpin.h"

#ifndef _led_h
#define _led_h

#define input 0
#define output 1
#define pullup 2

// methods need position of led in arduino
// in case of blink led, the delay between the blink is needed

void blink_led(uint8_t position, double delay);

void led_on(uint8_t position);

void led_off(uint8_t position);

#endif

