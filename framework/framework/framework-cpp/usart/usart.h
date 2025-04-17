/*
 * usart.h
 *
 * Created: 14/04/2025 17:24:14
 *  Author: Mnem
 */ 

#include <avr/io.h>

#ifndef USART_H_
#define USART_H_

// ----------------------------------------------------------------------------
// USART clock settings
#define USART_CK_ANM 16 // Asynchronous normal mode
#define USART_CK_DSM 8  // Double speed normal mode
#define USART_CK_SMM 2  // Synchronous master mode

namespace usart{
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
	struct USART {
	private:
		// IO registers
		volatile uint16_t* ubrr;
		volatile uint8_t* ucsrna;
		volatile uint8_t* ucsrnb;
		volatile uint8_t* ucsrnc;
		volatile uint8_t* udrn;

	public:
		// Initialise
		USART(const USARTPort port, const uint16_t mode, const uint32_t settings_mask){
			//Set pointers to registers
			this->ubrr   = port.ubrr;
			this->ucsrna = port.ucsrna;
			this->ucsrnb = port.ucsrnb;
			this->ucsrnc = port.ucsrnc;
			this->udrn   = port.udrn;

			// Set registers
			*this->ucsrnb = settings_mask >> 8 & 0xFF;
			*this->ucsrnc = mode | settings_mask >> 16 &0xFF;
		}
		
		IO reconfigure(const uint16_t mode, const uint32_t settings_mask){
			// Set registers
			*this->ucsrna = settings_mask & 0xFF;
			*this->ucsrnb = settings_mask >> 8 & 0xFF;
			*this->ucsrnc = mode | (settings_mask >> 16 &0xFF);
		}
		
		// Set baudrate and USART clock mode.
		IO set_baud(uint8_t mode, uint16_t baud){
			// UBRR = (FCPU / mode * baud) - 1
			*this->ubrr   = (uint16_t)((float)F_CPU / mode * (float)baud)-1;
		}

		// Sends a char. Waits until there's something to read.
		IO send_char(uint8_t c)
		{
			*this->ucsrna &= 0b11100011; // Clear FEn, DORn, and UPEn, as required
										 // by the datasheet
			while ( !(*this->ucsrna & (1 << UDRE0)) ) {
				;
			}
			*this->udrn = c;
		}
		
		// Send chars. Takes a null terminated string. Does cursed stuff if the
		// string isn't actually null terminated.
		IO send_chars(char* n){
			for (uint16_t i = 0; n[i] != NULL; i++){
				send_char(n[i]);
			}
		}
		
		// Send n bytes. Is type safe.
		template<uint16_t n> IO send_bytes(uint8_t x[n]){
			for (uint16_t i = 0; i < n; i++){
				send_char(x[n]);
			}
		}
		template<uint16_t n> IO send_bytes(char x[n]){
			for (uint16_t i = 0; i < n; i++){
				send_char(x[n]);
			}
		}
		
		// Get a char from USART. Errors can be masked out, and it simply sets
		// err_flag to UCSRnA if there was an error.
		inline char getch(register uint8_t* err_flag){
			if ( *this->ucsrna & ((1<<FE0)|(1<<DOR0)|(1<<UPE0)|(1<<UDRE0)) ){
				*err_flag = *ucsrna; //The exact error can be masked out in error handling code
				return NULL;
			}
			else{
				return *this->udrn; //Get data out of UDRn
			}
		}
	};
}
#endif /* USART_H_ */