/*
 * master.h
 *
 * Created: 7/15/2021 1:05:48 AM
 *  Author: Marco
 */ 


#ifndef MASTER_H_
#define MASTER_H_

/******************************************************************************
*                              Includes													*
*******************************************************************************/
#include "../../MCAL/I2C/I2C.h"
#include "../../MCAL/EEPROM/EEPROM.h"
#include "../../MCAL/UART/uart.h"
#include "../../MCAL/DIO/dio.h"
/******************************************************************************
*                              CONSTANTS													*
*******************************************************************************/
#define I2C_DDR				PORTC_DIR
#define SCL						PIN_0
#define SDA						PIN_1

#define SLAVE_ADDR         (uint8_t)(0xA0)
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
void I2C_Master_Init(void);
void I2C_Master_Update(void);


#endif /* MASTER_H_ */