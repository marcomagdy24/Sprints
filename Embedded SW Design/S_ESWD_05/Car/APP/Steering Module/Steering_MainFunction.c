/*
* Motor_MainFunction.c
*
* Created: 16-Aug-21 7:09:15 PM
*  Author: Ayman
*/

/******************************************************************************
*                              INCLUDES										  *
*******************************************************************************/
#include "Steering_MainFunction.h"

/******************************************************************************
*						GLOBAL EXTERN VARIABLES								  *
*******************************************************************************/
E_STATUS gu8_MotorInit = E_NOK;
uint8_t gu8i_MotorSpeed;
uint8_t gu8i_MotorDirection;
E_STATUS gu8_RetVal = E_NOK;

/******************************************************************************
*                         LOCAL FUNCTIONS IMPLEMENTATION					  *
*******************************************************************************/


E_STATUS Steering_InitData()
{
	uint8_t u8_retval = E_NOK;
	if ((E_OK == Steering_SetDirection(&gu8i_MotorDirection)) && (E_OK == Steering_SetSpeed(&gu8i_MotorSpeed)))
	{
		u8_retval = E_OK;
	}
	else
	{
		u8_retval = E_NOK;
	}
	return u8_retval;
}

/******************************************************************************
*                         APIS IMPLEMENTATION								  *
*******************************************************************************/
E_STATUS Steering_InitFunction()
{
	if (E_OK == DC_MotorInit(Motor_LEFT))
	{
		gu8_RetVal = E_OK;
	}
	else
	{
		gu8_RetVal = E_NOK;
	}
	if (E_OK == DC_MotorInit(Motor_RIGHT))
	{
		gu8_RetVal = E_OK;
	}
	else
	{
		gu8_RetVal = E_NOK;
	}
	
	return gu8_RetVal;
}

void Steering_MainFunction(void)
{
	if (E_OK == gu8_RetVal)
	{
		if (E_OK == Steering_InitData())
		{
			switch (gu8i_MotorDirection)
			{
				case (STATE_MOTOR_FORWARD):
				{
					DC_MotorStart(Motor_RIGHT, gu8i_MotorSpeed, Motor_FORWARD);
					DC_MotorStart(Motor_LEFT, gu8i_MotorSpeed, Motor_FORWARD);
					break;
				}
				case (STATE_MOTOR_BACKWARD):
				{
					DC_MotorStart(Motor_RIGHT, gu8i_MotorSpeed, Motor_BACKWARD);
					DC_MotorStart(Motor_LEFT, gu8i_MotorSpeed, Motor_BACKWARD);
					break;
				}
				case (STATE_MOTOR_RIGHT):
				{
					DC_MotorStart(Motor_RIGHT, gu8i_MotorSpeed, Motor_BACKWARD);
					DC_MotorStart(Motor_LEFT, gu8i_MotorSpeed, Motor_FORWARD);
					break;
				}
				case (STATE_MOTOR_LEFT):
				{
					DC_MotorStart(Motor_RIGHT, gu8i_MotorSpeed, Motor_FORWARD);
					DC_MotorStart(Motor_LEFT, gu8i_MotorSpeed, Motor_BACKWARD);
					break;
				}
				case (STATE_MOTOR_STOP):
				{
					DC_MotorStop(Motor_RIGHT);
					DC_MotorStop(Motor_LEFT);
					break;
				}
				default:
				{
					break;
				}
			}
		}
	}
	else
	{
		
	}
}