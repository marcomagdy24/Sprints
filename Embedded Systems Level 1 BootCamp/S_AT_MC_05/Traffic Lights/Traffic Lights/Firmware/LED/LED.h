/*
 * LED.h
 *
 * Created: 7/14/2021 8:52:23 PM
 *  Author: Marco
 */ 


#ifndef LED_H_
#define LED_H_

/******************************************************************************
*                              Includes													*
*******************************************************************************/
#include "../../MCAL/DIO/dio.h"
#include "ledRetval.h"

LED_STATUS_t LED_Init(uint8_t LED_ch);
LED_STATUS_t LED_Off(uint8_t LED_ch);
LED_STATUS_t LED_On(uint8_t LED_ch);
LED_STATUS_t LED_toggle(uint8_t LED_ch);



#endif /* LED_H_ */