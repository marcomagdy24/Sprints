/*
 * Button.h
 *
 * Created: 8/22/2021 6:36:00 PM
 *  Author: Marco
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../UTILS/utils.h"
#include "../../UTILS/types.h"
#include "../../MCAL/DIO/dio.h"

typedef struct
{
	PORTS port;
	EN_pins pin;
}BUTTON;

E_STATUS Button_Create(BUTTON* button, PORTS port, EN_pins pin);
E_STATUS Button_GetStatus(BUTTON* button, ptr_uint8_t pu8_ButtonStatus);


#endif /* BUTTON_H_ */