/*
* eeprom.h
*
* Created: 7/13/2021 8:58:24 PM
*  Author: Marco
*/


#ifndef EEPROM_H_
#define EEPROM_H_

/******************************************************************************
*                              Includes													*
*******************************************************************************/
#include "../../Infrastructure/registers.h"
#include "../../Infrastructure/utils.h"
#include "../../MCAL/I2C/I2C.h"
/******************************************************************************
*                               FUNCTION DECLARATIONS                         *
*******************************************************************************/
void EEPROM_Write (uint8_t u8_Data, uint8_t u8_ADDR);
void EEPROM_Read  (uint8_t u8_ADDR, uint8_t * ptr);
#endif /* EEPROM_H_ */