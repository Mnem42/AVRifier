/*
 * output.h
 *
 * Created: 14/04/2025 13:10:06
 *  Author: Mnem
 */ 


#ifndef OUTPUT_H_
#define OUTPUT_H_

// Activate a specific pin
IO activate_pin(volatile register uint8_t* portn, const uint8_t pin_offset){
	*portn |= ( 0x01 << pin_offset );
}

// Deactivate a specific pin
IO deactivate_pin(volatile register uint8_t* portn, const uint8_t pin_offset){
	*portn &= ( 0x01 << pin_offset );
}

// More efficient than branching with activate_pin and deactivate_pin
IO set_pin(volatile uint8_t* portn, const uint8_t pin_offset, PinMode mode){
	uint8_t tmp = mode << pin_offset;
	*portn = *portn & (1 << pin_offset) | tmp; // Mask out the pin to be toggled,
											   // and then OR in the value shifted
											   // by the offset
}

// Flip a specific pin
IO flip_pin(volatile register uint8_t* portn, const uint8_t pin_offset){
	*portn ^= ( 0x01 << pin_offset );
}

#endif /* OUTPUT_H_ */