/*
 * usart_periph.h
 *
 * Created: 15/04/2025 17:22:29
 *  Author: Mnem
 */ 


#pragma once

#ifdef UBRR0

const USARTPort USART0 = {
	.ubrr   = &UBRR0,
	.ucsrna = &UCSR0A,
	.ucsrnb = &UCSR0B,
	.ucsrnc = &UCSR0C,
	.udrn   = &UDR0
};
#endif

#ifdef UBRR1
const USARTPort USART0 = {
	.ubrr   = &UBRR1,
	.ucsrna = &UCSR1A,
	.ucsrnb = &UCSR1B,
	.ucsrnc = &UCSR1C
	.udrn   = &UDR1
};
#endif
