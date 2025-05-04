/*
 * eeprom.h
 *
 * Created: 04/05/2025 14:06:17
 *  Author: Mnem
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_
namespace eeprom{
	namespace normal{
		#include "normal.h"
	}
	namespace atomic{
		#include "atomic.h"
	}
	namespace helper{
		#include "helper.h"	
	}
}
#endif /* EEPROM_H_ */