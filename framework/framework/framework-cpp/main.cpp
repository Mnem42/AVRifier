/*
 * framework.c
 *
 * Created: 14/04/2025 12:24:20
 * Author : Mnem
 */ 

// #define FRM_NO_INLINE

#define F_CPU 16000000
#define FRM_HINT_INLINE
#define FRM_USE_CPP

#include <avr/io.h>
#include <avr/delay.h>
#include "framework.h"

int main(void) {
	pinio::set_pin_mode(&DDRB, 7, pinio::OUTPUT);
	pinio::activate_pin(&PORTB, 7);
	_delay_ms(1000);
	pinio::deactivate_pin(&PORTB, 7);
	_delay_ms(1000);
	
	eeprom::atomic::write_byte(0x01, 0xFF);
	uint8_t tmp = eeprom::atomic::read_byte(0x01);
	
	pinio::activate_pin(&PORTB, 7);

	/*while(1){
		gpio::flip_pin(&DDRB, 7);
		_delay_ms(1000);
	}*/
}