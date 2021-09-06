/*
* Sensing_MainFunction.c
*
* Created: 16-Aug-21 7:20:39 PM
*  Author: Ayman
*/

/******************************************************************************
*                              INCLUDES										  *
*******************************************************************************/
#include "Sensing_MainFunction.h"

/******************************************************************************
*						GLOBAL EXTERN VARIABLES								  *
*******************************************************************************/
float32_t gf32o_SensorDistance;
uint8_t u8_SensorInit = E_NOK;
/******************************************************************************
*                         LOCAL FUNCTIONS IMPLEMENTATION					  *
*******************************************************************************/
E_STATUS Sensing_Init(void)
{
	uint8_t count = ZERO;
	while (count != 3)
	{
		if (E_NOK == ULTRASONIC_INIT())
		{
			count++;
		}
		else
		{
			u8_SensorInit = E_OK;
			break;
		}
	}
	return u8_SensorInit;
}

/******************************************************************************
*                         APIS IMPLEMENTATION								  *
*******************************************************************************/
void Sensing_MainFunction(void)
{
	if (E_OK == u8_SensorInit)
	{
		ULTRASONIC_GetDist(&gf32o_SensorDistance);
	}
	else
	{
		gf32o_SensorDistance = ONE;
	}
}


