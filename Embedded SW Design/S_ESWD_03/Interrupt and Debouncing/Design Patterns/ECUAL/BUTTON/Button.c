/*
* Button.c
*
* Created: 8/22/2021 6:36:19 PM
*  Author: Marco
*/
#include "Button.h"

E_STATUS Button_INIT(BUTTON* button);
uint8_t status;

E_STATUS Button_Create(BUTTON* button, PORTS port, EN_pins pin)
{
	button->port = port;
	button->pin = pin;
	if(NULL_PTR != button)
	{
		Button_INIT(button);
	}
	return E_OK;
}

E_STATUS Button_INIT(BUTTON* button)
{
	E_STATUS retval = E_NOK;
	ST_DIO_config button_dio;
	button_dio.port = button->port;
	button_dio.pin = button->pin;
	button_dio.dir = INPUT;
	DIO_Init(&button_dio);
	return retval;
}

E_STATUS Button_GetStatus(BUTTON* button, ptr_uint8_t pu8_ButtonStatus)
{
	E_STATUS retval = E_NOK;
	DIO_ReadPIN(button->port, button->pin, pu8_ButtonStatus);
	status = *pu8_ButtonStatus;
	if ((*pu8_ButtonStatus == HIGH) || (*pu8_ButtonStatus == LOW))
	{
		retval = E_OK;
	} 
	return retval;
}



