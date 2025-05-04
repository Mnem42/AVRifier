/*
 * framework.h
 *
 * Created: 14/04/2025 17:23:15
 *  Author: Mnem
 */ 


#ifndef FRAMEWORK_H_
#define FRAMEWORK_H_

#ifdef FRM_HINT_INLINE
#define IO volatile inline void
#else
#define IO volatile void
#endif

#define NULL 0

#include "pinio/pinio.h"

// #include "usart/usart.h" (completely nonfunctional)

#endif /* FRAMEWORK_H_ */