/*
 * Motor_HardwareProxy.c
 *
 * Created: 02-Sep-21 3:01:36 AM
 *  Author: Ayman
 */

 #include "Motor_HardwareProxy.h"


static void MotorProxy_marshall(STR_MotorProxy_t* MotorProxy, STR_Motor_t *MotorData);
static void MotorProxy_unmarshall(STR_MotorProxy_t* MotorProxy, STR_Motor_t *MotorData);


void MotorProxy_initialize(STR_MotorProxy_t* MotorProxy)
{
	if(MotorProxy==NULL_PTR)
	{
		return;
	}
	MotorProxy->Motor_Backwardport=NULL_PTR;
	MotorProxy->Motor_Forwardport=NULL_PTR;
	MotorProxy->Motor_ForwardPin=ZERO;
	MotorProxy->Motor_BackwardPin=ZERO;
	MotorProxy->Motor_Direction=ZERO;
	MotorProxy->Motor_Speed=ZERO;
}
void MotorProxy_configue(STR_MotorProxy_t* MotorProxy,ptr_uint8_t Motor_ForwardPortaddress,ptr_uint8_t Motor_Backwardportaddress
,uint8_t Motor_ForwardPin,uint8_t Motor_BackwardPin)
{
	if((MotorProxy==NULL_PTR)||(Motor_ForwardPortaddress==NULL_PTR)||(Motor_Backwardportaddress==NULL_PTR))
	{
		return;
	}
	else
	{
		MotorProxy->Motor_Forwardport=Motor_ForwardPortaddress;
		MotorProxy->Motor_Backwardport=Motor_Backwardportaddress;
		MotorProxy->Motor_ForwardPin=Motor_ForwardPin;
		MotorProxy->Motor_BackwardPin=Motor_BackwardPin;
		STR_Motor_t MotorData;
		MotorProxy_unmarshall(MotorProxy,&MotorData);
		DC_MotorInit(&MotorData);
	}
	

	
}
void MotorProxy_disable(STR_MotorProxy_t* MotorProxy)
{
	if(MotorProxy==NULL_PTR)
	{
		return;
	}
	MotorProxy=NULL_PTR;
}
void MotorProxy_access(STR_MotorProxy_t* MotorProxy,ptr_uint8_t Motor_Direction,ptr_uint8_t Motor_Speed)
{
	if(MotorProxy==NULL_PTR)
	{
		return;
	}
	else
	{	
		STR_Motor_t MotorData;
	 	MotorProxy_unmarshall(MotorProxy,&MotorData);
		(*Motor_Direction)=(MotorData.Motor_Direction);
		(*Motor_Speed)=(MotorData.Motor_Speed);
	}
}
void MotorProxy_mutate(STR_MotorProxy_t* MotorProxy,uint8_t Motor_Direction,uint8_t Motor_Speed)
{
	if(MotorProxy==NULL_PTR)
	{
		return;
	}
	else
	{
		STR_Motor_t MotorData;
		MotorProxy_unmarshall(MotorProxy,&MotorData);
		MotorData.Motor_Direction=Motor_Direction;
		MotorData.Motor_Speed=Motor_Speed;
		MotorProxy_marshall(MotorProxy,&MotorData);
		DC_MotorStart(&MotorData);
		
	}
	
}
void MotorProxy_unmarshall(STR_MotorProxy_t* MotorProxy, STR_Motor_t *MotorData)
{
	ptr_uint8_t ptr_data=NULL_PTR;
	if((MotorProxy==NULL_PTR)||(MotorData==NULL_PTR))
	{
		return;
	}
	else
	{
		ptr_data=(MotorProxy->Motor_Forwardport);
		if(ptr_data==&PORTA)
		{
			MotorData->Motor_Forwardport=DIO_PORTA;
		}
		else if(ptr_data==&PORTB)
		{
			MotorData->Motor_Forwardport=DIO_PORTB;
		}
		else if(ptr_data==&PORTC)
		{
			MotorData->Motor_Forwardport=DIO_PORTC;
		}
		else if(ptr_data==&PORTD)
		{
			MotorData->Motor_Forwardport=DIO_PORTD;
		}
		ptr_data=(MotorProxy->Motor_Backwardport);
		if(ptr_data==&PORTA)
		{
			MotorData->Motor_Backwardport=DIO_PORTA;
		}
		else if(ptr_data==&PORTB)
		{
			MotorData->Motor_Backwardport=DIO_PORTB;
		}
		else if(ptr_data==&PORTC)
		{
			MotorData->Motor_Backwardport=DIO_PORTC;
		}
		else if(ptr_data==&PORTD)
		{
			MotorData->Motor_Backwardport=DIO_PORTD;
		}
		MotorData->Motor_ForwardPin	  =   MotorProxy->Motor_ForwardPin;
		MotorData->Motor_BackwardPin  =   MotorProxy->Motor_BackwardPin;
		MotorData->Motor_Speed        =   MotorProxy->Motor_Speed;
		MotorData->Motor_Direction    =   MotorProxy->Motor_Direction;
		
	}

}
void MotorProxy_marshall(STR_MotorProxy_t* MotorProxy, STR_Motor_t *MotorData)
{
	uint8_t data;
	if((MotorProxy==NULL_PTR)||(MotorData==NULL_PTR))
	{
		return;
	}
	else
	{
		data=(MotorData->Motor_Forwardport);
		if(data==DIO_PORTA)
		{
			(MotorProxy->Motor_Forwardport)=&PORTA;
		}
		else if(data==DIO_PORTB)
		{
			(MotorProxy->Motor_Forwardport)=&PORTB;
		}
		else if(data==DIO_PORTC)
		{
			(MotorProxy->Motor_Forwardport)=&PORTC;
		}
		else if(data==DIO_PORTD)
		{
			(MotorProxy->Motor_Forwardport)=&PORTD;
		}
		data=(MotorData->Motor_Backwardport);
		if(data==DIO_PORTA)
		{
			(MotorProxy->Motor_Backwardport)=&PORTA;
		}
		else if(data==DIO_PORTB)
		{
			(MotorProxy->Motor_Backwardport)=&PORTB;
		}
		else if(data==DIO_PORTC)
		{
			(MotorProxy->Motor_Backwardport)=&PORTC;
		}
		else if(data==DIO_PORTD)
		{
			(MotorProxy->Motor_Backwardport)=(&PORTD);
		}
		MotorProxy->Motor_ForwardPin  = MotorData->Motor_ForwardPin;
		MotorProxy->Motor_BackwardPin = MotorData->Motor_BackwardPin;
		MotorProxy->Motor_Speed		  =	MotorData->Motor_Speed;
		MotorProxy->Motor_Direction	  = MotorData->Motor_Direction;
		
	}

}