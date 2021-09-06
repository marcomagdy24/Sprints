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

/******************************************************************************
*                         APIS IMPLEMENTATION											*
*******************************************************************************/

void I2C_Master_Init(void)
{
	uint8_t status;
	PORTA_DIR = 0xFF;
	/* initialize I2C */
	I2C_Init(I2C_CH_0);
	/* start I2C */
	I2C_Start(I2C_CH_0);
	/* get the status */
	I2C_GetStatus(I2C_CH_0, &status);
	/* make sure the master node got the bus. */
	if(status != I2C_STATUS_START)
	{
		return;
	}
	/* send the slave address + master write */
	I2C_Write(I2C_CH_0, SLAVE_ADDR);
	I2C_GetStatus(I2C_CH_0, &status);
	/* make sure the master node got ack from slave. */
	if(status != I2C_STATUS_T_ADDR_ACK)
	{
		return;
	}
	
}

void I2C_Master_Update(void)
{
	uint8_t status;
	
	
	for (uint8_t i = 0; i < 255; i++)
	{
		I2C_Write(I2C_CH_0, i);
		/* get the status */
		I2C_GetStatus(I2C_CH_0,&status);
		/* make sure the master node got ack from slave. */
		if(status != I2C_STATUS_T_DATA_ACK)
		{
			return;
		}
		/* start I2C */
		I2C_RepeatedStart(I2C_CH_0);
		/* get the status */
		I2C_GetStatus(I2C_CH_0, &status);
		/* make sure the master node got the bus. */
		if(status != I2C_STATUS_REPEATED_START)
		{
			return;
		}
		/* send the slave address + master write */
		I2C_Write(I2C_CH_0, SLAVE_ADDR);
		I2C_GetStatus(I2C_CH_0, &status);
		/* make sure the master node got ack from slave. */
		if(status != I2C_STATUS_T_ADDR_ACK)
		{
			return;
		}
		PORTA_DATA = i;
		_delay_ms(20);
	}
	/* stop condition */
	I2C_Stop(I2C_CH_0);		
}

