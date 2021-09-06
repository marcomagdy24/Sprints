/*
 * BCM_MainFunction.h
 *
 * Created: 31-Aug-21 2:20:48 AM
 *  Author: ayman
 */ 


#ifndef BCM_MAINFUNCTION_H_
#define BCM_MAINFUNCTION_H_


/******************************************************************************
*                              INCLUDES										  *
*******************************************************************************/
#include "../../MCAL/UART/uart.h"
#include "../../MCAL/SPI/SPI.h"
#include "../../MCAL/I2C/I2C.h"
#include "../../MCAL/Timer/Timer_Int.h"


#define TEST 0

#define MAX_SIZE	(uint16_t)(100)
#define MAX_MODES	(uint16_t)(3)

#define BCM_ID		(uint8_t)(0xAE)
#define MCU_ID		(uint8_t)(2)


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

E_STATUS BCM_Init(ST_BCMConfig_t *configs);
E_STATUS BCM_Setup_RxBuffer(uint16_t size);
E_STATUS BCM_TxMainFunction();
E_STATUS BCM_RxMainFunction();


ST_BCMConfig_t configs;



#endif /* BCM_MAINFUNCTION_H_ */