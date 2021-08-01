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
*                         LOCAL FUNCTION IMPLEMENTATION								*
*******************************************************************************/
uint8_t compare(uint8_t *a,uint8_t *b)
{
	uint8_t flag=0;
	while((*a!=STRING_END) && (*b!=STRING_END)) // while loop
	{
		if(*a!=*b)
		{
			flag=1;
		}
		a++;
		b++;
	}
	if(flag==0)
	return 0;
	else
	return 1;
}


void Write_EEPROM(uint16_t * data, uint16_t * addr)
{
	UART_TransmitString(DATA_INFO);
	UART_RecieveChar(data);
	UART_TransmitChar(NEW_LINE);
	UART_TransmitString(RECEIVED_COMMAND);
	UART_TransmitChar(*data);
	UART_TransmitChar(NEW_LINE);
	UART_TransmitString(OK_COMMAND);
	EEPROM_Write(*data,*addr);
}

void Get_ADDR(uint8_t cmd[], uint16_t * addr)
{
	UART_TransmitString(READ_WRITE);
	UART_RecieveString(cmd);
	UART_TransmitString(ADDRESS_INFO);
	UART_RecieveChar(addr);
	UART_TransmitChar(NEW_LINE);
	UART_TransmitString(RECEIVED_COMMAND);
	UART_TransmitChar(*addr);
	UART_TransmitChar(NEW_LINE);
	UART_TransmitString(OK_COMMAND);
}

void Read_EEPROM(uint16_t addr, uint8_t * ptr)
{
	EEPROM_Read(addr,ptr);
	UART_TransmitString(DATA_COMMAND);
	UART_TransmitChar(*ptr);
	UART_TransmitChar(NEW_LINE);
}
/******************************************************************************
*                         APIS IMPLEMENTATION											*
*******************************************************************************/

void I2C_Master_Init(void)
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
	UART_TransmitString(START_COMMAND);
}

void I2C_Master_Update(void)
{
	uint8_t ptr;
	uint8_t cmd[6];
	uint16_t addr;
	uint16_t data;
	Get_ADDR(cmd, &addr);
	if (!(compare (WRITE_COMMAND, cmd)))
	{
		Write_EEPROM(&data, &addr);
	}
	else if (!(compare (READ_COMMAND, cmd)))
	{
		Read_EEPROM(addr, &ptr);
	}
	else
	{
		UART_TransmitString(INVALID_COMMAND);
	}
	
	
	
	//EEPROM_Read(0x00,&ptr);
	
}

