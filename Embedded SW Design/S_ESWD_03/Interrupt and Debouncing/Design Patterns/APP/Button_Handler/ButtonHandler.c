/*
* ButtonHandler.c
*
* Created: 8/22/2021 3:00:17 PM
*  Author: Marco
*/

#include "ButtonHandler.h"

#define DEBOUNCE_TIME (3750)

volatile uint32_t Timer2_counter = 0;
ButtonVectorPtr oldVectors[10];
static LED itsLED1;
static BUTTON itsButton1;
uint8_t u8_ButtonLedFlag;
uint8_t u8_ButtonNewState;
uint8_t u8_ButtonOldState;
uint8_t u8_NotMatch;


void ButtonHandler_EventReceive()
{	
	Button_GetStatus(&itsButton1, &u8_ButtonNewState);
	if (u8_ButtonNewState != u8_ButtonOldState)
	{
		u8_NotMatch = TRUE;
	}
	if (u8_NotMatch)
	{
		Timer_SetCallBack(ISRAddress[2]);
		if (SUCCESS == TIMER_NonBlockingDelay(TIMER_2, DEBOUNCE_TIME, 0))
		{
			if (u8_ButtonNewState != u8_ButtonOldState)
			{
				if (u8_ButtonNewState)
				{
					Button_SetCallBack (ISRAddress[0]);
					if (!u8_ButtonLedFlag)
					{
						Button_SetCallBack (ISRAddress[1]);
						u8_ButtonLedFlag++;
					}
					else if (u8_ButtonLedFlag)
					{
						Button_SetCallBack (ISRAddress[0]);
						u8_ButtonLedFlag = ZERO;
					}
				}
				u8_ButtonOldState = u8_ButtonNewState;
			}
			u8_NotMatch = FALSE;
		}
	}
}

void handleButtonPushInterrupt(void)
{
	LED_LightON(&itsLED1);
}

void handleButtonReleaseInterrupt(void)
{
	LED_LightOFF(&itsLED1);
}

void handleButtonDebouncing(void)
{
	Timer_tSetTMRValue(TIMER_2,255);
	Timer2_counter++;
}

LED ButtonHandler_getItsLED(void)
{
	return itsLED1;
}

void ButtonHandler_setItsLED(LED p_LED)
{
	itsLED1 = p_LED;
}

BUTTON ButtonHandler_getItsButton(void)
{
	return itsButton1;
}

void ButtonHandler_setItsButton(BUTTON p_button)
{
	itsButton1 = p_button;
}

void ButtonHandler_Install(void)
{
	oldVectors[0] = ISRAddress[0];
	oldVectors[1] = ISRAddress[1];
	oldVectors[2] = ISRAddress[2];
	ISRAddress[0] = handleButtonPushInterrupt;
	ISRAddress[1] = handleButtonReleaseInterrupt;
	ISRAddress[2] = handleButtonDebouncing;
}

void ButtonHandler_DeINIT(void)
{
	ISRAddress[0] = oldVectors[0];
	ISRAddress[1] = oldVectors[1];
	ISRAddress[2] = oldVectors[2];
}