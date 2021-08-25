/*
 * master.h
 *
 * Created: 7/15/2021 1:05:48 AM
 *  Author: Marco
 */ 


#ifndef SLAVE_H_
#define SLAVE_H_

/******************************************************************************
*                              Includes													*
*******************************************************************************/
#define F_CPU 1000000UL
#include <util/delay.h>
#include "../../MCAL/I2C/I2C.h"
#include "../../MCAL/DIO/dio.h"
/******************************************************************************
*                              CONSTANTS													*
*******************************************************************************/
#define I2C_DDR				PORTC_DIR
#define SCL						PIN_0
#define SDA						PIN_1

#define SLAVE_ADDR			(uint8_t)(0xA0)
/******************************************************************************
*                               FUNCTION DECLARATIONS                         *
*******************************************************************************/
void I2C_Slave_Init(void);
void I2C_Slave_Update(void);


#endif /* SLAVE_H_ */