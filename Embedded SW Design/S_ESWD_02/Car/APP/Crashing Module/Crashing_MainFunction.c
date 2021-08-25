/*
* LCD_MainFunction.c
*
* Created: 17-Aug-21 12:04:16 AM
*  Author: Ayman
*/

/******************************************************************************
*                              INCLUDES										  *
*******************************************************************************/
#include "Crashing_MainFunction.h"

/******************************************************************************
*                              LOCAL MACROS									  *
*******************************************************************************/
#define MAX_DISTANCE	(uint8_t)(54)
#define RANGE_DISTANCE	(uint8_t)(47)
#define MIN_DISTANCE	(uint8_t)(2)
#define MAX_SPEED		(uint8_t)(95)
#define MIN_SPEED		(uint8_t)(70)

/******************************************************************************
*						GLOBAL EXTERN VARIABLES								  *
*******************************************************************************/
float32_t gf32i_SensorDistance;
extern volatile uint8_t gu8o_MotorSpeed;
extern volatile uint8_t gu8o_MotorDirection;

void Crashing_MainFunction()
{
	SensingGetDistance(&gf32i_SensorDistance);
	if(gf32i_SensorDistance > MAX_DISTANCE)
	{
		gu8o_MotorSpeed = MIN_SPEED;
		gu8o_MotorDirection = STATE_MOTOR_FORWARD;
	}
	else if((gf32i_SensorDistance >= RANGE_DISTANCE) && (gf32i_SensorDistance <= MAX_DISTANCE))
	{
		gu8o_MotorSpeed = MAX_SPEED;
		gu8o_MotorDirection = STATE_MOTOR_RIGHT;
	}
	else if ((gf32i_SensorDistance < RANGE_DISTANCE) &&(gf32i_SensorDistance >= MIN_DISTANCE))
	{
		gu8o_MotorSpeed = MIN_SPEED;
		gu8o_MotorDirection = STATE_MOTOR_FORWARD;
	}
	else
	{
		gu8o_MotorSpeed = ZERO;
		gu8o_MotorDirection = STATE_MOTOR_STOP;
	}
}