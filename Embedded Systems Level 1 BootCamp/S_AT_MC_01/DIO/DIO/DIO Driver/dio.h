/*
* dio.h
*
* Created: 7/8/2021 6:11:13 PM
*  Author: Marco
*/


#ifndef DIO_H_
#define DIO_H_

/******************************************************************************
*                              Includes			                          *
*******************************************************************************/
#include "../registers.h"

/******************************************************************************
*                              CONSTANTS			                          *
*******************************************************************************/

typedef uint8_t E_STATUS;

#define E_INVALID (E_STATUS) 0
#define E_OK (E_STATUS) 1

/*-------------------------------- Input/Output -----------------------------*/
#define INPUT (uint8_t) 0
#define OUTPUT (uint8_t) 1

/*---------------------------------- High/Low -------------------------------*/
#define LOW (uint8_t) 0
#define HIGH (uint8_t) 1

/******************************************************************************
*                                     ENUMS                                   *
*******************************************************************************/

/*----------------------------------- PINS ----------------------------------*/
typedef enum {
	PIN_0,
	PIN_1,
	PIN_2,
	PIN_3,
	PIN_4,
	PIN_5,
	PIN_6,
	PIN_7
}EN_pins;

typedef enum{
	DIO_PORTA,
	DIO_PORTB,
	DIO_PORTC,
	DIO_PORTD
}PORTS;

/******************************************************************************
*                               STRUCTS AND UNIONS                            *
*******************************************************************************/

/*-------------------------------- PORT CONFIG ------------------------------*/
typedef struct
{
	uint8_t port;
	EN_pins pin;
	uint8_t dir;
}ST_DIO_config;

/******************************************************************************
*                               FUNCTION-LIKE MACROS                          *
*******************************************************************************/
#define SET_BIT(PORT,BIT)	  (PORT|=(1<<BIT))
#define RESET_BIT(PORT,BIT)	  (PORT&=~(1<<BIT))
#define TOGGLE_BIT(PORT,BIT)  (PORT^=(1<<BIT))
#define READ_BIT(PORT,BIT)	  (PORT&(1<<BIT))

/******************************************************************************
*                               FUNCTION DECLARATIONS                         *
*******************************************************************************/

/*******************************************************************************
* Parameters (in) : configurations - A pointer to a structure (uint8_t port, EN_pins pin, uint8_t dir)
* Parameters (out): None
* Return Value : Error - For error handling if the user input another index for port
* Description : Initialize DIO pins to be input or output
********************************************************************************/
E_STATUS DIO_Init(ST_DIO_config* configurations);


/*******************************************************************************
* Parameters (in) : configurations - A pointer to a structure (uint8_t port, EN_pins pin, uint8_t dir)
* Parameters (out): None
* Return Value : Error - For error handling if the user input another index for port or pin
* Description : Initialize DIO pins to be input or output
********************************************************************************/
E_STATUS DIO_Read_PIN(uint8_t port, EN_pins pin, uint8_t *data);


/*******************************************************************************
* Parameters (in) : = uint8_t port, EN_pins pin, uint8_t data
* Parameters (out): None
* Return Value : Error - For error handling if the user input another index for port or pin
* Description : Output a HIGH or LOW on any pin
********************************************************************************/
E_STATUS DIO_Write_PIN(uint8_t port, EN_pins pin, uint8_t data);


/*******************************************************************************
* Parameters (in) : = uint8_t port, EN_pins pin, uint8_t data
* Parameters (out): None
* Return Value : Error - For error handling if the user input another index for port or pin
* Description : Output a HIGH or LOW on any pin
********************************************************************************/
E_STATUS DIO_Write_PORT(uint8_t port,uint8_t data);


/*******************************************************************************
* Parameters (in) : configurations - A pointer to a structure (uint8_t port, EN_pins pin, uint8_t dir)
* Parameters (out): None
* Return Value : Error - For error handling if the user input another index for port
* Description : Initialize DIO pins to be input or output
********************************************************************************/
E_STATUS DIO_Toggle_PIN(uint8_t port, EN_pins pin);

ST_DIO_config configs;


#endif /* DIO_H_ */