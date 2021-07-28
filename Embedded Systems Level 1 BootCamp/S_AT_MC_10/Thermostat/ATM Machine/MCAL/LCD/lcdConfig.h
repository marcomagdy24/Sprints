/*
 * lcdConfig.h
 *
 * Created: 7/13/2021 8:58:57 PM
 *  Author: Marco
 */ 


#ifndef LCDCONFIG_H_
#define LCDCONFIG_H_

/******************************************************************************
*                              Includes													*
*******************************************************************************/
#define F_CPU 1000000UL
#include "../../Infrastructure/registers.h"
#include "../../Infrastructure/types.h"
#include <util/delay.h>
/******************************************************************************
*                              CONSTANTS													*
*******************************************************************************/
/*------------------------------ LCD REDGISTERS -----------------------------*/
#define LCD_PORT				PORTD_DATA
#define DataDir_LCD_PORT	PORTD_DIR
#define LCD_CTRL				PORTC_DATA
#define DataDir_LCD_CTRL	PORTC_DIR

/*------------------------------ LCD PINS -----------------------------*/
#define RS_SWITCH				(uint8_t)(5)
#define RW_SWITCH				(uint8_t)(6)
#define EN_SWITCH		      (uint8_t)(7)

/*----------------------------- LCD CONFIGS ---------------------------*/
//0:8bit data mode | 4:4bit data mode
#define DATA_SHIFT 4

//#define EIGHT_BIT_MODE
#define FOUR_BIT_MODE

#define FIRST_ROW									(uint8_t)(1)
#define SECOND_ROW								(uint8_t)(2)
#define FIRST_ROW_LIMIT							(uint8_t)(16)
#define SECOND_ROW_LIMIT						(uint8_t)(32)
#define LCD_BEGIN									(uint8_t)(0)
#define LCD_END									(uint8_t)(16)
/*---------------------------- LCD COMMANDS ---------------------------*/
#define LCD_FUNCTION_8BIT_2LINES   			(uint8_t)(0x38)
#define LCD_FUNCTION_4BIT_2LINES   			(uint8_t)(0x28)
#define LCD_MOVE_DISP_RIGHT       			(uint8_t)(0x1C)
#define LCD_MOVE_DISP_LEFT   					(uint8_t)(0x18)
#define LCD_MOVE_CURSOR_RIGHT   				(uint8_t)(0x14)
#define LCD_MOVE_CURSOR_LEFT 	  				(uint8_t)(0x10)
#define LCD_DISP_OFF   							(uint8_t)(0x08)
#define LCD_DISP_ON_CURSOR   					(uint8_t)(0x0E)
#define LCD_DISP_ON_CURSOR_BLINK   			(uint8_t)(0x0F)
#define LCD_DISP_ON_BLINK   					(uint8_t)(0x0D)
#define LCD_DISP_ON   							(uint8_t)(0x0C)
#define LCD_ENTRY_DEC							(uint8_t)(0x04)
#define LCD_ENTRY_DEC_SHIFT   				(uint8_t)(0x05)
#define LCD_ENTRY_INC_   						(uint8_t)(0x06)
#define LCD_ENTRY_INC_SHIFT   				(uint8_t)(0x07)
#define LCD_BEGIN_AT_FIRST_ROW				(uint8_t)(0x80)
#define LCD_BEGIN_AT_SECOND_ROW				(uint8_t)(0xC0)
#define LCD_CLEAR_SCREEN						(uint8_t)(0x01)
#define LCD_ENTRY_MODE							(uint8_t)(0x06)
/******************************************************************************
*                              FUNCTION-LIKE MACROS									*
*******************************************************************************/
#define BITRATE(TWSR)	((F_CPU/SCL_CLK)-16)/(2* (TWSR&((1<<TWPS0)|(1<<TWPS1))))

#endif /* LCDCONFIG_H_ */