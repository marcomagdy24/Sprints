/*
 * BCM_MainFunction.h
 *
 * Created: 30-Aug-21 9:48:05 PM
 *  Author: ayman
 */ 
#define TEST 0


#define MAX_SIZE	(uint16_t)(100)
#define MAX_MODES	(uint16_t)(3)

#define BCM_ID		(uint8_t)(0xAE)
#define MCU_ID		(uint8_t)(1)

#ifndef BCM_MAINFUNCTION_H_
#define BCM_MAINFUNCTION_H_
#include "BCM_Interference.h"
E_STATUS BCM_TxMainFunction();
E_STATUS BCM_RxMainFunction();



#endif /* BCM_MAINFUNCTION_H_ */