/*
* lcd.c
*
* Created: 7/26/2021 8:28:06 PM
*  Author: Marco
*/

/******************************************************************************
*                              INCLUDES										  *
*******************************************************************************/
#include "lcd.h"

/******************************************************************************
*                              LOCAL MACROS									  *
*******************************************************************************/
#define MAX_CHAR_INT							(uint8_t)(10)

/*---------------------------- LCD COMMANDS ---------------------------*/
#define LCD_FUNCTION_8BIT_2LINES   				(uint8_t)(0x38)
#define LCD_FUNCTION_4BIT_2LINES   				(uint8_t)(0x28)
#define LCD_MOVE_DISP_RIGHT       				(uint8_t)(0x1C)
#define LCD_MOVE_DISP_LEFT   					(uint8_t)(0x18)
#define LCD_MOVE_CURSOR_RIGHT   				(uint8_t)(0x14)
#define LCD_MOVE_CURSOR_LEFT 	  				(uint8_t)(0x10)
#define LCD_DISP_OFF   							(uint8_t)(0x08)
#define LCD_DISP_ON_CURSOR   					(uint8_t)(0x0E)
#define LCD_DISP_ON_CURSOR_BLINK   				(uint8_t)(0x0F)
#define LCD_DISP_ON_BLINK   					(uint8_t)(0x0D)
#define LCD_DISP_ON   							(uint8_t)(0x0C)
#define LCD_ENTRY_DEC							(uint8_t)(0x04)
#define LCD_ENTRY_DEC_SHIFT   					(uint8_t)(0x05)
#define LCD_ENTRY_INC_   						(uint8_t)(0x06)
#define LCD_ENTRY_INC_SHIFT   					(uint8_t)(0x07)
#define LCD_BEGIN_AT_FIRST_ROW					(uint8_t)(0x80)
#define LCD_BEGIN_AT_SECOND_ROW					(uint8_t)(0xC0)
#define LCD_CLEAR_SCREEN						(uint8_t)(0x01)
#define LCD_ENTRY_MODE							(uint8_t)(0x06)

/*---------------------------- LCD STATES ---------------------------*/
#define STATE_LCD_PIN_INITIALIZATION			(1)
/******************************************************************************
*                              FUNCTION-LIKE MACROS							  *
*******************************************************************************/
#define BITRATE(TWSR)	((F_CPU/SCL_CLK)-16)/(2* (TWSR&((1<<TWPS0)|(1<<TWPS1))))

/******************************************************************************
*						GLOBAL EXTERN VARIABLES								  *
*******************************************************************************/
extern ST_LCD_ConfigPINS gext_LCDConfig[];

/******************************************************************************
*                         LOCAL FUNCTIONS IMPLEMENTATION					  *
*******************************************************************************/
void WRITE_ZERO(uint8_t PIN)
{
	DIO_WritePIN(gext_LCDConfig[PIN].port, gext_LCDConfig[PIN].pin, LOW);
}

void WRITE_ONE(uint8_t PIN)
{
	DIO_WritePIN(gext_LCDConfig[PIN].port, gext_LCDConfig[PIN].pin, HIGH);
}

void LCD_KICK(){
	WRITE_ZERO(EN_SWITCH);
	#if !TEST
	_delay_us(1);
	#endif
	WRITE_ONE(EN_SWITCH);
}



/******************************************************************************
*								LOCAL MACROS								  *
*******************************************************************************/
//0:8bit data mode | 4:4bit data mode
#if LCD_MODE == EIGHT_BIT_MODE
#define DATA_SHIFT (uint8_t) (0)
#elif LCD_MODE == FOUR_BIT_MODE
#define DATA_SHIFT (uint8_t) (4)
#endif

#define PIN_CONFIG(PIN)			gext_LCDConfig[PIN]


/******************************************************************************
*                         APIS IMPLEMENTATION								  *
*******************************************************************************/
E_STATUS LCD_INIT(void)
{
	#if !TEST
	_delay_us(900);
	#endif

	for(uint8_t au8_IterationNo=0;au8_IterationNo<LCD_PINS_NUMBER;au8_IterationNo++)
	{
		configs.port = gext_LCDConfig[au8_IterationNo].port;
		configs.pin	 = gext_LCDConfig[au8_IterationNo].pin;
		configs.dir  = gext_LCDConfig[au8_IterationNo].dir;
		DIO_Init(&configs);
	}

	#if !TEST
	_delay_us(900);
	#endif
	LCD_clear_screen ();
	
	#if LCD_MODE == EIGHT_BIT_MODE
	DIO_WritePORT(DataDir_LCD_PORT, 0xFF);
	LCD_WRITE_COMMAND(LCD_FUNCTION_8BIT_2LINES);
	
	#elif LCD_MODE == FOUR_BIT_MODE
	LCD_WRITE_COMMAND(0x02);
	LCD_WRITE_COMMAND(LCD_FUNCTION_4BIT_2LINES);
	#endif

	LCD_WRITE_COMMAND(LCD_ENTRY_MODE);
	LCD_GOTO_XY(FIRST_ROW, 0);
	LCD_WRITE_COMMAND(LCD_DISP_ON);
	#if !TEST
	_delay_us(900);
	#endif
	LCD_clear_screen();
	return E_OK;
}

E_STATUS LCD_clear_screen ()
{
	LCD_WRITE_COMMAND(LCD_CLEAR_SCREEN); // clear the screen
	return E_OK;
}

E_STATUS LCD_GOTO_XY(uint8_t line, uint8_t position)
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
		else 
		{
			return E_NOK;
		}
	}
	else 
	{
		return E_NOK;
	}
	return E_OK;
}


E_STATUS LCD_WRITE_COMMAND(uint8_t command)
{
	#if LCD_MODE == EIGHT_BIT_MODE
	LCD_PORT = command;
	WRITE_ZERO(RS_SWITCH);
	WRITE_ZERO(RW_SWITCH);
	#if !TEST
	_delay_us(1);
	#endif
	LCD_KICK ();
	#elif LCD_MODE == FOUR_BIT_MODE
	DIO_WritePIN(gext_LCDConfig[DATA_4].port,gext_LCDConfig[DATA_4].pin,BIT_GET(command,4));
	DIO_WritePIN(gext_LCDConfig[DATA_5].port,gext_LCDConfig[DATA_5].pin,BIT_GET(command,5));
	DIO_WritePIN(gext_LCDConfig[DATA_6].port,gext_LCDConfig[DATA_6].pin,BIT_GET(command,6));
	DIO_WritePIN(gext_LCDConfig[DATA_7].port,gext_LCDConfig[DATA_7].pin,BIT_GET(command,7));
	WRITE_ZERO(RS_SWITCH);
	WRITE_ZERO(RW_SWITCH);
	LCD_KICK ();
	DIO_WritePIN(gext_LCDConfig[DATA_4].port,gext_LCDConfig[DATA_4].pin,BIT_GET(command,0));
	DIO_WritePIN(gext_LCDConfig[DATA_5].port,gext_LCDConfig[DATA_5].pin,BIT_GET(command,1));
	DIO_WritePIN(gext_LCDConfig[DATA_6].port,gext_LCDConfig[DATA_6].pin,BIT_GET(command,2));
	DIO_WritePIN(gext_LCDConfig[DATA_7].port,gext_LCDConfig[DATA_7].pin,BIT_GET(command,3));
	WRITE_ZERO(RS_SWITCH);
	WRITE_ZERO(RW_SWITCH);
	LCD_KICK ();
	#endif
	return E_OK;

}

E_STATUS LCD_WRITE_CHAR(uint8_t data)
{
	#if LCD_MODE == EIGHT_BIT_MODE
	WRITE_ONE(RS_SWITCH); //turn RS ON for Data mode.
	LCD_PORT = (((data) << DATA_SHIFT));
	WRITE_ZERO(RW_SWITCH);//turn RW off so you can write.
	#if !TEST
	_delay_us(1);
	#endif
	LCD_KICK ();
	#elif LCD_MODE == FOUR_BIT_MODE
	DIO_WritePIN(gext_LCDConfig[DATA_4].port,gext_LCDConfig[DATA_4].pin,BIT_GET(data,4));
	DIO_WritePIN(gext_LCDConfig[DATA_5].port,gext_LCDConfig[DATA_5].pin,BIT_GET(data,5));
	DIO_WritePIN(gext_LCDConfig[DATA_6].port,gext_LCDConfig[DATA_6].pin,BIT_GET(data,6));
	DIO_WritePIN(gext_LCDConfig[DATA_7].port,gext_LCDConfig[DATA_7].pin,BIT_GET(data,7));
	//turn RS ON for Data mode.
	WRITE_ONE(RS_SWITCH);
	//turn RW off so you can write.
	WRITE_ZERO(RW_SWITCH);
	LCD_KICK ();
	DIO_WritePIN(gext_LCDConfig[DATA_4].port,gext_LCDConfig[DATA_4].pin,BIT_GET(data,0));
	DIO_WritePIN(gext_LCDConfig[DATA_5].port,gext_LCDConfig[DATA_5].pin,BIT_GET(data,1));
	DIO_WritePIN(gext_LCDConfig[DATA_6].port,gext_LCDConfig[DATA_6].pin,BIT_GET(data,2));
	DIO_WritePIN(gext_LCDConfig[DATA_7].port,gext_LCDConfig[DATA_7].pin,BIT_GET(data,3));
	//turn RS ON for Data mode.
	WRITE_ONE(RS_SWITCH);
	//turn RW off so you can write.
	WRITE_ZERO(RW_SWITCH);
	LCD_KICK ();
	#endif

	return E_OK;
}

E_STATUS LCD_WRITE_STRING(uint8_t *data)
{
	if (NULL_PTR == data)
	{
		return E_NOK;
	}

	/* To count how much char on the line (it should be 16 char only) */
	uint8_t count = LCD_BEGIN;
	while((*data > LCD_BEGIN))
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
	return E_OK;
}

E_STATUS LCD_WRITE_NUMBER(float32_t data)
{
	if (0 == data)
	{
		LCD_WRITE_CHAR(0x30);
	}
	else if ((data < 3.402823E+38) && (data > 0))
	{
		uint8_t lcd_display[MAX_CHAR_INT];
		ftos(data, lcd_display, 0);
		LCD_WRITE_STRING(lcd_display);
	}
	else
	{
		return E_NOK;
	}
	return E_OK;
}

E_STATUS LCD_CUSTOM_CHARACTER()
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
	#if !TEST
	_delay_us(1);
	#endif
	
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
	#if !TEST
	_delay_us(1);
	#endif
	
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
	#if !TEST
	_delay_us(1);
	#endif
	
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
	#if !TEST
	_delay_us(1);
	#endif
	
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
	#if !TEST
	_delay_us(1);
	#endif
	
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
	#if !TEST
	_delay_us(1);
	#endif
	
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
	#if !TEST
	_delay_us(1);
	#endif
	
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
	#if !TEST
	_delay_us(1);
	#endif
	
	return E_OK;
}


