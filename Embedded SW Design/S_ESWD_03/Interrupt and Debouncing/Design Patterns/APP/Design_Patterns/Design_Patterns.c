/*
* DESIGN_PATTERNS.c
*
* Created: 8/22/2021 7:32:04 PM
*  Author: Marco
*/

#include "Design_Patterns.h"

E_STATUS APP_INIT()
{
	ExInterrupt_INIT(interrupt2, falling_edge);
	LED itsLED;
	BUTTON itsButton;
	LED_Create(&itsLED, DIO_PORTB, PIN_6);
	Button_Create(&itsButton, DIO_PORTB, PIN_2);
	for (uint8_t j = 0;j < 9;j++) {
		ISRAddress[j] = NULL_PTR;
		oldVectors[j] = NULL_PTR;
	}
	ButtonHandler_setItsLED(itsLED);
	ButtonHandler_setItsButton(itsButton);
	ButtonHandler_Install();
	GIE_voidEnable();	Button_SetCallBack (ISRAddress[1]);	return E_OK;
}

E_STATUS APP_UPDATE()
{
	ButtonHandler_EventReceive();	
	return E_OK;
}