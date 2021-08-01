/*
* UART_APP.c
*
* Created: 7/13/2021 7:28:40 PM
* Author : Marco
*/

#include "MCAL/UART/uart.h"
#include "MCAL/DIO/dio.h"

int main(void)
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
	UART_Init(configs);
	UART_TransmitString((uint8_t *) "Start");
	UART_TransmitChar(NEW_LINE);
	uint16_t received ;
	uint8_t y[10];
	UART_TransmitString((uint8_t *) "Received String: ");
	UART_RecieveString(y);
	UART_TransmitString((uint8_t *) "Sent String: ");
	UART_TransmitString(y);
	UART_TransmitChar(NEW_LINE);
	/* Replace with your application code */
	while (1)
	{
		UART_TransmitString((uint8_t *) "Received Char: ");
		UART_RecieveChar(&received);
		UART_TransmitString((uint8_t *) "       ");
		UART_TransmitString((uint8_t *) "Sent Char: ");
		UART_TransmitChar(received);
		UART_TransmitChar(NEW_LINE);
	}
}

