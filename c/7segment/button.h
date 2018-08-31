#include "bitop.h"
#include <util/delay.h>

#ifndef _button_h
#define _button_h

#define set_button(DDR, PORT, P)\
    clr_bit(DDR, P);\
    set_bit(PORT, P);
    
#define button_op(PIN, P, OP, ARG)\
    if(!isset_bit(PIN, P)){\
        void *arg = ARG;\
        OP(arg);\
    while(!isset_bit(PIN, P))\
        _delay_ms(10);\
    while(!isset_bit(PIN,P)){\
    }\
}

#endif
