/*
 * i2cRetval.h
 *
 * Created: 7/13/2021 9:18:07 PM
 *  Author: Marco
 */ 


#ifndef I2CRETVAL_H_
#define I2CRETVAL_H_

/******************************************************************************
*                              Includes													*
*******************************************************************************/
#include "../../Infrastructure/types.h"

/******************************************************************************
*                              PRIMITIVE TYPES											*
*******************************************************************************/
typedef uint8_t I2C_STATUS_t;


/**
* @brief: This return value indicate that the function could
* run successfully and it returns no errors.
*/
#define I2C_SUCCESS (I2C_STATUS_t) 0
/**
* @brief: This return value indicate that the function tries
* to use an uninitialized module.
*/
#define I2C_INVALID_CH (I2C_STATUS_t) 1
/**
* @brief: This return value indicate that the function tries
* to use invalid transmit value.
*/
#define I2C_NULL_PTR (I2C_STATUS_t) 2
#endif /* I2CRETVAL_H_ */