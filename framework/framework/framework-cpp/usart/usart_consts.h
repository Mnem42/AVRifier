/*
 * usart_consts.h
 *
 * Created: 17/04/2025 13:20:32
 *  Author: Ishaan
 */ 


#ifndef USART_CONSTS_H_
#define USART_CONSTS_H_

// ----------------------------------------------------------------------------
// USART settings, A

// USART mode settings (see UMSELn)
#define USART_ASYNC 0b00000000 // Asynchronous USART (default, is just a hint)
#define USART_SYNC  0b01000000 // Synchronous USART
#define USART_MSPIM 0b11000000 // Master SPI mode

// ----------------------------------------------------------------------------
// USART settings, B

// ISR settings
#define USART_ISR_DRE 0b00100000 << 8 // Enable data register empty ISR
#define USART_ISR_DRE 0b01000000 << 8 // Enable TX complete ISR
#define USART_ISR_DRE 0b10000000 << 8 // Enable RX complete ISR

// Data direction settings
#define USART_DD_TXEN 0b00001000 << 8 // Enable TX
#define USART_DD_RXEN 0b00010000 << 8 // Enable RX

// ----------------------------------------------------------------------------
// USART settings, C

// Clocking
#define USART_LSBF  0b00000100 << 16 // UDORDn, LSB first
#define USART_TXR   0b00000010 << 16 // UCPHAn, transmit on rising edge
#define USART_RXR   0b00000001 << 16 // UCPOLn, receive on rising edge

// Character size
#define USART_CSZ_5   0b00000000 << 16              // 5 bits
#define USART_CSZ_6   0b00000010 << 16              // 6 bits
#define USART_CSZ_7   0b00000100 << 16              // 7 bits
#define USART_CSZ_8   0b00000110 << 16              // 8 bits
#define USART_CSZ_9   USART_CSZ_8 | 0b00000100 << 8 // 9 bits, also sets a bit
                                                    // in UCSRnB
// ----------------------------------------------------------------------------

#endif /* USART_CONSTS_H_ */