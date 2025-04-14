/*
 * ioconfig.h
 *
 * Created: 14/04/2025 13:12:22
 *  Author: Mnem
 */ 


#ifndef IOCONFIG_H_
#define IOCONFIG_H_

typedef enum {
	INPUT  = 0,
	OUTPUT = 1
} PinMode;

IO set_pin_mode_PORTB(const uint8_t pin_offset, PinMode mode){
	if (mode) {
		DDRD ^= mode << pin_offset;
	}
	else {
		DDRD |= mode << pin_offset;
	}
}

IO set_pin_mode_PORTD(const uint8_t pin_offset, PinMode mode){
	if (mode) {
		DDRD ^= mode << pin_offset;
	}
	else {
		DDRD |= mode << pin_offset;
	}
}

#endif /* IOCONFIG_H_ */