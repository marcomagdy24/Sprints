/*
 * LED.h
 *
 * Created: 8/22/2021 3:50:15 PM
 *  Author: Marco
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../UTILS/utils.h"
#include "../../UTILS/types.h"
#include "../../MCAL/DIO/dio.h"

typedef struct 
{
	PORTS port;
	EN_pins pin;
}LED;

E_STATUS LED_Create(LED* led, PORTS port, EN_pins pin);
E_STATUS LED_LightON(LED* led);
E_STATUS LED_LightOFF(LED* led);


#endif /* LED_H_ */