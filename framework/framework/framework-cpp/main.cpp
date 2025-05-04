/*
 * framework.c
 *
 * Created: 14/04/2025 12:24:20
 * Author : Mnem
 */ 

// #define FRM_NO_INLINE

#define F_CPU 16000000
#define FRM_HINT_INLINE

#include <avr/io.h>
#include <avr/delay.h>
#include "framework.h"

using namespace gpio;
using namespace usart;

int main(void) {
	volatile uint8_t c = 0x00;
	//usart0::configure(USART_ASYNC,USART_DD_TXEN| USART_DD_RXEN | USART_CSZ_7);
	while (1) {
		usart0::configure(USART_SYNC,USART_DD_TXEN| USART_DD_RXEN | USART_CSZ_7);
		usart0::send_byte(c);
		// _delay_ms(100);
		c += 1;
	}
}