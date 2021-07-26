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
#include "../../MCAL/SPI/SPI.h"
#include "../../MCAL/DIO/dio.h"
/******************************************************************************
*                              CONSTANTS													*
*******************************************************************************/
#define SPI_DDR PORTB_DIR
#define SS      PIN_4
#define MOSI    PIN_5
#define MISO    PIN_6
#define SCK     PIN_7

/******************************************************************************
*                               FUNCTION DECLARATIONS                         *
*******************************************************************************/
void SPI_Master_Init(void);
void SPI_Master_Update(void);


#endif /* MASTER_H_ */