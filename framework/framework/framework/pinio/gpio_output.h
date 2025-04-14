/*
 * output.h
 *
 * Created: 14/04/2025 13:10:06
 *  Author: Mnem
 */ 


#ifndef OUTPUT_H_
#define OUTPUT_H_

IO activate_pin_PORTD(const uint8_t pin_offset){
	PORTD |= ( 0x01 << pin_offset );
}
IO deactivate_pin_PORTD(const uint8_t pin_offset){
	PORTD &= ( 0x01 << pin_offset );
}

IO flip_pin_PORTD(const uint8_t pin_offset){
	PORTD ^= ( 0x01 << pin_offset );
}

IO activate_pin_PORTB(const uint8_t pin_offset){
	PORTB |= ( 0x01 << pin_offset );
}

IO flip_pin_PORTB(const uint8_t pin_offset){
	PORTB ^= ( 0x01 << pin_offset );
}

#endif /* OUTPUT_H_ */