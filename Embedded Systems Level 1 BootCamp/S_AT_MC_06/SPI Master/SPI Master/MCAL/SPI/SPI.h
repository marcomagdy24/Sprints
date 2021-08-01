/*
* spi.h
*
* Created: 7/13/2021 8:58:24 PM
*  Author: Marco
*/


#ifndef SPI_H_
#define SPI_H_

/******************************************************************************
*                              Includes													*
*******************************************************************************/
#include "../../Infrastructure/registers.h"
#include "../../Infrastructure/spi_registers.h"
#include "../../Infrastructure/utils.h"
#include "spiRetval.h"
#include "spiConfig.h"
/******************************************************************************
*                              CONSTANTS													*
*******************************************************************************/
#define F_CPU 1000000UL
#define NOT_INIT                          (uint8_t)(0)
#define INIT                              (uint8_t)(1)
#define STRING_START                      (uint8_t)(0)
#define STRING_END								(uint8_t)(0)
#define RESET_SPDR								(uint8_t)(0xFF)


/******************************************************************************
*                               FUNCTION DECLARATIONS                         *
*******************************************************************************/
SPI_STATUS_t SPI_Init();
SPI_STATUS_t SPI_TransmitChar(uint8_t data);
SPI_STATUS_t SPI_TransmitString(uint8_t *data);
SPI_STATUS_t SPI_RecieveChar(uint8_t * data);
SPI_STATUS_t SPI_RecieveString(uint8_t * data);

#endif /* SPI_H_ */