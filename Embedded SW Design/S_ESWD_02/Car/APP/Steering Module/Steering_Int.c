/*
* MotorINT.c
*
* Created: 16-Aug-21 6:02:30 PM
*  Author: Ayman
*/

/******************************************************************************
*                              INCLUDES										  *
*******************************************************************************/
#include "Steering_Int.h"

/******************************************************************************
*                              LOCAL MACROS									  *
*******************************************************************************/
/* ---MotorS CONFIGURATIONS --------------------*/
#define Motor_RIGHT        (uint8_t)(0)
#define Motor_LEFT         (uint8_t)(1)
#define Motor_DIRECTION    (uint8_t)(2)

/* ---DIRECTION CONFIGURATIONS --------------------*/
#define Motor_FORWARD     (uint8_t)(0)
#define Motor_BACKWARD    (uint8_t)(1)

/******************************************************************************
*						GLOBAL EXTERN VARIABLES								  *
*******************************************************************************/
volatile uint8_t gu8i_RetValMotorDirection;

/******************************************************************************
*                         APIS IMPLEMENTATION								  *
*******************************************************************************/
E_STATUS Steering_SetDirection(ptr_uint8_t MotorDirection)
{
	uint8_t state;
	CrashingModule_GetDirection(&state);
	if ((state >= STATE_MOTOR_STOP) && (state <= STATE_MOTOR_LEFT) )
	{
		*MotorDirection = state;
		gu8i_RetValMotorDirection = E_OK;
	}
	else
	{
		gu8i_RetValMotorDirection = E_NOK;
	}
	
	return gu8i_RetValMotorDirection;
}

E_STATUS Steering_SetSpeed(ptr_uint8_t MotorSpeed)
{
	uint8_t state;
	CrashingModule_GetSpeed(&state);
	if (!((state >= MOTOR_MIN_SPEED)  && (state <= MOTOR_MAX_SPEED)))
	{
		gu8i_RetValMotorDirection = E_NOK;
	}
	else
	{
		*MotorSpeed = state;
		gu8i_RetValMotorDirection = E_OK;
	}
	
	return gu8i_RetValMotorDirection;
}

