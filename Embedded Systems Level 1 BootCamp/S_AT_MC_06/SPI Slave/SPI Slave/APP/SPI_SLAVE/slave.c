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
#include <util/delay.h>

/******************************************************************************
*                         APIS IMPLEMENTATION											*
*******************************************************************************/

void SPI_Slave_Init(void)
{
	PORTA_DIR = 0xFF;
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
	if (configs.MASTER_SLAVE_MODE == SPI_MASTER_MODE)
	{
		SPI_DDR |= (1 << SS) | (1 << MOSI) | (1 << SCK);
	}
	else if (configs.MASTER_SLAVE_MODE == SPI_SLAVE_MODE)
	{
		SPI_DDR |= (1 << MISO);
	}
	SPI_Init(configs);
}

void SPI_Slave_Update(void)
{
	uint8_t* recieved;
	SPI_RecieveChar(recieved);
	PORTA_DATA = *recieved;
	_delay_ms(100);

}