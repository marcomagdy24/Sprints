/*
 * lcd.h
 *
 * Created: 7/26/2021 8:27:58 PM
 *  Author: Marco
 */ 


#ifndef LCD_H_
#define LCD_H_

/******************************************************************************
*                              INCLUDES										  *
*******************************************************************************/
#include "lcd_Config.h"
#include "../../MCAL/DIO/dio.h"

/******************************************************************************
*                              CONSTANTS									  *
*******************************************************************************/
/*---------------------------- LCD MACROS ------------------------------*/
#define FIRST_ROW								(uint8_t)(1)
#define SECOND_ROW								(uint8_t)(2)
#define FIRST_ROW_LIMIT							(uint8_t)(16)
#define SECOND_ROW_LIMIT						(uint8_t)(32)
#define LCD_BEGIN								(uint8_t)(0)
#define LCD_END									(uint8_t)(16)
#define OperationSuccess 						0
#define OperationFail 							1
#define OperationRunning						2
#define OperationStarted 						255

/******************************************************************************
*                               FUNCTION DECLARATIONS                         *
*******************************************************************************/
E_STATUS LCD_INIT(void);
E_STATUS LCD_WRITE_COMMAND(uint8_t command);
E_STATUS LCD_WRITE_CHAR(uint8_t data);
E_STATUS LCD_WRITE_STRING(uint8_t* data);
E_STATUS LCD_WRITE_NUMBER(float32_t data);
E_STATUS LCD_isbusy(void);
E_STATUS LCD_clear_screen(void);
E_STATUS LCD_GOTO_XY(uint8_t line, uint8_t position);
E_STATUS LCD_CUSTOM_CHARACTER(void);


#endif /* LCD_H_ */