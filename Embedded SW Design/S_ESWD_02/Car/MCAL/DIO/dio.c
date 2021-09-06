/*
* dio.c
*
* Created: 7/8/2021 6:10:54 PM
*  Author: Marco
*/

#include "dio.h"


E_STATUS DIO_Init(ST_DIO_config* configurations)
{	
	E_STATUS au8_error=E_NOK;
	if(((configurations->port <= DIO_PORTD)&&(configurations->port >= DIO_PORTA))&&
	((configurations->pin <= PIN_7) && (configurations->pin >= PIN_0)))
	{
		
		switch(configurations->port)
		{
			case DIO_PORTA:
			{
				if(configurations->dir == OUTPUT)
				{	
					SET_BIT(PORTA_DIR,configurations->pin);
					au8_error = E_OK;
				}
				else
				{
					RESET_BIT(PORTA_DIR,configurations->pin);
				}
				
				break;
			}
			case DIO_PORTB:
			{
				if(configurations->dir == OUTPUT)
				{
					SET_BIT(PORTB_DIR,configurations->pin);
				}else
				{
					RESET_BIT(PORTB_DIR,configurations->pin);
				}
				au8_error = E_OK;
				break;
			}
			case DIO_PORTC:
			{
				if(configurations->dir == OUTPUT)
				{
					SET_BIT(PORTC_DIR,configurations->pin);
				}else
				{
					RESET_BIT(PORTC_DIR,configurations->pin);
				}
				au8_error = E_OK;
				break;
			}
			case DIO_PORTD:
			{
				if(configurations->dir == OUTPUT)
				{
					SET_BIT(PORTD_DIR,configurations->pin);
				}else
				{
					RESET_BIT(PORTD_DIR,configurations->pin);
				}
				au8_error = E_OK;
				break;
			}

		}
	}
	return au8_error;
}


E_STATUS DIO_WritePIN(uint8_t port,EN_pins pin,uint8_t data)
{
	E_STATUS au8_error=E_NOK;
	if(((port <= DIO_PORTD)&&(port >= DIO_PORTA))&&
	((pin <= PIN_7)&&(pin >= PIN_0)))
	{
		au8_error = E_OK;
		switch(port)
		{
			case DIO_PORTA:
			{
				if(data == HIGH)
				{
					SET_BIT(PORTA_DATA,pin);
				}else
				{
					RESET_BIT(PORTA_DATA,pin);
				}
				break;
			}
			case DIO_PORTB:
			{
				if(data == HIGH)
				{
					SET_BIT(PORTB_DATA,pin);
				}else
				{
					RESET_BIT(PORTB_DATA,pin);
				}
				break;
			}
			case DIO_PORTC:
			{
				if(data == HIGH)
				{
					SET_BIT(PORTC_DATA,pin);
				}else
				{
					RESET_BIT(PORTC_DATA,pin);
				}
				break;
			}
			case DIO_PORTD:
			{
				if(data == HIGH)
				{
					SET_BIT(PORTD_DATA,pin);
				}else
				{
					RESET_BIT(PORTD_DATA,pin);
				}
				break;
			}

		}
	}
	return au8_error;
}


E_STATUS DIO_WritePORT(uint8_t port,uint8_t data)
{
	E_STATUS au8_error=E_NOK;
	if(((port <= DIO_PORTD) && (port >= DIO_PORTA)))
	{
		au8_error = E_OK;
		switch(port)
		{
			case DIO_PORTA:
			{
				PORTA_DATA=data;
				break;
			}
			case DIO_PORTB:
			{
				PORTB_DATA=data;
				break;
			}
			case DIO_PORTC:
			{
				PORTC_DATA=data;
				break;
			}
			case DIO_PORTD:
			{
				PORTD_DATA=data;
				break;
			}

		}
	}
	return au8_error;
}


E_STATUS DIO_ReadPIN(uint8_t port,EN_pins pin,uint8_t* data_ptr)
{
	E_STATUS au8_error=E_NOK;
	if(((port <= DIO_PORTD)||(port >= DIO_PORTA))&&
	((pin <= PIN_7)||(pin >= PIN_0)))
	{
		au8_error = E_OK;
		switch(port)
		{
			case DIO_PORTA:
			{
				*data_ptr=READ_BIT(PORTA_INPUT,pin);
				break;
			}
			case DIO_PORTB:
			{
				*data_ptr=READ_BIT(PORTB_INPUT,pin);
				break;
			}
			case DIO_PORTC:
			{
				*data_ptr=READ_BIT(PORTC_INPUT,pin);
				break;
			}
			case DIO_PORTD:
			{
				*data_ptr=READ_BIT(PORTD_INPUT,pin);
				break;
			}

		}
	}
	return au8_error;
}


E_STATUS DIO_TogglePIN(uint8_t port,EN_pins pin)
{
	E_STATUS au8_error=E_NOK;
	if(((port <= DIO_PORTD)||(port >= DIO_PORTA))&&
	((pin <= PIN_7)||(pin >= PIN_0)))
	{
		au8_error = E_OK;
		switch(port)
		{
			case DIO_PORTA:
			{
				TOGGLE_BIT(PORTA_DATA,pin);
				break;
			}
			case DIO_PORTB:
			{
				TOGGLE_BIT(PORTB_DATA,pin);
				break;
			}
			case DIO_PORTC:
			{
				TOGGLE_BIT(PORTC_DATA,pin);
				break;
			}
			case DIO_PORTD:
			{
				TOGGLE_BIT(PORTD_DATA,pin);
				break;
			}
			default:
			{
				au8_error = E_NOK;
				break;
			}
		}
	}
	return au8_error;
}
