/*
 * File Name: LCD.h
 * Creation Date: 07/23/2020
 * Author: Rehab
 * Description: Header File for LCD...
 */

#ifndef __LCD__
#define __LCD__

//FILES INCLUDING
#include "../../Infrastructure/STD_types.h"


#include "LCD_RetVal.h"

//RW PIN
#define WRITE 	PIN_LOW
#define READ 	PIN_HIGH

//RS PIN
#define IR 		PIN_LOW
#define DR 		PIN_HIGH
/********************************************************************************/
/*								LCD COMMANDS									*/
/********************************************************************************/
//CLEAR DISPLAY COMMAND
#define LCD_CLEAR_DISPALY 					0X01
//RETURN HOME COMMAND
#define LCD_RETURN_HOME 					0X02
//ENTRY MODE SET COMMANDS
#define LCD_INC_AC 							0X06
#define LCD_DEC_AC 							0X04
#define LCD_INC_AC_SHIFT_LEFT 				0X07
#define LCD_DEC_AC_SHIFT_RIGHT				0X05
//FUNCTION SET COMMANDS
#define LCD_8BITS_1LINE_5X8 				0X30
#define LCD_8BITS_1LINE_5X11				0X34
#define LCD_8BITS_2LINE_5X8 				0X38
#define LCD_4BITS_1LINE_5X8 				0X20
#define LCD_4BITS_1LINE_5X11				0X24
#define LCD_4BITS_2LINE_5X8 				0X28
//DISPLAY ON/OFF COMMANDS
#define LCD_DISPLAYOFF_CURSOROFF 			0X08
#define LCD_DISPLAYON_CURSORON_NOBLINKING 	0X0E
#define LCD_DISPLAYON_CURSOROFF_NOBLINKING	0X0C
#define LCD_DISPLAYON_CURSORON_BLINKING 	0X0F
#define LCD_DISPLAYON_CURSOROFF_BLINKING	0X0D
//CURSOR OR DISPLAY SHIFT COMMANDS
#define LCD_SHIFTDISPLAY_LEFT 				0X18
#define LCD_SHIFTDISPLAY_RIGHT 				0X1C
#define LCD_MOVECURSOR_LEFT 				0X10
#define LCD_MOVECURSOR_RIGHT 				0X14

#define LCD_LINE1_STARTADDRESS 				0X00
#define LCD_LINE2_STARTADDRESS 				0X40
#define LCD_LINE3_STARTADDRESS 				0X14
#define LCD_LINE4_STARTADDRESS 				0X54

//SET DDRAM ADDRESS COMMAND
#define LCD_LINE1_DDRAM_ADDRESS(COLUMN) 	((0X80|LCD_LINE1_STARTADDRESS)|COLUMN)
#define LCD_LINE2_DDRAM_ADDRESS(COLUMN) 	((0X80|LCD_LINE2_STARTADDRESS)|COLUMN)
#define LCD_LINE3_DDRAM_ADDRESS(COLUMN) 	((0X80|LCD_LINE3_STARTADDRESS)|COLUMN)
#define LCD_LINE4_DDRAM_ADDRESS(COLUMN) 	((0X80|LCD_LINE4_STARTADDRESS)|COLUMN)

//SET CGRAM ADDRESS COMMAND
#define LCD_CGRAM_ADDRESS 					0X40
/********************************************************************************/

//FUNCTIONS PROTOTYPES
uint8_t LCD_Init(void);
uint8_t LCD_SendCommand(uint8_t Cmd);
uint8_t LCD_SendData(uint8_t Data);
uint8_t LCD_SendString(char* String);
uint8_t LCD_SendNumber(uint32_t Number);
#endif
