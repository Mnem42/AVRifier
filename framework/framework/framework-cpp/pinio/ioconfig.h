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

IO set_pin_mode(volatile uint8_t* ddrn, const uint8_t pin_offset, const PinMode mode){
	*ddrn = (*ddrn & ~((1 << pin_offset)) | mode << pin_offset);
}

#endif /* IOCONFIG_H_ */