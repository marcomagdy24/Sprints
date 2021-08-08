/*
 * master.h
 *
 * Created: 7/15/2021 1:05:48 AM
 *  Author: Marco
 */ 


#ifndef THERMOSTAT_H_
#define THERMOSTAT_H_

/******************************************************************************
*                              Includes													*
*******************************************************************************/
#include <stdlib.h>
#include "../../MCAL/LCD/lcd.h"
#include "../../MCAL/ADC/adc.h"
#include "../../MCAL/Keypad/Keypad.h"
#include "../../EUCAL/Motor/motor.h"
/******************************************************************************
*                              CONSTANTS													*
*******************************************************************************/
#define I2C_DDR				PORTC_DIR
#define SCL						PIN_0
#define SDA						PIN_1

#define START_COMMAND      (uint8_t *) ("START \r")
#define ADDRESS_INFO       (uint8_t *) ("[INFO] Waiting for Address \r")
#define DATA_INFO          (uint8_t *) ("[INFO] Waiting for Data \r")								
#define RECEIVED_COMMAND   (uint8_t *) ("Received: ")
#define OK_COMMAND         (uint8_t *) ("OK \r")
#define WRITE_COMMAND      (uint8_t *) ("WRITE")
#define READ_COMMAND       (uint8_t *) ("READ")
#define DATA_COMMAND       (uint8_t *) ("the data stored is: ")
#define READ_WRITE         (uint8_t *)  ("Do you want to read or write on EEPROM? \r")
#define INVALID_COMMAND    (uint8_t *) ("[INFO] Invalid Command \r")	
/******************************************************************************
*                               FUNCTION DECLARATIONS                         *
*******************************************************************************/
void THERMOSTAT_Init(void);
void THERMOSTAT_Update(void);


#endif /* THERMOSTAT_H_ */