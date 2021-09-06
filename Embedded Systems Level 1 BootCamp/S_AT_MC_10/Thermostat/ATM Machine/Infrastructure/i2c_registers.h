/*
 * I2C_registers.h
 *
 * Created: 7/13/2021 10:44:35 PM
 *  Author: Marco
 */ 


#ifndef I2C_REGISTERS_H_
#define I2C_REGISTERS_H_

/******************************************************************************
*                              Includes			                          *
*******************************************************************************/
#include "types.h"

/*------------------------------ I2C REGISTERS ------------------------------*/
/* I2C Bit Rate Register*/
#define TWBR		  *((volatile uint8_t*) (0x20))

/* I2C Control Register*/
#define TWCR		  *((volatile uint8_t*) (0x56))

#define TWIE   (uint8_t) 0   // I2C Interrupt Enable
#define TWEN   (uint8_t) 2   // I2C Enable
#define TWWC   (uint8_t) 3   // I2C Write Collision Flag
#define TWSTO  (uint8_t) 4   // I2C STOP Condition
#define TWSTA  (uint8_t) 5   // I2C START Condition
#define TWEA   (uint8_t) 6   // I2C Enable Acknowledge
#define TWINT  (uint8_t) 7   // I2C Interrupt Flag

/*
TWPS1 TWPS0  Prescaler Value
  0	 0				1
  0	 1				4
  1	 0				16
  1	 1				64
*/
/* I2C Status Register*/
#define TWSR		  *((volatile uint8_t*) (0x21))

#define TWPS0  (uint8_t) 0   // I2C Prescaler [n = 1:0]
#define TWPS1  (uint8_t) 1   // I2C Prescaler [n = 1:0]
#define TWS0   (uint8_t) 3   // I2C Status Bit 7 [n = 7:3]
#define TWS1   (uint8_t) 4   // I2C Status Bit 7 [n = 7:3]
#define TWS2   (uint8_t) 5   // I2C Status Bit 7 [n = 7:3]
#define TWS3   (uint8_t) 6   // I2C Status Bit 7 [n = 7:3]
#define TWS4   (uint8_t) 7   // I2C Status Bit 7 [n = 7:3]

/* I2C Data Register*/
#define TWDR		  *((volatile uint8_t*) (0x23))


/* I2C(Slave) Address Register*/
#define TWAR		  *((volatile uint8_t*) (0x22))

#define TWGCE  (uint8_t) 0   // I2C General Call Recognition Enable Bit
#define TWA0   (uint8_t) 1   // I2C (Slave) Address [n = 6:0]
#define TWA1   (uint8_t) 2   // I2C (Slave) Address [n = 6:0]
#define TWA2   (uint8_t) 3   // I2C (Slave) Address [n = 6:0]
#define TWA3   (uint8_t) 4   // I2C (Slave) Address [n = 6:0]
#define TWA4   (uint8_t) 5   // I2C (Slave) Address [n = 6:0]
#define TWA6   (uint8_t) 6   // I2C (Slave) Address [n = 6:0]
#define TWA7   (uint8_t) 7   // I2C (Slave) Address [n = 6:0]
#endif /* I2C_REGISTERS_H_ */