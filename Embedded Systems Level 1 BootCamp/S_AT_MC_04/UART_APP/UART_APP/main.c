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
	ST_DIO_config port_b_5 = {DIO_PORTB, PIN_5, OUTPUT};
	DIO_Init(&port_b_5);
	UART_Init(configs);
	UART_TransmitString((uint8_t *) "Start");
	UART_TransmitChar('\r');
	uint16_t received ;
	uint8_t y[10];
	UART_TransmitString((uint8_t *) "Received: ");
	if (!(UART_RecieveString(y)))
	{
		DIO_Write_PIN(DIO_PORTB, PIN_5, HIGH);
	}
	UART_TransmitString((uint8_t *) "Sent: ");
	UART_TransmitString(y);
	UART_TransmitChar(NEW_LINE);
	/* Replace with your application code */
	while (1)
	{
		UART_TransmitString((uint8_t *) "Received: ");
		UART_RecieveChar(&received);
		UART_TransmitString((uint8_t *) "       ");
		UART_TransmitString((uint8_t *) "Sent: ");
		UART_TransmitChar(received);
		UART_TransmitChar(NEW_LINE);
	}
}

