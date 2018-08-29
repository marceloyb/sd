
inicio:
	ldi R16, 0b00100000
	out DDRB, R16

principal:
	sbi PORTB, PB5
	rcall atraso
	cbi PORTB, PB5
	rcall atraso
	rjmp principal

atraso:
	ldi R19, 16	
	volta:
		dec R17
		brne volta
		dec R18
		brne volta
		dec R19
		brne volta
	ret
	
