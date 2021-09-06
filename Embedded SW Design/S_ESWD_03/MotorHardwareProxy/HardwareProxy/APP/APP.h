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
#include "../MCAL/PWM/PWM.h"
#include "../ECUAL/Motor/DC_Motor.h"
#include "../MCAL/DIO/dio.h"


uint8_t APP_INIT();
uint8_t APP_UPDATE();

#endif /* PWM_H_ */