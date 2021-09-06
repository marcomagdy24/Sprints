/*
* DC_Motor.c
*
* Created: 28-Jul-21 11:21:38 PM
*  Author: Ayman
*/

#include "DC_Motor.h"
Motor_ERROR_state_t DC_MotorInit(uint8_t Motor)
{
	if(!((Motor>=Motor_RIGHT)&&(Motor<=Motor_LEFT)))
	{
		return E_NOK;
	}
	else
	{
		switch (Motor)
		{
			case Motor_RIGHT:
			configs.port = Motor_RIGHT_FORWARD_PORT;
			configs.pin = Motor_RIGHT_FORWARD_PIN;
			configs.dir = OUTPUT;
			DIO_Init(&configs);
			configs.port = Motor_RIGHT_BACKWARD_PORT;
			configs.pin = Motor_RIGHT_BACKWARD_PIN;
			configs.dir = OUTPUT;
			DIO_Init(&configs);
			break;
			case Motor_LEFT:
			configs.port = Motor_LEFT_FORWARD_PORT;
			configs.pin = Motor_LEFT_FORWARD_PIN;
			configs.dir = OUTPUT;
			DIO_Init(&configs);
			configs.port = Motor_LEFT_BACKWARD_PORT;
			configs.pin = Motor_LEFT_BACKWARD_PIN;
			configs.dir = OUTPUT;
			DIO_Init(&configs);
			break;
		}
	}
	
	return E_OK;
}
Motor_ERROR_state_t DC_MotorStart(uint8_t Motor,uint8_t Motor_speed,uint8_t Motor_Direction)
{
	
	if(!(((Motor>=Motor_RIGHT)&&(Motor<=Motor_LEFT))&&((Motor_speed>=Motor_MIN_SPEED)&&(Motor_speed<=Motor_MAX_SPEED))
	&&((Motor_Direction>=Motor_FORWARD)&&(Motor_Direction<=Motor_BACKWARD))))
	{
		return E_NOK;
	}
	else
	{
		switch (Motor)
		{
			case Motor_RIGHT:
			switch (Motor_Direction)
			{
				case Motor_FORWARD:
				DIO_WritePIN(Motor_RIGHT_BACKWARD_PORT, Motor_RIGHT_BACKWARD_PIN, LOW);
				DIO_WritePIN(Motor_RIGHT_FORWARD_PORT, Motor_RIGHT_FORWARD_PIN, HIGH);
				break;
				case Motor_BACKWARD:
				DIO_WritePIN(Motor_RIGHT_FORWARD_PORT, Motor_RIGHT_FORWARD_PIN, LOW);
				DIO_WritePIN(Motor_RIGHT_BACKWARD_PORT, Motor_RIGHT_BACKWARD_PIN, HIGH);
				break;
			}
			PWM_START(PWM_TIMER0, Motor_speed);
			//ENABLE Motor RIGHT PWM REQUIRED SPEED
			break;
			case Motor_LEFT:
			switch (Motor_Direction)
			{
				case Motor_FORWARD:
				DIO_WritePIN(Motor_LEFT_BACKWARD_PORT, Motor_LEFT_BACKWARD_PIN, LOW);
				DIO_WritePIN(Motor_LEFT_FORWARD_PORT, Motor_LEFT_FORWARD_PIN, HIGH);
				break;
				case Motor_BACKWARD:
				DIO_WritePIN(Motor_LEFT_FORWARD_PORT, Motor_LEFT_FORWARD_PIN, LOW);
				DIO_WritePIN(Motor_LEFT_BACKWARD_PORT, Motor_LEFT_BACKWARD_PIN, HIGH);
				break;
			}
			//PWM_START(PWM_TIMER0, Motor_speed);
			//ENABLE Motor LEFT PWM REQUIRED SPEED
			break;
		}
	}
	return E_OK;
}
Motor_ERROR_state_t DC_MotorStop(uint8_t Motor)
{
	
	if(!((Motor>=Motor_RIGHT)&&(Motor<=Motor_LEFT)))
	{
		return E_NOK;
	}
	else
	{
		switch (Motor)
		{
			case Motor_RIGHT:
			DIO_WritePIN(Motor_RIGHT_FORWARD_PORT, Motor_RIGHT_FORWARD_PIN, LOW);
			DIO_WritePIN(Motor_RIGHT_BACKWARD_PORT, Motor_RIGHT_BACKWARD_PIN, LOW);
			break;
			case Motor_LEFT:
			DIO_WritePIN(Motor_LEFT_FORWARD_PORT, Motor_LEFT_FORWARD_PIN, LOW);
			DIO_WritePIN(Motor_LEFT_BACKWARD_PORT, Motor_LEFT_BACKWARD_PIN, LOW);
			break;
		}
	}
	return E_OK;
}