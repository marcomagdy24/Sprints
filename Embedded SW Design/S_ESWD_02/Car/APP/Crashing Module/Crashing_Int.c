/*
 * LCD_Int.c
 *
 * Created: 17-Aug-21 12:03:20 AM
 *  Author: Ayman
 */ 

/******************************************************************************
*                              INCLUDES										  *
*******************************************************************************/
#include "Crashing_Int.h"

/******************************************************************************
*						GLOBAL EXTERN VARIABLES								  *
*******************************************************************************/
volatile uint8_t gu8o_MotorSpeed;
volatile uint8_t gu8o_MotorDirection;
volatile uint8_t gu8_RetValMotorDirection;


/******************************************************************************
*                         APIS IMPLEMENTATION								  *
*******************************************************************************/
E_STATUS CrashingModule_GetDirection(ptr_uint8_t MotorDirection)
{
	if (NULL_PTR == MotorDirection)
	{
		gu8_RetValMotorDirection = E_NOK;
	}
	else if ((*MotorDirection >= STATE_MOTOR_STOP) && (*MotorDirection <= STATE_MOTOR_LEFT) )
	{
		*MotorDirection = gu8o_MotorDirection;
		gu8_RetValMotorDirection = E_OK;
	}
	else
	{
		gu8_RetValMotorDirection = E_NOK;
	}
	return gu8_RetValMotorDirection;
}



E_STATUS CrashingModule_GetSpeed(ptr_uint8_t Speed)
{
	if (NULL_PTR == Speed)
	{
		gu8_RetValMotorDirection = E_NOK;
	}
	else if ((*Speed >= MOTOR_MIN_SPEED) && (*Speed <= MOTOR_MAX_SPEED) )
	{
		*Speed = gu8o_MotorSpeed;
		gu8_RetValMotorDirection = E_OK;
	}
	else
	{
		gu8_RetValMotorDirection = E_NOK;
	}
	
	return gu8_RetValMotorDirection;
}


