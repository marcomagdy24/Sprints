/*
* slave.c
*
* Created: 7/15/2021 1:05:37 AM
*  Author: Marco
*/

/******************************************************************************
*                              Includes													*
*******************************************************************************/
#include "slave.h"

/******************************************************************************
*                         APIS IMPLEMENTATION											*
*******************************************************************************/

void SPI_Slave_Init(void)
{
	ST_SPI_CONFIG_t configs = {
		SPI_SLAVE_MODE,
		SPI_NORMAL_SPEED,
		SPI_Fosc_4,
		SPI_CLOCK_POLARITY_RISING ,
		SPI_CLOCK_PHASE_SAMPLE,
		SPI_MSB_FIRST,
		SPI_RECIEVE_ENABLE,
		SPI_RECIEVER_INT_DISABLE,
	};
	ST_UART_CONFIG_t config = {
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
	UART_Init(config);
	if (configs.MASTER_SLAVE_MODE == SPI_MASTER_MODE)
	{
		SPI_DDR |= (1 << SS) | (1 << MOSI) | (1 << SCK);
	}
	else if (configs.MASTER_SLAVE_MODE == SPI_SLAVE_MODE)
	{
		SPI_DDR |= (1 << MISO);
	}
	UART_TransmitString((uint8_t *) "Start");
	UART_TransmitChar('\r');
	SPI_Init(configs);
}

void SPI_Slave_Update(void)
{
	uint8_t recieved[255];
	UART_TransmitString((uint8_t*) "Received: ");
	SPI_RecieveString((uint8_t *) recieved);
	UART_TransmitString((uint8_t*) recieved);
	UART_TransmitChar(STRING_NEW_LINE);
}