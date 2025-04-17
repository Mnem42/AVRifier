/*
 * usart.h
 *
 * Created: 14/04/2025 17:24:14
 *  Author: Mnem
 */ 

#include <avr/io.h>

#ifndef USART_H_
#define USART_H_

typedef struct {
	unsigned int usart_inited : 1;
	unsigned int rx : 1;
	unsigned int tx : 1;
} USARTInfo;

IO init_usart0(USARTInfo* state, uint16_t baud, uint8_t mode){
	uint16_t ubrr = (uint16_t)((float)(3333333 * 64 / (mode * (float)baud)) + 0.5);
	
	UBRR0 = ubrr;
	
	UCSR0B = (state->tx << TXEN0) | (state->rx << RXEN0);
	
	state->usart_inited = 1;
};

void send_usart0(uint8_t c)
{
	while ( ( UCSR0A & TXC0) ) {
		;
	}
	UDR0 = c;
}

#endif /* USART_H_ */