/*
* i2c.h
*
* Created: 7/13/2021 8:58:24 PM
*  Author: Marco
*/


#ifndef I2C_H_
#define I2C_H_

/******************************************************************************
*                              Includes													*
*******************************************************************************/
#include "../../Infrastructure/registers.h"
#include "../../Infrastructure/i2c_registers.h"
#include "../../Infrastructure/utils.h"
#include "i2cRetval.h"
#include "i2cConfig.h"


/******************************************************************************
*                               FUNCTION DECLARATIONS                         *
*******************************************************************************/
I2C_STATUS_t I2C_Init(uint8_t u8_I2C_CH);
I2C_STATUS_t I2C_SetSlaveAddress(uint8_t u8_I2C_CH, uint8_t u8_SlaveADDR);

I2C_STATUS_t I2C_Start(uint8_t u8_I2C_CH);
I2C_STATUS_t I2C_RepeatedStart(uint8_t u8_I2C_CH);
I2C_STATUS_t I2C_Stop(uint8_t u8_I2C_CH);

I2C_STATUS_t I2C_Write(uint8_t u8_I2C_CH, uint8_t u8_Data);
I2C_STATUS_t I2C_ReadAck(uint8_t u8_I2C_CH, uint8_t * pu8_Data);
I2C_STATUS_t I2C_ReadNotAck(uint8_t u8_I2C_CH, uint8_t * pu8_Data);

I2C_STATUS_t I2C_GetStatus(uint8_t u8_I2C_CH, uint8_t * pu8_Status);

I2C_STATUS_t I2C_EnableInterrupt(uint8_t u8_I2C_CH);
I2C_STATUS_t I2C_DisableInterrupt(uint8_t u8_I2C_CH);

//typedef void(*Ptr_VoidFuncVoid_t)(void);
I2C_STATUS_t I2C_SetCallback(uint8_t u8_I2C_CH, Ptr_VoidFuncVoid_t Callback);
#endif /* I2C_H_ */