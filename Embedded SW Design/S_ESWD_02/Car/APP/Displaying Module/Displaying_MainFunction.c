/*
* Displaying_MainFunction.c
*
* Created: 17-Aug-21 12:04:16 AM
*  Author: Ayman
*/


/******************************************************************************
*                              INCLUDES										  *
*******************************************************************************/
#include "Displaying_MainFunction.h"

/******************************************************************************
*                              LOCAL MACROS									  *
*******************************************************************************/
#define STRING_DISTANCE	(uint8_t *) ("Distance: ")
#define STRING_CM		(uint8_t *) ("cm")

/******************************************************************************
*						GLOBAL EXTERN VARIABLES								  *
*******************************************************************************/
float32_t gf32i_SensorDistance;
uint8_t u8_isInitStarted = FALSE;
uint8_t u8_isInitFinished = E_NOK;


/******************************************************************************
*                         APIS IMPLEMENTATION								  *
*******************************************************************************/
void Displaying_MainFunction()
{
	if (u8_isInitStarted && u8_isInitFinished)
	{
		SensingGetDistance(&gf32i_SensorDistance);
		LCD_GOTO_XY(FIRST_ROW, 10);
		LCD_WRITE_STRING((ptr_uint8_t)"   ");
		LCD_GOTO_XY(FIRST_ROW, 10);
		LCD_WRITE_NUMBER(gf32i_SensorDistance);
	}
	else if (!(u8_isInitStarted) && !(u8_isInitFinished))
	{
		LCD_INIT();
		u8_isInitStarted = TRUE;
	}
	else if ((u8_isInitStarted) && !(u8_isInitFinished))
	{
		while (OPERATION_SUCCESS != LCD_INIT());
		u8_isInitFinished = E_OK;
		LCD_WRITE_STRING(STRING_DISTANCE);
		LCD_GOTO_XY(FIRST_ROW, 14);
		LCD_WRITE_STRING(STRING_CM);
	}

}