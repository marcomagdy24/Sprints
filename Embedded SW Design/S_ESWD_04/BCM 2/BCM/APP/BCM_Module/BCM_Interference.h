/*
 * BCM_Interference.h
 *
 * Created: 31-Aug-21 2:20:16 AM
 *  Author: ayman
 */ 


#ifndef BCM_INTERFERENCE_H_
#define BCM_INTERFERENCE_H_

#include "../../MCAL/UART/uart.h"
#include "../../MCAL/SPI/SPI.h"
#include "../../MCAL/I2C/I2C.h"
#include "../../MCAL/Timer/Timer_Int.h"

#define TEST 0


#define MAX_SIZE	(uint16_t)(100)
#define MAX_MODES	(uint16_t)(3)

#define BCM_ID		(uint8_t)(0xAE)
#define MCU_ID		(uint8_t)(1)


/******************************************************************************
*                              STRUCTS AND UNIONS							  *
*******************************************************************************/
typedef struct
{
	uint8_t uartEnable;
	uint8_t spiEnable;
	uint8_t i2cEnable;
}ST_BCMModes_t;

typedef struct
{
	ST_BCMModes_t modes;
}ST_BCMConfig_t;

/******************************************************************************
*                                 APIS DECLARATIONS                           *
*******************************************************************************/
ST_BCMConfig_t configs;


E_STATUS BCM_Send(ptr_uint8_t data, uint8_t u8_RxID, uint16_t u16_size);



#endif /* BCM_INTERFERENCE_H_ */