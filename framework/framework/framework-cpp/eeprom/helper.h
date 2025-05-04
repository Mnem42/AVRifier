/*
 * helper.h
 *
 * Created: 04/05/2025 19:28:03
 *  Author: Ishaan
 */ 


#ifndef HELPER_H_
#define HELPER_H_

#ifdef __FRM_IS_CPP
template<uint16_t n> IO load_bytes_safe(uint16_t start_addr, uint8_t buf[n]){
	for(uint16_t i = 0; i < n; i++){
		buf[i] = read_byte(i+start_addr);
	}
}
#endif

template<uint16_t n> IO load_bytes(uint16_t start_addr, uint8_t buf[n]){
	for(uint16_t i = 0; i < n; i++){
		buf[i] = read_byte(i+start_addr);
	}
}

#endif /* HELPER_H_ */