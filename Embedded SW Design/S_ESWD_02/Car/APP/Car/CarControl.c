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
uint8_t APP_INIT()
{
	GIE_voidEnable();
	
	/* Replace with your application code */
	return E_OK;
}

uint8_t APP_UPDATE()
{
	Displaying_MainFunction();
	Sensing_MainFunction();
	Crashing_MainFunction();
	Steering_MainFunction();
	return E_OK;

}