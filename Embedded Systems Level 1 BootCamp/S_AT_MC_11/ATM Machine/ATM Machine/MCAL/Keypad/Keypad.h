/*
 * Keypad.h
 *
 * Created: 7/26/2021 9:21:54 PM
 *  Author: Marco
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

/******************************************************************************
*                              Includes													*
*******************************************************************************/
#define F_CPU 1000000UL
#include <util/delay.h>
#include "../../Infrastructure/registers.h"
#include "../../Infrastructure/types.h"
/******************************************************************************
*                              CONSTANTS													*
*******************************************************************************/
#define KEYPAD_PORT				PORTA_DATA
#define DataDir_KEYPAD_PORT	PORTA_DIR
#define KEYPAD_PIN				PORTA_INPUT

#define C0 1
#define C1 2
#define C2 3
#define R0 4
#define R1 5
#define R2 6
#define R3 7	

void KEYPAD_INIT();
uint8_t KEYPAD_GETCHAR();


#endif /* KEYPAD_H_ */