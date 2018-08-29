CC = avr-gcc
CCOBJ = avr-objcopy
EXEC = $1

main:
	$(CC) -Os -mmcu=atmega328p -DF_CPU=16000000UL -c -o $(EXEC).o $(EXEC).c
	$(CC) -mmcu=atmega328p $(EXEC).o -o $(EXEC).elf
	$(CCOBJ) -O ihex -R .eeprom $(EXEC).elf $(EXEC).hex
clean:
	rm $(EXEC).elf
	rm $(EXEC).hex
	rm $(EXEC).o
