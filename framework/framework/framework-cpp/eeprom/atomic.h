/*
 * atomic.h
 *
 * Created: 04/05/2025 15:06:20
 *  Author: Mnem
 */ 

#include <util/atomic.h>

#ifndef ATOMIC_H_
#define ATOMIC_H_

uint8_t read_byte(const uint16_t addr){
	ATOMIC_BLOCK(ATOMIC_FORCEON){
		// Wait for previous read to finish
		while(EECR & (1<<EEPE));

		EEAR = addr;       // Set addr
		EECR |= (1<<EERE); // Start read
		return EEDR;
	}	
}

void write_byte(const uint16_t addr, const uint8_t val){
	ATOMIC_BLOCK(ATOMIC_FORCEON){
		// Wait for previous read to finish
		while(EECR & (1<<EEPE));

		EEAR = addr;       // Set addr
		EEDR = val;        // Set data
		EECR |= (1<<EEPE); // Start write
	}
}

#endif /* ATOMIC_H_ */