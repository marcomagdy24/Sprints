/*
 * PWM.h
 *
 * Created: 8/9/2021 8:07:33 PM
 *  Author: Marco
 */ 


#ifndef CAR_H_
#define CAR_H_

/******************************************************************************
*                              INCLUDES										  *
*******************************************************************************/
#include "../../MCAL/PWM/PWM.h"
#include "../../ECUAL/LCD/lcd.h"
#include "../../ECUAL/Motor/DC_Motor.h"
#include "../../ECUAL/ULTRASONIC/Ultrasonic.h"
#include "../../MCAL/DIO/dio.h"

#define STRING_DISTANCE	(uint8_t *) ("Distance: ")
#define STRING_CM		(uint8_t *) ("cm")

uint8_t APP_INIT();
uint8_t APP_UPDATE();

#endif /* PWM_H_ */