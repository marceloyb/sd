#include <avr/io.h>
#include <avr/portpins.h>
#include <util/delay.h>
#include "bitop.h"

#ifndef _setpin_h
#define _setpin_h

#define input 0
#define output 1
#define pullup 2

uint8_t finalpos(uint8_t position);

uint8_t setmode(uint8_t mode, uint8_t position);

#endif

