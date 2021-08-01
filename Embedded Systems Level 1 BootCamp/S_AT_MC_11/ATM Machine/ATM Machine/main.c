/*
* ATM Machine.c
*
* Created: 7/27/2021 12:02:39 AM
* Author : Marco
*/

#include "MCAL/LCD/lcd.h"
#include "MCAL/ADC/adc.h"
#include "MCAL/Keypad/Keypad.h"
#include <stdlib.h>


int main(void)
{
	/* Replace with your application code */
	//uint8_t key_pressed;
	ADC_Init();
	LCD_INIT();
	LCD_WRITE_STRING((uint8_t *)"Temp= ");
	LCD_GOTO_XY(FIRST_ROW,8);
	LCD_WRITE_CHAR('C');
	uint16_t temp;
	//LCD_CUSTOM_CHARACTER();
	KEYPAD_INIT();
	
	
	while (1)
	{
		ADC_Read(ADC_CHANNEL_0, &temp);
		temp = (temp * 150 / 308);
		char buff[16];
		itoa(temp, buff,10);
		LCD_GOTO_XY(FIRST_ROW,6);
		LCD_WRITE_STRING((uint8_t *) buff);
		//key_pressed = KEYPAD_GETCHAR();
		//switch(key_pressed){
		//case ('N'):
		//break;
		//case ('*'):
		//LCD_clear_screen();
		//break;
		//default:
		//LCD_WRITE_CHAR(key_pressed);
		//}
	}
}

