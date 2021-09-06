

#include "DIO.h"


E_STATUS DIO_SetPinDirection(EN_PORT_t port, EN_PIN_t pin, EN_PINDIR_t dir)
{
	E_STATUS u8_State=ERROR;
	if(((port>=PortA)&&(port<=PortD))&&((pin<=PIN7)&&(pin>=PIN0))){
		u8_State=Success;
		switch(port)
		{
		case PortA:
		{
			if(dir==INPUT)
				CLEAR_BIT(DDRA,pin);
			else
				SET_BIT(DDRA,pin);
		}
		break;
		case PortB:
		{
			if(dir==INPUT)
				CLEAR_BIT(DDRB,pin);
			else
				SET_BIT(DDRB,pin);
		}
		break;
		case PortC:
		{
			if(dir==INPUT)
				CLEAR_BIT(DDRC,pin);
			else
				SET_BIT(DDRC,pin);
		}
		break;
		case PortD:
		{
			if(dir==INPUT)
				CLEAR_BIT(DDRD,pin);
			else
				SET_BIT(DDRD,pin);
		}
		break;
		}
	}
	return u8_State;
}

E_STATUS DIO_SetPortDirection(EN_PORT_t port, uint8_t dir)
{
	E_STATUS u8_State=ERROR;
	if((port>=PortA)&&(port<=PortD)){
		u8_State=Success;
		switch(port)
		{
			case PortA:
			{
				DDRA = dir;
			}
			break;
			case PortB:
			{
				DDRB = dir;
			}
			break;
			case PortC:
			{
				DDRC = dir;
			}
			break;
			case PortD:
			{
				DDRD = dir;
			}
			break;
		}
	}
	return u8_State;
}


E_STATUS DIO_TogglePin(EN_PORT_t port, EN_PIN_t pin)
{
	E_STATUS u8_State=ERROR;
	if(((port>=PortA)&&(port<=PortD))&&((pin<=PIN7)&&(pin>=PIN0))){
		u8_State=Success;
		switch(port)
		{
		case PortA:
			TOGGLE_BIT(PORTA,pin);
			break;
		case PortB:
			TOGGLE_BIT(PORTB,pin);
			break;
		case PortC:
			TOGGLE_BIT(PORTC,pin);
			break;
		case PortD:
			TOGGLE_BIT(PORTD,pin);
			break;
		}

	}
	return u8_State;
}


E_STATUS DIO_ReadPin(EN_PORT_t port, EN_PIN_t pin, EN_PINOUT_t *value)
{
	E_STATUS u8_State=ERROR;
	if(((port>=PortA)&&(port<=PortD))&&((pin<=PIN7)&&(pin>=PIN0))){
		u8_State=Success;
		switch(port)
		{
		case PortA:
			*value=Get_Bit(PORTA,pin);
			break;
		case PortB:
			*value=Get_Bit(PORTB,pin);
			break;
		case PortC:
			*value=Get_Bit(PORTC,pin);
			break;
		case PortD:
			*value=Get_Bit(PORTD,pin);
			break;
		}
	}
	return u8_State;
}


E_STATUS DIO_ReadPort(EN_PORT_t port, uint8_t * value)
{
	E_STATUS u8_State=ERROR;
	if((port>=PortA)&&(port<=PortD)){
		u8_State=Success;
		switch(port)
		{
		case PortA:
			*value=PINA;
			break;
		case PortB:
			*value=PINB;
			break;
		case PortC:
			*value=PINC;
			break;
		case PortD:
			*value=PIND;
			break;
		}
	}
	return u8_State;
}


E_STATUS DIO_WritePin(EN_PORT_t port, EN_PIN_t pin, EN_PINOUT_t data)
{
	E_STATUS u8_State=ERROR;
	if(((port>=PortA)&&(port<=PortD))&&((pin<=PIN7)&&(pin>=PIN0))){
		u8_State=Success;
		switch(port)
		{
		case PortA:
		{
			if(data==HIGH)
				SET_BIT(PORTA,pin);
			else
				CLEAR_BIT(PORTA,pin);
		}
		break;
		case PortB:
		{
			if(data==HIGH)
				SET_BIT(PORTB,pin);
			else
				CLEAR_BIT(PORTB,pin);
		}
		break;
		case PortC:
		{
			if(data==HIGH)
				SET_BIT(PORTC,pin);
			else
				CLEAR_BIT(PORTC,pin);
		}
		break;
		case PortD:
		{
			if(data==HIGH)
				SET_BIT(PORTD,pin);
			else
				CLEAR_BIT(PORTD,pin);
		}
		break;
		}
	}
	return u8_State;
}


E_STATUS DIO_WritePort(EN_PORT_t port, uint8_t data)
{
	E_STATUS u8_State=ERROR;
	if((port>=PortA)&&(port<=PortD)){
		u8_State=Success;
		switch(port)
		{
		case PortA:
			PORTA=data;
			break;
		case PortB:
			PORTB=data;
			break;
		case PortC:
			PORTC=data;
			break;
		case PortD:
			PORTD=data;
			break;
		}
	}
	return u8_State;
}

