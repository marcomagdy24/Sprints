/*
* master.c
*
* Created: 7/15/2021 1:05:37 AM
*  Author: Marco
*/

/******************************************************************************
*                              Includes													*
*******************************************************************************/
#include "thermostat.h"
/******************************************************************************
*                         LOCAL FUNCTION IMPLEMENTATION								*
*******************************************************************************/
char temp_str[2];

void displayMaximumTemp(void)
{
	LCD_clear_screen();
	LCD_GOTO_XY(SECOND_ROW,0);
	LCD_WRITE_STRING((uint8_t *)"Max Temp=   C");
	LCD_GOTO_XY(SECOND_ROW,10);
	LCD_WRITE_STRING((uint8_t *) temp_str);
}

void displayTemp(void)
{
	LCD_GOTO_XY(FIRST_ROW,0);
	LCD_WRITE_STRING((uint8_t *)"Temp=   C");
}

void getMaximumTemp(void)
{
	uint8_t key_pressed;
	uint8_t i = 0;
	LCD_WRITE_STRING((uint8_t *)"Enter the maximum temp:   C");
	LCD_GOTO_XY(SECOND_ROW,8);
	while(i < 2){
		key_pressed = KEYPAD_GETCHAR();
		switch(key_pressed){
			case ('N'):
			break;
			case ('*'):
			LCD_clear_screen();
			break;
			default:
			LCD_WRITE_CHAR(key_pressed);
			temp_str[i++] = key_pressed;
		}
	}
}
/******************************************************************************
*                         APIS IMPLEMENTATION											*
*******************************************************************************/

void THERMOSTAT_Init(void)
{
	ADC_Init();
	LCD_INIT();
	MOTOR_INIT();
	KEYPAD_INIT();
	DIO_SetPinDirection(PORT_B, PIN1, PIN_OUTPUT);
	getMaximumTemp();
	displayMaximumTemp();
	displayTemp();
}

void THERMOSTAT_Update(void)
{
	uint16_t temp;
	uint16_t max_temp;
	char buff[16];
	
	max_temp = atoi(temp_str);
	ADC_Read(ADC_CHANNEL_0, &temp);
	temp = (temp * 150 / 308);
	itoa(temp, buff,10);
	LCD_GOTO_XY(FIRST_ROW,6);
	LCD_WRITE_STRING((uint8_t *) buff);
	if (temp >= max_temp)
	{
		MOTOR_START();
	}
	else
	{
		MOTOR_STOP();
	}
	_delay_ms(100);
}

