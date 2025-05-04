/*
 * output.h
 *
 * Created: 14/04/2025 13:10:06
 *  Author: Mnem
 */ 


#ifndef OUTPUT_H_
#define OUTPUT_H_

typedef enum{
	High = 1,
	Low  = 0	
} OutputValue;

// Activate a specific pin
IO activate_pin(volatile register uint8_t* portn, const uint8_t pin_offset){
	*portn |= ( 0x01 << pin_offset );
}

// Deactivate a specific pin
IO deactivate_pin(volatile register uint8_t* portn, const uint8_t pin_offset){
	*portn &= ( 0x01 << pin_offset );
}

// More efficient than branching with activate_pin and deactivate_pin
IO set_pin(volatile uint8_t* portn, const uint8_t pin_offset, OutputValue mode){
	uint8_t tmp = mode << pin_offset;
	*portn = (*portn & ~((1 << pin_offset)) | mode << pin_offset);
}

// Flip a specific pin
IO flip_pin(volatile register uint8_t* portn, const uint8_t pin_offset){
	*portn ^= ( 0x01 << pin_offset );
}

#endif /* OUTPUT_H_ */