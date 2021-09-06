/*
 * DC_Motor.h
 *
 * Created: 28-Jul-21 11:21:10 PM
 *  Author: ayman
 */ 


#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_
/* ---INCLUDES --------------------*/
#include "../../Utils/utils.h"
#include "../../MCAL/DIO/dio.h"
#include "../../MCAL/PWM/PWM.h"
#include "DC_MotorConfig.h"

/*-----------------------------------------*/

typedef struct
{
	uint8_t Motor_Forwardport;
	uint8_t Motor_ForwardPin;
	uint8_t Motor_Backwardport;
	uint8_t Motor_BackwardPin;
	uint8_t Motor_Direction;
	uint8_t Motor_Speed;
	
}STR_Motor_t;
/* ---FUNCTION DECLARATIONS --------------------*/
Motor_ERROR_state_t DC_MotorInit(STR_Motor_t* Motor);
Motor_ERROR_state_t DC_MotorStart(STR_Motor_t* Motor);
Motor_ERROR_state_t DC_MotorStop(STR_Motor_t* Motor);

	

#endif /* DC_MOTOR_H_ */