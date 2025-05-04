/*
 * usart.h
 *
 * Created: 14/04/2025 17:24:14
 *  Author: Mnem
 */ 

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// NOTE: FIX CONFIG LOGIC
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

#include <avr/io.h>
#pragma once

// Struct for a set of USART registers
struct USARTPort{
	volatile uint16_t* ubrr;
	volatile uint8_t*  ucsrna;
	volatile uint8_t*  ucsrnb;
	volatile uint8_t*  ucsrnc;
	volatile uint8_t*  udrn;
};

// Struct for a USART instance (for safety, only have *one* per USART port
// at a time).
namespace usart0 {
	IO configure(const uint16_t mode, uint32_t settings_mask){
		// Set registers
		UCSR0A = settings_mask & 0xFF;
		UCSR0B = settings_mask >> 8 & 0xFF;
		UCSR0C = ((settings_mask >> 16) & 0xFF);
	}
		
	// Set baudrate and USART clock mode.
	IO set_baud(uint8_t mode, uint16_t baud){
		// UBRR = (FCPU / (mode * baud)) - 1
		UBRR0 = ((float)F_CPU / ((float)mode * (float)baud)) - 1;
	}

	// Sends a char. Waits until there's something to read.
	IO send_byte(const uint8_t c)
	{
		UCSR0A ^= 0b00011100;    // Clear FEn, DORn, and UPEn, as required
										// by the datasheet
		UCSR0C = (((USART_DD_TXEN| USART_DD_RXEN | USART_CSZ_7) >> 16) & 0xFF);
		while (( UCSR0A & (1<<UDRE0)) == 0) {};
		UDR0 = c;
	}
		
	// Send chars. Takes a null terminated string. Does cursed stuff if the
	// string isn't actually null terminated.
	IO send_chars(char* n){
		for (uint16_t i = 0; n[i] != NULL; i++){
			send_byte(n[i]);
		}
	}
		
	// Send n bytes. Is type safe. The variant with chars is for ASCII.
	template<uint16_t n> IO send_bytes(uint8_t x[n]){
		for (uint16_t i = 0; i < n; i++){
			send_byte(x[n]);
		}
	}
	template<uint16_t n> IO send_chars(char x[n]){
		for (uint16_t i = 0; i < n; i++){
			send_byte(x[n]);
		}
	}
		
	// Get a char from USART. Errors can be masked out in the executing code, as
	// it simply sets err_flag to UCSRnA if there was an error. Does not modify
	// UCSRnA if there was no error.
	inline char getch(register uint8_t* err_flag){
		if ( UCSR0A & ((1<<FE0)|(1<<DOR0)|(1<<UPE0)|(1<<UDRE0)) ){
			*err_flag = UCSR0A; //The exact error can be masked out in error handling code
			return NULL;
		}
		else{
			return UDR0; //Get data out of UDRn
		}
	}
};
