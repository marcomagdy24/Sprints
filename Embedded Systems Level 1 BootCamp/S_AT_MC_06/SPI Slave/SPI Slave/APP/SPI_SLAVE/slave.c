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
	SPI_Init();
}

void SPI_Slave_Update(void)
{
	uint8_t* recieved;
	SPI_RecieveChar(recieved);
	PORTA_DATA = *recieved;
	_delay_ms(100);

}