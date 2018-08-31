#!/bin/sh
EXEC=$1


avr-gcc -Os -mmcu=atmega328p -DF_CPU=16000000 -c -o $EXEC.o $EXEC.c
avr-gcc -mmcu=atmega328p $EXEC.o -o $EXEC.elf
avr-objcopy -O ihex -R .eeprom $EXEC.elf $EXEC.hex
avrdude -V -C /etc/avrdude.conf -p atmega328p -c arduino -P /dev/ttyACM0 -b 115200 -D -Uflash:w:$EXEC.hex:i


rm $EXEC.elf
rm $EXEC.hex
rm $EXEC.o
