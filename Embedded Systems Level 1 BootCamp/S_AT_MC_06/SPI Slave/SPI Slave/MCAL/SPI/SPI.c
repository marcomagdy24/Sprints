/*
* uart.c
*
* Created: 7/13/2021 8:58:32 PM
*  Author: Marco
*/

/******************************************************************************
*                              Includes													*
*******************************************************************************/
#include "SPI.h"

/******************************************************************************
*                         GLOBAL STATIC VARIABLES										*
*******************************************************************************/
static ST_SPI_CONFIG_t g_ST_SPI_CONFIG_t;
extern ST_SPI_CONFIG_t config;
/******************************************************************************
*                         APIS IMPLEMENTATION											*
*******************************************************************************/
SPI_STATUS_t SPI_Init()
{
	g_ST_SPI_CONFIG_t = config;
	
	if (g_ST_SPI_CONFIG_t.MASTER_SLAVE_MODE == SPI_MASTER_MODE)
	{
		SPI_DDR |= (1 << SS) | (1 << MOSI) | (1 << SCK);
	}
	else if (g_ST_SPI_CONFIG_t.MASTER_SLAVE_MODE == SPI_SLAVE_MODE)
	{
		SPI_DDR |= (1 << MISO);
	}
	
	/********************Enable SPI Interrupt ******************/
	if ((g_ST_SPI_CONFIG_t.RECIEVER_INT == SPI_RECIEVER_INT_ENABLE) || (g_ST_SPI_CONFIG_t.RECIEVER_INT == SPI_RECIEVER_INT_DISABLE))
	{
		SPCR |= g_ST_SPI_CONFIG_t.RECIEVER_INT;
	}
	else
	{
		return SPI_RECIEVE_INT_ERROR;
	}
	/******************** Data Order ******************/
	if ((g_ST_SPI_CONFIG_t.DATA_ORDER == SPI_LSB_FIRST) || (g_ST_SPI_CONFIG_t.DATA_ORDER == SPI_MSB_FIRST))
	{
		SPCR |= g_ST_SPI_CONFIG_t.DATA_ORDER;
	}
	else
	{
		return SPI_DATA_ORDER_ERROR;
	}
	/******************** Master Slave Select ******************/
	if ((g_ST_SPI_CONFIG_t.MASTER_SLAVE_MODE == SPI_SLAVE_MODE) || (g_ST_SPI_CONFIG_t.MASTER_SLAVE_MODE == SPI_MASTER_MODE))
	{
		SPCR |= g_ST_SPI_CONFIG_t.MASTER_SLAVE_MODE;
	}
	else
	{
		return SPI_MASTER_SLAVE_ERROR;
	}
	/******************** Clock Polarity ******************/
	if ((g_ST_SPI_CONFIG_t.CLOCK_POLARITY == SPI_CLOCK_POLARITY_RISING) || (g_ST_SPI_CONFIG_t.CLOCK_POLARITY == SPI_CLOCK_POLARITY_FALLING))
	{
		SPCR |= g_ST_SPI_CONFIG_t.CLOCK_POLARITY;
	}
	else
	{
		return SPI_CLOCK_POLARITY_ERROR;
	}
	/******************** Clock Phase ******************/
	if ((g_ST_SPI_CONFIG_t.CLOCK_PHASE == SPI_CLOCK_PHASE_SAMPLE) || (g_ST_SPI_CONFIG_t.CLOCK_PHASE == SPI_CLOCK_PHASE_SETUP))
	{
		SPCR |= g_ST_SPI_CONFIG_t.CLOCK_PHASE;
	}
	else
	{
		return SPI_CLOCK_PHASE_ERROR;
	}
	/******************** SCK and Oscillator Frequency ******************/
	if ((g_ST_SPI_CONFIG_t.PRESCALAR >= SPI_Fosc_4) && (g_ST_SPI_CONFIG_t.PRESCALAR <= SPI_Fosc_128))
	{
		SPCR |= g_ST_SPI_CONFIG_t.PRESCALAR;
	}
	else
	{
		return SPI_PRESCALAR_ERROR;
	}
	/******************** Double SPI speed ******************/
	if ((g_ST_SPI_CONFIG_t.SPI_SPEED == SPI_NORMAL_SPEED) || (g_ST_SPI_CONFIG_t.SPI_SPEED == SPI_DOUBLE_SPEED))
	{
		SPSR |= g_ST_SPI_CONFIG_t.SPI_SPEED;
	}
	else
	{
		return SPI_SPEED_ERROR;
	}
	/******************** Enable SPI ******************/
	if ((g_ST_SPI_CONFIG_t.RECIEVE == SPI_RECIEVE_DISABLE) || (g_ST_SPI_CONFIG_t.RECIEVE == SPI_RECIEVE_ENABLE))
	{
		SPCR |= g_ST_SPI_CONFIG_t.RECIEVE;
	}
	else
	{
		return SPI_RECIEVE_ERROR;
	}
	return SPI_SUCCESS;
}

SPI_STATUS_t SPI_TransmitChar(uint8_t data)
{
	SPDR = data;
	while (! (READ_BIT(SPSR, SPIF)));
	return SPI_SUCCESS;
}

SPI_STATUS_t SPI_TransmitString(uint8_t *data)
{
	uint8_t j = STRING_START;
	
	while (data[j]!= STRING_END)		/* Send string till null */
	{
		SPI_TransmitChar(data[j]);
		j++;
	}
	data[j] = STRING_END;
	SPI_TransmitChar(data[j]);
	return SPI_SUCCESS;
}

SPI_STATUS_t SPI_RecieveChar(uint8_t * data)
{
	// Wait for reception complete
	while (! (READ_BIT(SPSR, SPIF)));
	*data = SPDR;
	return SPI_SUCCESS;
}

SPI_STATUS_t SPI_RecieveString(uint8_t *data)
{
	uint8_t i = 0;
	
	while (1) {
		uint8_t c;
		// wait for another char
		while (! (READ_BIT(SPSR, SPIF)));
		c = (uint8_t)SPDR;
		// break on NULL character or new line
		if (c == STRING_END) break;
		// when backspace
		
		// write into the supplied buffer
		data[i] =  (uint8_t)c;
		i++;
	}
	data[i] = STRING_END;
	return SPI_SUCCESS;
}