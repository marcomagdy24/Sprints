/*
* DIO.c
*
* Created: 7/8/2021 6:09:26 PM
* Author : Marco
*/

/*---------------------- INCLUDES ----------------------*/
#define F_CPU 10000000ul
#include "DIO Driver/dio.h"


int main(void)
{
	/* Replace with your application code */
	configs.port=DIO_PORTA;
	configs.pin=PIN_0;
	configs.dir=OUTPUT;
	DIO_Init(&configs);
	//Make the output pin initially high
	//configuring the input pin
	configs.port=DIO_PORTC;
	configs.pin=PIN_0;
	configs.dir=INPUT;
	DIO_Init(&configs);
	//a variable to return the data we get by the DIO
	uint8_t au_read_pin;
	
	while (1)
	{
		//read the DIO
		DIO_Read_PIN(DIO_PORTC,PIN_0,&au_read_pin);
		if(au_read_pin==HIGH)
		{
			DIO_Write_PIN(DIO_PORTA,PIN_0,HIGH);
		}
		else{
			DIO_Write_PIN(DIO_PORTA,PIN_0,LOW);
		}
	}
	return 0;
}

