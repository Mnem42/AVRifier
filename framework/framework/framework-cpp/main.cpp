/*
 * framework.c
 *
 * Created: 14/04/2025 12:24:20
 * Author : Mnem
 */ 

// #define FRM_NO_INLINE

#define F_CPU 8000000
//#define FRM_HINT_INLINE

#include <avr/io.h>
#include "framework.h"

int main(void) {
	usart::USART usart0 = usart::USART(usart_periph::USART0, USART_ASYNC,  USART_DD_RXEN | USART_DD_TXEN);
	usart0.reconfigure(USART_SYNC, USART_DD_RXEN);
	
	usart0.set_baud(USART_CK_ANM, 9600);
	usart0.send_char('t');
	
	uint8_t errflag = NULL;
	char ch = usart0.getch(&errflag);
	
	char chars[2] = {'h', 'i'};
	usart0.send_bytes<2>(chars);
	
	usart0.send_chars("hello world");
}