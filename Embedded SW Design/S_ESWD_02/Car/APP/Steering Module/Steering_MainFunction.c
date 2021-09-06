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
uint8_t gu8_MotorInit = E_NOK;
uint8_t gu8i_MotorSpeed;
uint8_t gu8i_MotorDirection;


/******************************************************************************
*                         LOCAL FUNCTIONS IMPLEMENTATION					  *
*******************************************************************************/
E_STATUS Steering_InitFunction()
{
	DC_MotorInit(Motor_LEFT);
	DC_MotorInit(Motor_RIGHT);
	return E_OK;
}

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
void Steering_MainFunction(void)
{
	if (E_NOK == gu8_MotorInit)
	{
		Steering_InitFunction();
		gu8_MotorInit = E_OK;
	}
	else
	{
		if (Steering_InitData())
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
}