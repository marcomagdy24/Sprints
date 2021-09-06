/*
* DC_Motor.c
*
* Created: 28-Jul-21 11:21:38 PM
*  Author: Ayman
*/

#include "DC_Motor.h"
Motor_ERROR_state_t DC_MotorInit(STR_Motor_t* Motor)
{
	if(NULL_PTR==Motor)
	{
		return E_NOK;
	}
	else
	{

			configs.port = Motor->Motor_Forwardport;
			configs.pin = Motor->Motor_ForwardPin;
			configs.dir = OUTPUT;
			DIO_Init(&configs);
			configs.port = Motor->Motor_Backwardport;
			configs.pin = Motor->Motor_BackwardPin;
			configs.dir = OUTPUT;
			DIO_Init(&configs);

		}
	
	return E_OK;
}
Motor_ERROR_state_t DC_MotorStart(STR_Motor_t* Motor)
{
	
	if(NULL_PTR==Motor)
	{
		return E_NOK;
	}
	else
	{
		switch ((Motor->Motor_Direction))
		{
			case MOTOR_FORWARD:
			DIO_WritePIN(Motor->Motor_Backwardport, Motor->Motor_BackwardPin, LOW);
			DIO_WritePIN(Motor->Motor_Forwardport, Motor->Motor_ForwardPin, HIGH);
				
			break;
			case MOTOR_BACKWARD:
			DIO_WritePIN(Motor->Motor_Forwardport, Motor->Motor_ForwardPin, LOW);
			DIO_WritePIN(Motor->Motor_Backwardport, Motor->Motor_BackwardPin, HIGH);
			break;
		}
		PWM_START(PWM_TIMER0, Motor->Motor_Speed);
		//ENABLE MOTOR RIGHT PWM REQUIRED SPEED
	}
	return E_OK;
}
Motor_ERROR_state_t DC_MotorStop(STR_Motor_t* Motor)
{
	
	if(NULL_PTR==Motor)
	{
		return E_NOK;
	}
	else
	{

		DIO_WritePIN(Motor->Motor_Forwardport, Motor->Motor_ForwardPin, LOW);
		DIO_WritePIN(Motor->Motor_Backwardport, Motor->Motor_BackwardPin, LOW);
		Motor->Motor_Speed=0;

	}
	return E_OK;
}