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

#ifdef USE_CPP
#define __FRM_IS_CPP
#include "pinio/pinio.hpp"
#include "eeprom/eeprom.hpp"
// #include "usart/usart.h" (completely nonfunctional)
#else
#include "pinio/pinio.h"
// #include "eeprom/eeprom.h" (needs some reworks to not have name conflicts)
// #include "usart/usart.h" (completely nonfunctional)
#endif

#endif /* FRAMEWORK_H_ */