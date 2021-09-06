/*
* LED.c
*
* Created: 8/22/2021 3:50:04 PM
*  Author: Marco
*/

#include "LED.h"

E_STATUS LED_INIT(LED* led);


E_STATUS LED_Create(LED* led, PORTS port, EN_pins pin)
{
	led->port = port;
	led->pin = pin;
	if(NULL_PTR != led)
	{
		LED_INIT(led);
	}
	return E_OK;
}

E_STATUS LED_INIT(LED* led)
{
	E_STATUS retval = E_NOK;
	ST_DIO_config led_dio;
	led_dio.port = led->port;
	led_dio.pin = led->pin;
	led_dio.dir = OUTPUT;
	DIO_Init(&led_dio);
	return retval;
}

E_STATUS LED_LightON(LED* led)
{
	DIO_WritePIN(led->port, led->pin, HIGH);
	return E_OK;
}

E_STATUS LED_LightOFF(LED* led)
{
	DIO_WritePIN(led->port, led->pin, LOW);
	return E_OK;
}
