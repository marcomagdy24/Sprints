/*
 * i2cRetval.h
 *
 * Created: 7/13/2021 9:18:07 PM
 *  Author: Marco
 */ 


#ifndef ADCRETVAL_H_
#define ADCRETVAL_H_

/******************************************************************************
*                              Includes													*
*******************************************************************************/
#include "../../Infrastructure/STD_TYPES.h"

/******************************************************************************
*                              PRIMITIVE TYPES											*
*******************************************************************************/
#define ADC_STATUS_t	uint8_t

/**
* @brief: This return value indicate that the function could
* run successfully and it returns no errors.
*/
#define ADC_SUCCESS (ADC_STATUS_t) 0
/**
* @brief: This return value indicate that the function tries
* to use an invalid channel.
*/
#define ADC_INVALID_CH (ADC_STATUS_t) 1
/**
* @brief: This return value indicate that the function tries
* to use an null ptr.
*/
#define ADC_NULL_PTR (ADC_STATUS_t) 1
#endif /* ADCRETVAL_H_ */