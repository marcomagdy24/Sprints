/*
* master.c
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

void I2C_Slave_Init(void)
{
	PORTA_DIR = 0xFF;
	/* set slave address */
	I2C_SetSlaveAddress(I2C_CH_0, SLAVE_ADDR);
}

void I2C_Slave_Update(void)
{
	uint8_t data;
	uint8_t status;
	/* get data from bus */
	I2C_ReadAck(I2C_CH_0, &data);
	/* get the status */
	I2C_GetStatus(I2C_CH_0, &status);
	/* make sure the slave node received it's address and send ack to master. */
	if(status != I2C_STATUS_R_ADDR_ACK)
	{
		return;
	}
	/* get data from bus */
	I2C_ReadAck(I2C_CH_0, &data);
	/* get the status */
	I2C_GetStatus(I2C_CH_0, &status);
	/* make sure the slave node received the data and send ack to master. */
	if(status != I2C_STATUS_R_DATA_ACK)
	{
		return;
	}
	/* set portA pins to the received data */
	PORTA_DATA = data;
	//EEPROM_Read(0x00,&ptr);
}

