/*
 * framework.c
 *
 * Created: 14/04/2025 12:24:20
 * Author : Mnem
 */ 

// #define FRM_NO_INLINE

#define F_CPU 8000000
#define FRM_HINT_INLINE

#include <avr/io.h>
#include "framework.h"

using namespace gpio;

int main(void) {
	set_pin_mode(&DDRD, 3, OUTPUT);
	activate_pin(&PORTD, 3);
	
	while (1) {
		flip_pin(&PORTD, 3);
	}
}