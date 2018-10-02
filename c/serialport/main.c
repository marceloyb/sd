#include "uart.h"
#include <avr/io.h>
#include <stdbool.h>
#include <util/delay.h>

#define TRIGGER (1 << 4)
#define ECHO (1 << 5)

#define SET_BIT(REG, FLAGS) (REG |= (FLAGS))
#define CLEAR_BIT(REG, FLAGS) (REG &= ~(FLAGS))
#define SWP_BIT(REG, FLAGS) (REG ^= (FLAGS))
#define IS_BIT_SET(REG, N) (REG & (N))

int main(void) {
	uint32_t i;
	uint8_t j;
	SET_BIT(DDRB, TRIGGER);
	CLEAR_BIT(DDRB, ECHO);

	uart_init();

while (true) {
	SET_BIT(PORTB, TRIGGER);
	_delay_us(10);
	CLEAR_BIT(PORTB, TRIGGER);

	i = 0;
	while (!IS_BIT_SET(PINB, ECHO));

	while (IS_BIT_SET(PINB, ECHO)) {
		_delay_us(1);
		i++;
		j++;
		if (j >= 13){
			i += 10;
			j = 0;
		}
	}

	printf("%lu\n", i / 58);

	_delay_ms(500);
}

	return 0;
}