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
	E_STATUS retVal = E_NOK;
	while (count != 3)
	{
		if (E_NOK == ULTRASONIC_INIT())
		{
			count++;
		}
		else
		{
			retVal = E_OK;
			break;
		}
	}
	return retVal;
}

/******************************************************************************
*                         APIS IMPLEMENTATION								  *
*******************************************************************************/
void Sensing_MainFunction(void)
{
	if (E_NOK == u8_SensorInit) 
	{
		if (E_OK == Sensing_Init())
		{
			u8_SensorInit = E_OK;
		}
		else
		{
			u8_SensorInit = E_NOK;
			gf32o_SensorDistance = ONE;
		}
	}
	else
	{
		ULTRASONIC_GetDist(&gf32o_SensorDistance);
	}
}


