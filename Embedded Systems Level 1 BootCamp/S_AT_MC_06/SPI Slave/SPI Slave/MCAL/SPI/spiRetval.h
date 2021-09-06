/*
 * spiRetval.h
 *
 * Created: 7/13/2021 9:18:07 PM
 *  Author: Marco
 */ 


#ifndef SPIRETVAL_H_
#define SPIRETVAL_H_

/******************************************************************************
*                              Includes													*
*******************************************************************************/
#include "../../Infrastructure/types.h"

/******************************************************************************
*                              PRIMITIVE TYPES											*
*******************************************************************************/
typedef uint8_t SPI_STATUS_t;


/**
* @brief: This return value indicate that the function could
* run successfully and it returns no errors.
*/
#define SPI_SUCCESS (SPI_STATUS_t) 0
/**
* @brief: This return value indicate that the function tries
* to use an uninitialized module.
*/
#define SPI_ERROR_NOT_INITIALIZED (SPI_STATUS_t) 1
/**
* @brief: This return value indicate that the function tries
* to use invalid transmit value.
*/
#define SPI_DATA_ORDER_ERROR (SPI_STATUS_t) 2
/**
* @brief: This return value indicate that the function tries
* to use invalid RECIEVE value.
*/
#define SPI_RECIEVE_ERROR (SPI_STATUS_t) 3
/**
* @brief: This return value indicate that the function tries
* to use invalid transmit value.
*/
#define SPI_MASTER_SLAVE_ERROR (SPI_STATUS_t) 4
/**
* @brief: This return value indicate that the function tries
* to use invalid RECIEVE value.
*/
#define SPI_RECIEVE_INT_ERROR (SPI_STATUS_t) 5
/**
* @brief: This return value indicate that the function tries
* to use invalid RECIEVE value.
*/
#define SPI_CLOCK_POLARITY_ERROR (SPI_STATUS_t) 6
/**
* @brief: This return value indicate that the function tries
* to use invalid RECIEVE value.
*/
#define SPI_CLOCK_PHASE_ERROR (SPI_STATUS_t) 7
/**
* @brief: This return value indicate that the function tries
* to use invalid RECIEVE value.
*/
#define SPI_PRESCALAR_ERROR (SPI_STATUS_t) 8
/**
* @brief: This return value indicate that the function tries
* to use invalid RECIEVE value.
*/
#define SPI_SPEED_ERROR (SPI_STATUS_t) 9
#endif /* SPIRETVAL_H_ */