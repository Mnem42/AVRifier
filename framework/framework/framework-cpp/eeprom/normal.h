/*
 * normal.h
 *
 * Created: 04/05/2025 15:05:10
 *  Author: Mnem
 */ 


#ifndef NORMAL_H_
#define NORMAL_H_

uint8_t read_byte(const uint16_t addr){
	// Wait for previous read to finish
	while(EECR & (1<<EEPE));

	EEAR = addr;       // Set addr
	EECR |= (1<<EERE); // Start read

	return EEDR;
}

void write_byte(const uint16_t addr, const uint8_t val){
	// Wait for previous read to finish
	while(EECR & (1<<EEPE));

	EEAR = addr;       // Set addr
	EEDR = val;        // Set data
	EECR |= (1<<EEPE); // Start write
}

#endif /* NORMAL_H_ */