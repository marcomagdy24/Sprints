/*
* lcd.c
*
* Created: 7/26/2021 8:28:06 PM
*  Author: Marco
*/

/******************************************************************************
*                              Includes													*
*******************************************************************************/
#include "lcd.h"
/******************************************************************************
*                         LOCAL FUNCTIONS IMPLEMENTATION								*
*******************************************************************************/
void LCD_KICK(){
	LCD_CTRL &= ~(1<<EN_SWITCH);
	_delay_ms(50);
	LCD_CTRL |= 1<<EN_SWITCH;
}

/******************************************************************************
*                         APIS IMPLEMENTATION											*
*******************************************************************************/
void LCD_INIT(void)
{

	_delay_ms(20);
	DataDir_LCD_CTRL |= (1<<EN_SWITCH | 1<<RW_SWITCH | 1<<RS_SWITCH) ;
	LCD_CTRL &= ~(1<<EN_SWITCH | 1<<RW_SWITCH | 1<<RS_SWITCH) ;

	DataDir_LCD_PORT = 0xff ;
	_delay_ms(15);

	LCD_clear_screen ();

	#ifdef EIGHT_BIT_MODE
	LCD_WRITE_COMMAND(LCD_FUNCTION_8BIT_2LINES);

	#endif
	#ifdef FOUR_BIT_MODE
	LCD_WRITE_COMMAND(0x02);

	LCD_WRITE_COMMAND(LCD_FUNCTION_4BIT_2LINES);

	#endif

	LCD_WRITE_COMMAND(LCD_ENTRY_MODE);
	LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW);
	LCD_WRITE_COMMAND(LCD_DISP_ON_CURSOR_BLINK);

}

void LCD_clear_screen ()
{
	LCD_WRITE_COMMAND(LCD_CLEAR_SCREEN); // clear the screen
}

void LCD_GOTO_XY(uint8_t line, uint8_t position)
{
	if ((position < LCD_END) && (position >=LCD_BEGIN))
	{
		if(line == FIRST_ROW)
		{
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW + position);
		}
		else if(line == SECOND_ROW)
		{
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_SECOND_ROW + position);
		}
	}
}


void LCD_isbusy()
{
	DataDir_LCD_PORT &= ~(0xff<<DATA_SHIFT) ;
	LCD_CTRL |= (1<<RW_SWITCH); // read
	LCD_CTRL &= ~ (1<<RS_SWITCH);
	LCD_KICK ();
	DataDir_LCD_PORT = 0xFF; //0xFF means 0b11111111
	LCD_CTRL &= ~ (1<<RW_SWITCH); //write
}


void LCD_WRITE_COMMAND(uint8_t command)
{
	#ifdef EIGHT_BIT_MODE
	LCD_isbusy();

	LCD_PORT = command  ;
	LCD_CTRL &= ~ ((1<<RW_SWITCH)|(1<<RS_SWITCH));
	_delay_ms(1);
	LCD_KICK ();
	//LCD_PORT = 0;
	#endif
	#ifdef FOUR_BIT_MODE
	//LCD_isbusy();
	LCD_PORT = (LCD_PORT & 0x0F) | (command & 0xF0);
	//LCD_VoidLcd_waitIfBusy();
	//SET_DATA_DIRECTION_REGISTER(LCD_DATA_DIRECTION_PORT, PORT_OUTPUT_DIRECTION);
	//LCD_SET_REGISTER_SELECT(LCD_REGISTER_SELECT_DISABLE);
	//	LCD_SET_READ_WRITE(WRITE_TO_LCD);
	LCD_CTRL &= ~ ((1<<RW_SWITCH)|(1<<RS_SWITCH));
	//LCD_VoidLcd_referish();
	LCD_KICK ();
	LCD_PORT = (LCD_PORT & 0x0F) | (command << 4);
	//LCD_VoidLcd_waitIfBusy();
	LCD_CTRL &= ~ ((1<<RW_SWITCH)|(1<<RS_SWITCH));
	//LCD_VoidLcd_referish();
	LCD_KICK ();
	#endif

}


void LCD_WRITE_CHAR(uint8_t data)
{

	#ifdef EIGHT_BIT_MODE
	LCD_isbusy();

	LCD_CTRL |= 1<<RS_SWITCH; //turn RS ON for Data mode.
	LCD_PORT = (((data) << DATA_SHIFT));
	LCD_CTRL &= ~ (1<<RW_SWITCH);//turn RW off so you can write.

	_delay_ms(1);

	LCD_KICK ();
	//LCD_PORT = 0;
	#endif

	#ifdef FOUR_BIT_MODE
	LCD_PORT = (LCD_PORT & 0x0F) | (data & 0xF0);
	LCD_CTRL |= 1<<RS_SWITCH; //turn RS ON for Data mode.
	LCD_CTRL &= ~ (1<<RW_SWITCH);//turn RW off so you can write.
	LCD_KICK ();
	LCD_PORT = (LCD_PORT & 0x0F) | (data << 4);
	LCD_CTRL |= 1<<RS_SWITCH; //turn RS ON for Data mode.
	LCD_CTRL &= ~ (1<<RW_SWITCH);//turn RW off so you can write.
	LCD_KICK ();

	#endif


}

void LCD_WRITE_STRING(uint8_t *data)
{

	/* To count how much uint8_t on the line (it should be 16 uint8_t only) */
	uint8_t count = LCD_BEGIN ;
	while(*data > LCD_BEGIN)
	{
		count++;
		LCD_WRITE_CHAR(*data++);
		if (count == FIRST_ROW_LIMIT) // go to the second line
		{
			LCD_GOTO_XY(SECOND_ROW, LCD_BEGIN); //Second line position zero
		}
		else if ((count == SECOND_ROW_LIMIT) || (count == SECOND_ROW_LIMIT + 1)) // clear screen and show again
		{
			LCD_clear_screen();
			LCD_GOTO_XY(FIRST_ROW,LCD_BEGIN); //First Line position zero
			count = LCD_BEGIN ;
		}
	}
}



void LCD_CUSTOM_CHARACTER()
{
	LCD_WRITE_COMMAND(64);  // Address where customized uint8_tacter is to be stored
	LCD_WRITE_CHAR(0);
	LCD_WRITE_CHAR(14);
	LCD_WRITE_CHAR(17);
	LCD_WRITE_CHAR(2);
	LCD_WRITE_CHAR(4);
	LCD_WRITE_CHAR(4);
	LCD_WRITE_CHAR(0);
	LCD_WRITE_CHAR(4);
	LCD_WRITE_COMMAND(FIRST_ROW);  // Location of LCD where the uint8_tacter is to be displayed
	LCD_WRITE_CHAR(0);  // Displaying the uint8_tacter created at address 0x64
	_delay_ms(10);
	
	LCD_WRITE_COMMAND(72);  // Address where customized uint8_tacter is to be stored
	LCD_WRITE_CHAR(0);
	LCD_WRITE_CHAR(10);
	LCD_WRITE_CHAR(21);
	LCD_WRITE_CHAR(17);
	LCD_WRITE_CHAR(18);
	LCD_WRITE_CHAR(4);
	LCD_WRITE_CHAR(0);
	LCD_WRITE_CHAR(0);
	LCD_WRITE_COMMAND(0x82);  // Location of LCD where the uint8_tacter is to be displayed
	LCD_WRITE_CHAR(1);  // Displaying the uint8_tacter created at address 0x72
	_delay_ms(10);
	
	LCD_WRITE_COMMAND(80);  //Address where customized uint8_tacter is to be stored
	LCD_WRITE_CHAR(0);
	LCD_WRITE_CHAR(0);
	LCD_WRITE_CHAR(10);
	LCD_WRITE_CHAR(0);
	LCD_WRITE_CHAR(4);
	LCD_WRITE_CHAR(0);
	LCD_WRITE_CHAR(14);
	LCD_WRITE_CHAR(17);
	LCD_WRITE_COMMAND(0x84);  // Location of LCD where the uint8_tacter is to be displayed
	LCD_WRITE_CHAR(2);  // Displaying the uint8_tacter created at address 0x80
	_delay_ms(10);
	
	LCD_WRITE_COMMAND(88);  //Address where customized uint8_tacter is to be stored
	LCD_WRITE_CHAR(1);
	LCD_WRITE_CHAR(3);
	LCD_WRITE_CHAR(5);
	LCD_WRITE_CHAR(9);
	LCD_WRITE_CHAR(9);
	LCD_WRITE_CHAR(11);
	LCD_WRITE_CHAR(27);
	LCD_WRITE_CHAR(24);
	LCD_WRITE_COMMAND(0x86);  // Location of LCD where the uint8_tacter is to be displayed
	LCD_WRITE_CHAR(3);  // Displaying the uint8_tacter created at address 0x88
	_delay_ms(10);
	
	LCD_WRITE_COMMAND(96);  // Address where customized uint8_tacter is to be stored
	LCD_WRITE_CHAR(0);
	LCD_WRITE_CHAR(0);
	LCD_WRITE_CHAR(0);
	LCD_WRITE_CHAR(4);
	LCD_WRITE_CHAR(0);
	LCD_WRITE_CHAR(31);
	LCD_WRITE_CHAR(0);
	LCD_WRITE_COMMAND(0xC0);  // location where the uint8_tacter is to be displayed
	LCD_WRITE_CHAR(4);  // Display the uint8_tacter created at address 0x96
	_delay_ms(10);
	
	LCD_WRITE_COMMAND(104);  //Address where customized uint8_tacter is stored
	LCD_WRITE_CHAR(0);
	LCD_WRITE_CHAR(17);
	LCD_WRITE_CHAR(10);
	LCD_WRITE_CHAR(17);
	LCD_WRITE_CHAR(4);
	LCD_WRITE_CHAR(0);
	LCD_WRITE_CHAR(14);
	LCD_WRITE_CHAR(17);
	LCD_WRITE_COMMAND(0xC2);  // Location of LCD where the uint8_tacter is to be displayed
	LCD_WRITE_CHAR(5);  // Display the uint8_tacter created at address 0x104
	_delay_ms(10);
	
	LCD_WRITE_COMMAND(112);  // Address where customized uint8_tacter is to be stored
	LCD_WRITE_CHAR(0);
	LCD_WRITE_CHAR(14);
	LCD_WRITE_CHAR(17);
	LCD_WRITE_CHAR(2);
	LCD_WRITE_CHAR(4);
	LCD_WRITE_CHAR(4);
	LCD_WRITE_CHAR(0);
	LCD_WRITE_CHAR(4);
	LCD_WRITE_COMMAND(0xC4);  // Location of LCD where the uint8_tacter is to be displayed
	LCD_WRITE_CHAR(6);   // Display the uint8_tacter created at address 0x112
	_delay_ms(10);
	
	LCD_WRITE_COMMAND(120);  // Address where customized uint8_tacter is to be stored
	LCD_WRITE_CHAR(10);
	LCD_WRITE_CHAR(0);
	LCD_WRITE_CHAR(4);
	LCD_WRITE_CHAR(0);
	LCD_WRITE_CHAR(14);
	LCD_WRITE_CHAR(17);
	LCD_WRITE_CHAR(17);
	LCD_WRITE_CHAR(14);
	LCD_WRITE_COMMAND(0xC6);  // Location of LCD where the uint8_tacter is to be displayed
	LCD_WRITE_CHAR(7);   // Display the uint8_tacter created at address 0x120
	_delay_ms(10);
}


