/*
 * lcd.h
 *
 * Created: 7/26/2021 8:27:58 PM
 *  Author: Marco
 */ 


#ifndef LCD_H_
#define LCD_H_

/******************************************************************************
*                              Includes													*
*******************************************************************************/
#include "lcdConfig.h"

/******************************************************************************
*                               FUNCTION DECLARATIONS                         *
*******************************************************************************/
void LCD_INIT(void);
void LCD_WRITE_COMMAND(uint8_t command);
void LCD_WRITE_CHAR(uint8_t data);
void LCD_WRITE_STRING(uint8_t* data);
void LCD_isbusy(void);
void LCD_clear_screen(void);
void LCD_GOTO_XY(uint8_t line, uint8_t position);
void LCD_CUSTOM_CHARACTER(void);


#endif /* LCD_H_ */