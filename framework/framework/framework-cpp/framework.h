/*
 * framework.h
 *
 * Created: 14/04/2025 17:23:15
 *  Author: Mnem
 */ 


#ifndef FRAMEWORK_H_
#define FRAMEWORK_H_

#ifdef FRM_HINT_INLINE
#define IO inline void
#else
#define IO void
#endif

#define NULL 0

#include "pinio/pinio.h"

#include "usart/usart.h"

#endif /* FRAMEWORK_H_ */