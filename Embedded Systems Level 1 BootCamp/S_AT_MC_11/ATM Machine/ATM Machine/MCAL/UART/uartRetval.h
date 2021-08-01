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
#include "../../Infrastructure/STD_TYPES.h"

/******************************************************************************
*                              PRIMITIVE TYPES											*
*******************************************************************************/
#define int8_t UART_STATUS_t


/**
* @brief: This return value indicate that the function could
* run successfully and it returns no errors.
*/
#define UART_SUCCESS (UART_STATUS_t) 0
/**
* @brief: This return value indicate that the function tries
* to use an uninitialized module.
*/
#define UART_ERROR_NOT_INITIALIZED (UART_STATUS_t) 1
/**
* @brief: This return value indicate that the function tries
* to use an less or more char bits.
*/
#define UART_CHAR_BITS_ERROR (UART_STATUS_t) 2
/**
* @brief: This return value indicate that the function tries
* to use an less or more stop bits.
*/
#define UART_STOP_BITS_ERROR (UART_STATUS_t) 3
/**
* @brief: This return value indicate that the function tries
* to use invalid parity mode.
*/
#define UART_PARITY_ERROR (UART_STATUS_t) 4
/**
* @brief: This return value indicate that the function tries
* to use invalid baud rate.
*/
#define UART_INVALID_BAUD_RATE (UART_STATUS_t) 5
/**
* @brief: This return value indicate that the function tries
* to use invalid transmit value.
*/
#define UART_TRANSMIT_ERROR (UART_STATUS_t) 6
/**
* @brief: This return value indicate that the function tries
* to use invalid RECIEVE value.
*/
#define UART_RECIEVE_ERROR (UART_STATUS_t) 7
/**
* @brief: This return value indicate that the function tries
* to use invalid transmit value.
*/
#define UART_TRANSMIT_INT_ERROR (UART_STATUS_t) 8
/**
* @brief: This return value indicate that the function tries
* to use invalid RECIEVE value.
*/
#define UART_RECIEVE_INT_ERROR (UART_STATUS_t) 9
#endif /* UARTRETVAL_H_ */