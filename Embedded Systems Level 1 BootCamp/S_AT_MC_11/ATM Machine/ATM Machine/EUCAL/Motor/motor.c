/*
 * motor.c
 *
 * Created: 7/28/2021 12:07:13 PM
 *  Author: Marco
 */ 
/******************************************************************************
*                              Includes													*
*******************************************************************************/
#include "motor.h"

/******************************************************************************
*                         APIS IMPLEMENTATION											*
*******************************************************************************/
MOTOR_STATUS_t MOTOR_INIT(void)
{
	if ((MOTOR_PORT > PORT_D) || (MOTOR_PORT < PORT_A))
	{
		return MOTOR_INVALID_PORT;
	}
	else if ((MOTOR_PORT > PIN7) || (MOTOR_PORT < PIN0))
	{
		return MOTOR_INVALID_PORT;
	}
	DIO_SetPinDirection(MOTOR_PORT, MOTOR_PIN, PIN_OUTPUT);
	return MOTOR_SUCCESS;
}
MOTOR_STATUS_t MOTOR_START(void)
{
	DIO_WritePin(MOTOR_PORT, MOTOR_PIN, PIN_HIGH);
	return MOTOR_SUCCESS;
}
MOTOR_STATUS_t MOTOR_STOP(void)
{
	DIO_WritePin(MOTOR_PORT, MOTOR_PIN, PIN_LOW);
	return MOTOR_SUCCESS;
}
MOTOR_STATUS_t MOTOR_STATUS(uint8_t * status)
{
	DIO_ReadPin(MOTOR_PORT, MOTOR_PIN, status);
	return MOTOR_SUCCESS;
}