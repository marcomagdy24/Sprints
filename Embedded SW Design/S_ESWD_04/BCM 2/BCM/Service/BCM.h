/*
 * BCM.h
 *
 * Created: 8/25/2021 4:09:45 PM
 *  Author: Marco
 */ 


#ifndef BCM_H_
#define BCM_H_

/******************************************************************************
*                              INCLUDES										  *
*******************************************************************************/
#include "../MCAL/UART/uart.h"
#include "../MCAL/SPI/SPI.h"
#include "../MCAL/I2C/I2C.h"
#include "../MCAL/Timer/Timer_Int.h"


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
E_STATUS BCM_Send(ptr_uint8_t data, uint8_t u8_RxID, uint16_t u16_size);
E_STATUS BCM_Setup_RxBuffer(uint16_t size);
E_STATUS BCM_TxMainFunction();
E_STATUS BCM_RxMainFunction();
E_STATUS BCM_Receive();
// E_STATUS BCM_RxUnlock();
// E_STATUS BCM_GetTxBufferStatus();
// E_STATUS BCM_GetRxBufferStatus();

ST_BCMConfig_t configs;


#endif /* BCM_H_ */