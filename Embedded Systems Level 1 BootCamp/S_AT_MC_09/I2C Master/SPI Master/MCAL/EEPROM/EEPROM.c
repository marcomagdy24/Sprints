/*
* uart.c
*
* Created: 7/13/2021 8:58:32 PM
*  Author: Marco
*/

/******************************************************************************
*                              Includes													*
*******************************************************************************/
#include "EEPROM.h"

/******************************************************************************
*                         APIS IMPLEMENTATION											*
*******************************************************************************/
void EEPROM_Write (uint8_t u8_Data, uint8_t u8_ADDR)
{
	I2C_Start(I2C_CH_0);
	I2C_Write(I2C_CH_0, 0xA8); //slave address is 1010.100 and a 0 in the 8th bit to indicate writing.
	I2C_Write(I2C_CH_0, u8_ADDR);
	I2C_Write(I2C_CH_0, u8_Data);
	I2C_Stop(I2C_CH_0);
}
/* the function arguments are an address 
   in the EEPROM to read from and a pointer to a memory 
	place in the MCU to store the read data in */
void EEPROM_Read (uint8_t u8_ADDR, uint8_t * ptr)
{
	I2C_Start(I2C_CH_0);
	I2C_Write(I2C_CH_0, 0xA8);
	I2C_Write(I2C_CH_0, u8_ADDR);
	I2C_RepeatedStart(I2C_CH_0);
	I2C_Write(I2C_CH_0, 0xA9);
	I2C_ReadNotAck(I2C_CH_0, ptr);
	I2C_Stop(I2C_CH_0);
}