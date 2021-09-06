/*
 * DC_Motor.h
 *
 * Created: 28-Jul-21 11:21:10 PM
 *  Author: Ayman
 */ 


#ifndef DC_Motor_H_
#define DC_Motor_H_
/* ---INCLUDES --------------------*/
#include "../../Utils/utils.h"
#include "../../MCAL/DIO/dio.h"
#include "../../MCAL/PWM/PWM.h"
#include "DC_MotorConfig.h"
/* ---FUNCTION DECLARATIONS --------------------*/
Motor_ERROR_state_t DC_MotorInit(uint8_t Motor);
Motor_ERROR_state_t DC_MotorStart(uint8_t Motor,uint8_t Motor_speed,uint8_t Motor_direction);
Motor_ERROR_state_t DC_MotorStop(uint8_t Motor);

#endif /* DC_Motor_H_ */
