/*
* PWM.c
*
* Created: 8/9/2021 8:07:46 PM
*  Author: Marco
*/
#include "CarControl.h"

float32_t distance;

uint8_t APP_INIT()
{
	LCD_INIT();
	_delay_us(900);
	ULTRASONIC_INIT();
	DC_MotorInit(MOTOR_LEFT);
	DC_MotorInit(MOTOR_RIGHT);
	LCD_WRITE_STRING(STRING_DISTANCE);
	LCD_GOTO_XY(FIRST_ROW, 14);
	LCD_WRITE_STRING(STRING_CM);
	/* Replace with your application code */
	return E_OK;
}

uint8_t APP_UPDATE()
{
	ULTRASONIC_GetDist(&distance);
	LCD_GOTO_XY(FIRST_ROW, 10);
	LCD_WRITE_STRING((ptr_uint8_t)"   ");
	LCD_GOTO_XY(FIRST_ROW, 10);
	LCD_WRITE_NUMBER(distance);
	if(distance > 52)
	{
		DC_MotorStart(MOTOR_RIGHT,70,MOTOR_FORWARD);
		DC_MotorStart(MOTOR_LEFT,70,MOTOR_FORWARD);
		return E_OK;
	}
	else if((distance >= 48) && (distance <= 52))
	{
		DC_MotorStart(MOTOR_RIGHT,95,MOTOR_BACKWARD);
		DC_MotorStart(MOTOR_LEFT,95,MOTOR_FORWARD);
		return E_OK;
	}
	else if ((distance < 48) &&(distance >= 0))
	{
		DC_MotorStart(MOTOR_RIGHT,70,MOTOR_BACKWARD);
		DC_MotorStart(MOTOR_LEFT,70,MOTOR_BACKWARD);
		return E_OK;
	}
	else
	{
		return E_NOK;
	}
	return E_OK;
}