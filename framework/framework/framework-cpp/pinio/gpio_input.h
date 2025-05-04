/*
 * gpio_input.h
 *
 * Created: 17/04/2025 14:05:04
 *  Author: Mnem
 */ 


#ifndef GPIO_INPUT_H_
#define GPIO_INPUT_H_

// Read a pin
uint8_t read_pin(volatile uint8_t* pinn, uint8_t pin_offset){
	return pinn & (1 << pin_offset);
}

#endif /* GPIO_INPUT_H_ */