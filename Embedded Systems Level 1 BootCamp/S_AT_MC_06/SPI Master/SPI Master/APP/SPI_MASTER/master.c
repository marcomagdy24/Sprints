/*
* master.c
*
* Created: 7/15/2021 1:05:37 AM
*  Author: Marco
*/

/******************************************************************************
*                              Includes													*
*******************************************************************************/
#include "master.h"
#include <util/delay.h>
/******************************************************************************
*                         APIS IMPLEMENTATION											*
*******************************************************************************/

void SPI_Master_Init(void)
{
	PORTA_DIR = 0xFF;
	SPI_Init();
}

void SPI_Master_Update(void)
{
	for (uint8_t i = 0; i < 255; i++)
	{
		while ((READ_BIT(SPSR, WCOL)));
		SPI_TransmitChar(i);
		PORTA_DATA = i;
		_delay_ms(100);
	}
}