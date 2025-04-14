/*
 * framework.c
 *
 * Created: 14/04/2025 12:24:20
 * Author : Mnem
 */ 

#include <avr/io.h>
#include "framework.h"

int main(void) {
	DDRD |= 0x00;
	set_pin_mode_PORTD(2, OUTPUT);
    /* Replace with your application code */
    while (1) 
    {
		flip_pin_PORTD(2);
    }
}

