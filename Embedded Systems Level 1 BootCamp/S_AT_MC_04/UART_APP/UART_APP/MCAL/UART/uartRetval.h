/*
 * uartRetval.h
 *
 * Created: 7/13/2021 9:18:07 PM
 *  Author: Marco
 */ 


#ifndef UARTRETVAL_H_
#define UARTRETVAL_H_

/******************************************************************************
*                              Includes													*
*******************************************************************************/
#include "../../Infrastructure/types.h"

/******************************************************************************
*                              PRIMITIVE TYPES											*
*******************************************************************************/
typedef sint8_t UART_STATUS;


/**
* @brief: This return value indicate that the function could
* run successfully and it returns no errors.
*/
#define UART_SUCCESS (UART_STATUS) 0
/**
* @brief: This return value indicate that the function tries
* to use an uninitialized module.
*/
#define UART_ERROR_NOT_INITIALIZED (UART_STATUS) 1
/**
* @brief: This return value indicate that the function tries
* to use an less or more char bits.
*/
#define UART_CHAR_BITS_ERROR (UART_STATUS) 2
/**
* @brief: This return value indicate that the function tries
* to use an less or more stop bits.
*/
#define UART_STOP_BITS_ERROR (UART_STATUS) 3
/**
* @brief: This return value indicate that the function tries
* to use invalid parity mode.
*/
#define UART_PARITY_ERROR (UART_STATUS) 4
/**
* @brief: This return value indicate that the function tries
* to use invalid baud rate.
*/
#define UART_INVALID_BAUD_RATE (UART_STATUS) 5
/**
* @brief: This return value indicate that the function tries
* to use invalid transmit value.
*/
#define UART_TRANSMIT_ERROR (UART_STATUS) 6
/**
* @brief: This return value indicate that the function tries
* to use invalid RECIEVE value.
*/
#define UART_RECIEVE_ERROR (UART_STATUS) 7
/**
* @brief: This return value indicate that the function tries
* to use invalid transmit value.
*/
#define UART_TRANSMIT_INT_ERROR (UART_STATUS) 8
/**
* @brief: This return value indicate that the function tries
* to use invalid RECIEVE value.
*/
#define UART_RECIEVE_INT_ERROR (UART_STATUS) 9
#endif /* UARTRETVAL_H_ */