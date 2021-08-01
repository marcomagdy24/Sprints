/*
 * spiConfig.h
 *
 * Created: 7/13/2021 8:58:57 PM
 *  Author: Marco
 */ 


#ifndef SPICONFIG_H_
#define SPICONFIG_H_

#include "../../MCAL/DIO/dio.h"

/******************************************************************************
*                              CONSTANTS													*
*******************************************************************************/
#define SPI_DDR PORTB_DIR
#define SS      PIN_4
#define MOSI    PIN_5
#define MISO    PIN_6
#define SCK     PIN_7

/******************************************************************************
*                                     typedef enum                            *
*******************************************************************************/
typedef enum
{
	SPI_Fosc_4   = 0b00,
	SPI_Fosc_16  = 0b01,
	SPI_Fosc_64  = 0b10,
	SPI_Fosc_128 = 0b11
} EN_SPI_PRESCALAR_t;

typedef enum
{
	SPI_NORMAL_SPEED,
	SPI_DOUBLE_SPEED
} EN_SPI_SPEED_t;

typedef enum
{
	SPI_CLOCK_PHASE_SAMPLE	    =	  (0<<2),
	SPI_CLOCK_PHASE_SETUP		 =	  (1<<2)
} EN_SPI_CLOCK_PHASE_t;

typedef enum
{
	SPI_CLOCK_POLARITY_RISING	    =	  (0<<3),
	SPI_CLOCK_POLARITY_FALLING		 =	  (1<<3)
} EN_SPI_CLOCK_POLARITY_t;

typedef enum
{
	SPI_SLAVE_MODE		    =	  (0<<4),
	SPI_MASTER_MODE	    =	  (1<<4)
} EN_SPI_MASTER_SLAVE_t;

typedef enum
{
	SPI_MSB_FIRST	      =	  (0<<5),
	SPI_LSB_FIRST	      =	  (1<<5)
} EN_SPI_DATA_ORDER_t;

typedef enum
{
	SPI_RECIEVE_DISABLE		 =	  (0<<6),
	SPI_RECIEVE_ENABLE	    =	  (1<<6)
} EN_SPI_RECIEVE_t;

typedef enum
{
	SPI_RECIEVER_INT_DISABLE 	   =	(0<<7),
	SPI_RECIEVER_INT_ENABLE 	   =	(1<<7)
} EN_SPI_RECIEVE_INT_t;


/******************************************************************************
*                               STRUCTS AND UNIONS                            *
*******************************************************************************/
typedef struct
{
	
	EN_SPI_MASTER_SLAVE_t		 MASTER_SLAVE_MODE;
	EN_SPI_SPEED_t					 SPI_SPEED;
	EN_SPI_PRESCALAR_t			 PRESCALAR;
	EN_SPI_CLOCK_POLARITY_t		 CLOCK_POLARITY ;
	EN_SPI_CLOCK_PHASE_t			 CLOCK_PHASE;
	EN_SPI_DATA_ORDER_t			 DATA_ORDER;
	EN_SPI_RECIEVE_t	          RECIEVE;
	EN_SPI_RECIEVE_INT_t	       RECIEVER_INT;
} ST_SPI_CONFIG_t;





#endif /* SPICONFIG_H_ */