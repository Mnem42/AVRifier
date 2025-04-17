/*
 * framework.c
 *
 * Created: 14/04/2025 12:24:20
 * Author : Mnem
 */ 

// #define FRM_NO_INLINE

#include <avr/io.h>
#include "framework.h"

int main(void) {
	USARTInfo setup = {
		.usart_inited = 0,
		.tx = 1,
		.rx = 1
	};
	
	init_usart0(&setup, 9600, 16);
	send_usart0('t');
	
	PORTA = 0xFF;
}

