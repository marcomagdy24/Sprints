/*
* PWM.c
*
* Created: 8/9/2021 8:07:46 PM
*  Author: Marco
*/

/******************************************************************************
*                              INCLUDES										  *
*******************************************************************************/
#include "CarControl.h"


/******************************************************************************
*                         APIS IMPLEMENTATION								  *
*******************************************************************************/
uint8_t SYS_Init()
{
	GIE_voidEnable();
	Sensing_Init();
	Steering_InitFunction();
	ST_Task_Config_t sensingTask = {ONE, ZERO, ZERO, THREE, Sensing_MainFunction};
	ST_Task_Config_t crashingTask = {ZERO, ONE, ONE, THREE, Crashing_MainFunction};
	ST_Task_Config_t steeringTask = {TWO, TWO, TWO, THREE, Steering_MainFunction};
	TMU_CreateTask(&sensingTask);
	TMU_CreateTask(&crashingTask);
	TMU_CreateTask(&steeringTask);
	TMU_Init();
	/* Replace with your application code */
	return E_OK;
}

uint8_t SYS_Update()
{
	TMU_Run();
	return E_OK;
}