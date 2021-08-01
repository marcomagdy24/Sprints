/*
 * uartRetval.h
 *
 * Created: 7/13/2021 9:18:07 PM
 *  Author: Marco
 */ 


#ifndef LEDRETVAL_H_
#define LEDRETVAL_H_

/******************************************************************************
*                              Includes													*
*******************************************************************************/
#include "../../Infrastructure/types.h"

/******************************************************************************
*                              PRIMITIVE TYPES											*
*******************************************************************************/
typedef uint8_t LED_STATUS_t;

/**
* @brief: This return value indicate that the function
* ran successfully and it returns no errors.
*/
#define LED_SUCCESS           (LED_STATUS_t) 0 

/**
* @brief: This return value indicate that a function
* got an invalid channel number.
*/
#define LED_INVALID_CH_NO     (LED_STATUS_t) 1

/**
* @brief: This return value indicate that a function
* from DIO driver returned an error.
*/
#define LED_DIO_ERROR         (LED_STATUS_t) 2

#endif /* LEDRETVAL_H_ */
