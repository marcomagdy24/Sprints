/*
 * lcdConfig.h
 *
 * Created: 7/13/2021 8:58:57 PM
 *  Author: Marco
 */ 


#ifndef LCDCONFIG_H_
#define LCDCONFIG_H_

/******************************************************************************
*                              INCLUDES										  *
*******************************************************************************/
#define F_CPU 8000000UL
#include "../../MCAL/DIO/dio.h"
#include "../../Utils/registers.h"
#include "../../Utils/types.h"
#if !TEST
#include "../../Utils/delay.h"
#endif
/******************************************************************************
*                              CONSTANTS									  *
*******************************************************************************/
/*---------------------------- LCD CONFIGS -----------------------------*/
#define FOUR_BIT_MODE							0
#define EIGHT_BIT_MODE							1

/*		Select Mode			*/
/*		FOUR_BIT_MODE		*/
/*		EIGHT_BIT_MODE		*/
#define LCD_MODE FOUR_BIT_MODE

/*------------------------------ LCD REDGISTERS -----------------------------*/
#define LCD_PORT				PORTD_DATA
#define DataDir_LCD_PORT		PORTD_DIR

/*------------------------------ LCD PINS -----------------------------*/
#define LCD_PINS_NUMBER			(uint8_t)(7)

#define RS_SWITCH				(uint8_t)(0)
#define RW_SWITCH				(uint8_t)(1)
#define EN_SWITCH		        (uint8_t)(2)
#define DATA_4					(uint8_t)(3)
#define DATA_5					(uint8_t)(4)
#define DATA_6			        (uint8_t)(5)
#define DATA_7					(uint8_t)(6)

/**
* @brief: This macros used in Four bit mode
* we need to specify D4, D5, D6, D7 pins
* connected to MCU as (uint8_t)(x) where x
* is pin number
*/

typedef ST_DIO_config ST_LCD_ConfigPINS ;




#endif /* LCDCONFIG_H_ */