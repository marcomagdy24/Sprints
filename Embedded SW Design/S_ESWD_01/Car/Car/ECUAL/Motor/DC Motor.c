/*
* DC_Motor.c
*
* Created: 28-Jul-21 11:21:38 PM
*  Author: ayman
*/

#include "DC_Motor.h"
Motor_ERROR_state_t DC_MotorInit(uint8_t Motor)
{
	if(!((Motor>=MOTOR_RIGHT)&&(Motor<=MOTOR_LEFT)))
	{
		return E_NOK;
	}
	else
	{
		switch (Motor)
		{
			case MOTOR_RIGHT:
			configs.port = MOTOR_RIGHT_FORWARD_PORT;
			configs.pin = MOTOR_RIGHT_FORWARD_PIN;
			configs.dir = OUTPUT;
			DIO_Init(&configs);
			configs.port = MOTOR_RIGHT_BACKWARD_PORT;
			configs.pin = MOTOR_RIGHT_BACKWARD_PIN;
			configs.dir = OUTPUT;
			DIO_Init(&configs);
			break;
			case MOTOR_LEFT:
			configs.port = MOTOR_LEFT_FORWARD_PORT;
			configs.pin = MOTOR_LEFT_FORWARD_PIN;
			configs.dir = OUTPUT;
			DIO_Init(&configs);
			configs.port = MOTOR_LEFT_BACKWARD_PORT;
			configs.pin = MOTOR_LEFT_BACKWARD_PIN;
			configs.dir = OUTPUT;
			DIO_Init(&configs);
			break;
		}
	}
	
	return E_OK;
}
Motor_ERROR_state_t DC_MotorStart(uint8_t Motor,uint8_t Motor_speed,uint8_t Motor_Direction)
{
	
	if(!(((Motor>=MOTOR_RIGHT)&&(Motor<=MOTOR_LEFT))&&((Motor_speed>=MOTOR_MIN_SPEED)&&(Motor_speed<=MOTOR_MAX_SPEED))
	&&((Motor_Direction>=MOTOR_FORWARD)&&(Motor_Direction<=MOTOR_BACKWARD))))
	{
		return E_NOK;
	}
	else
	{
		switch (Motor)
		{
			case MOTOR_RIGHT:
			switch (Motor_Direction)
			{
				case MOTOR_FORWARD:
				DIO_WritePIN(MOTOR_RIGHT_BACKWARD_PORT, MOTOR_RIGHT_BACKWARD_PIN, LOW);
				DIO_WritePIN(MOTOR_RIGHT_FORWARD_PORT, MOTOR_RIGHT_FORWARD_PIN, HIGH);
				break;
				case MOTOR_BACKWARD:
				DIO_WritePIN(MOTOR_RIGHT_FORWARD_PORT, MOTOR_RIGHT_FORWARD_PIN, LOW);
				DIO_WritePIN(MOTOR_RIGHT_BACKWARD_PORT, MOTOR_RIGHT_BACKWARD_PIN, HIGH);
				break;
			}
			PWM_START(PWM_TIMER0, Motor_speed);
			//ENABLE MOTOR RIGHT PWM REQUIRED SPEED
			break;
			case MOTOR_LEFT:
			switch (Motor_Direction)
			{
				case MOTOR_FORWARD:
				DIO_WritePIN(MOTOR_LEFT_BACKWARD_PORT, MOTOR_LEFT_BACKWARD_PIN, LOW);
				DIO_WritePIN(MOTOR_LEFT_FORWARD_PORT, MOTOR_LEFT_FORWARD_PIN, HIGH);
				break;
				case MOTOR_BACKWARD:
				DIO_WritePIN(MOTOR_LEFT_FORWARD_PORT, MOTOR_LEFT_FORWARD_PIN, LOW);
				DIO_WritePIN(MOTOR_LEFT_BACKWARD_PORT, MOTOR_LEFT_BACKWARD_PIN, HIGH);
				break;
			}
			//PWM_START(PWM_TIMER0, Motor_speed);
			//ENABLE MOTOR LEFT PWM REQUIRED SPEED
			break;
		}
	}
	return E_OK;
}
Motor_ERROR_state_t DC_MotorStop(uint8_t Motor)
{
	
	if(!((Motor>=MOTOR_RIGHT)&&(Motor<=MOTOR_LEFT)))
	{
		return E_NOK;
	}
	else
	{
		switch (Motor)
		{
			case MOTOR_RIGHT:
			DIO_WritePIN(MOTOR_RIGHT_FORWARD_PORT, MOTOR_RIGHT_FORWARD_PIN, LOW);
			DIO_WritePIN(MOTOR_RIGHT_BACKWARD_PORT, MOTOR_RIGHT_BACKWARD_PIN, LOW);
			break;
			case MOTOR_LEFT:
			DIO_WritePIN(MOTOR_LEFT_FORWARD_PORT, MOTOR_LEFT_FORWARD_PIN, LOW);
			DIO_WritePIN(MOTOR_LEFT_BACKWARD_PORT, MOTOR_LEFT_BACKWARD_PIN, LOW);
			break;
		}
	}
	return E_OK;
}