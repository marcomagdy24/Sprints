/*
* Traffic_Lights.c
*
* Created: 7/14/2021 7:47:54 PM
*  Author: Marco
*/
/******************************************************************************
*                              Includes													*
*******************************************************************************/
#include "Traffic Lights.h"

/******************************************************************************
*                         LOCAL FUNCTION IMPLEMENTATION								*
*******************************************************************************/
uint8_t string_compare(uint8_t str1[], uint8_t str2[])
{
	uint8_t ctr=0;

	while(str1[ctr]==str2[ctr])
	{
		if(str1[ctr]=='\0'||str2[ctr]=='\0')
		{
			break;
		}
		
		ctr++;
	}
	if(str1[ctr]=='\0' && str2[ctr]=='\0')
	{
		return 0;
	}
	
	else
	{
		return 1;
	}
	
}

/******************************************************************************
*                         APIS IMPLEMENTATION											*
*******************************************************************************/
void Traffic_Init(void)
{
	ST_UART_CONFIG_t configs = {
		UART_NORMAL_SPEED,
		200,
		UART_TRANSMIT_ENABLE,
		UART_RECIEVE_ENABLE,
		UART_8_Bit_CHAR,
		UART_NO_PARITY,
		UART_1_STOP_BIT,
		UART_TRANSMITER_INT_DISABLE,
		UART_RECIEVER_INT_DISABLE
	};
	ST_DIO_config port_b_3 = {DIO_PORTB, PIN_3, OUTPUT};
	DIO_Init(&port_b_3);
	ST_DIO_config port_b_4 = {DIO_PORTB, PIN_4, OUTPUT};
	DIO_Init(&port_b_4);
	ST_DIO_config port_b_5 = {DIO_PORTB, PIN_5, OUTPUT};
	DIO_Init(&port_b_5);
	UART_Init(configs);
	UART_TransmitString(INTRO_TERMINAL_MESSAGE);
}

void Traffic_Update(void)
{
	uint8_t y[7];
	UART_TransmitString((uint8_t *) "Message: ");
	UART_RecieveString(y);
	if (! (string_compare(y,START_MESSAGE)))
	{
		UART_TransmitString(START_TERMINAL_MESSAGE);
		DIO_WritePIN(DIO_PORTB, PIN_3, HIGH);
		DIO_WritePIN(DIO_PORTB, PIN_4, LOW);
		DIO_WritePIN(DIO_PORTB, PIN_5, LOW);
	}
	else if (! (string_compare(y,WAIT_MESSAGE)))
	{
		UART_TransmitString(WAIT_TERMINAL_MESSAGE);
		DIO_WritePIN(DIO_PORTB, PIN_3, LOW);
		DIO_WritePIN(DIO_PORTB, PIN_4, HIGH);
		DIO_WritePIN(DIO_PORTB, PIN_5, LOW);
	}
	else if (! (string_compare(y,STOP_MESSAGE)))
	{
		UART_TransmitString(STOP_TERMINAL_MESSAGE);
		DIO_WritePIN(DIO_PORTB, PIN_3, LOW);
		DIO_WritePIN(DIO_PORTB, PIN_4, LOW);
		DIO_WritePIN(DIO_PORTB, PIN_5, HIGH);
	}
	else if (! (string_compare(y,AT_MESSAGE)))
	{
		UART_TransmitString(OK_TERMINAL_MESSAGE);
	}
	else
	{
		UART_TransmitString(INVALID_TERMINAL_MESSAGE);
	}
}
