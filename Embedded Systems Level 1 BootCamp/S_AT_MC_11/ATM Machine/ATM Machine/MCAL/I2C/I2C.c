/*
* uart.c
*
* Created: 7/13/2021 8:58:32 PM
*  Author: Marco
*/

/******************************************************************************
*                              Includes													*
*******************************************************************************/
#include "I2C.h"

/******************************************************************************
*                         GLOBAL STATIC VARIABLES										*
*******************************************************************************/
static Ptr_VoidFuncVoid_t g_Callback[I2C_CHANNELS];
static volatile uint8_t * gvpu8_I2C_Control_R;
static volatile uint8_t * gvpu8_I2C_Data_R;
static volatile uint8_t * gvpu8_I2C_Status_R;
static volatile uint8_t * gvpu8_I2C_BitRate_R;
static volatile uint8_t * gvpu8_I2C_Slave_ADDR;
/******************************************************************************
*                         LOCAL FUNCTIONS IMPLEMENTATION								*
*******************************************************************************/

I2C_STATUS_t I2C_InitRegisters(uint8_t u8_I2C_CH)
{
	switch(u8_I2C_CH)
	{
		case I2C_CH_0:
			gvpu8_I2C_Data_R = &TWDR;
			gvpu8_I2C_Control_R = &TWCR;
			gvpu8_I2C_Status_R = &TWSR;
			gvpu8_I2C_BitRate_R = &TWBR;
			gvpu8_I2C_Slave_ADDR = &TWAR;
			break;
		default:
			return I2C_INVALID_CH;
	}
	return I2C_SUCCESS;
}

/******************************************************************************
*                         APIS IMPLEMENTATION											*
*******************************************************************************/
I2C_STATUS_t I2C_Init(uint8_t u8_I2C_CH)
{
	I2C_InitRegisters(u8_I2C_CH);
	/* set prescaler value */
	*gvpu8_I2C_Status_R = I2C_CH_0_PRESCALER;

	/* set bit rate */
	*gvpu8_I2C_BitRate_R = I2C_CH_0_BIT_RATE;

	/* set control configuration */
	*gvpu8_I2C_Control_R = I2C_CH_0_CONTROL_MASK;
	
	/* return success macro */
	return I2C_SUCCESS;
}

I2C_STATUS_t I2C_SetSlaveAddress(uint8_t u8_I2C_CH, uint8_t u8_SlaveADDR)
{
	/* Initialize registers */
	I2C_InitRegisters(u8_I2C_CH);
	
	/* Set slave address */
	*gvpu8_I2C_Slave_ADDR = u8_SlaveADDR;
	/* return success macro */
	return I2C_SUCCESS;
}

I2C_STATUS_t I2C_Start(uint8_t u8_I2C_CH)
{
	/* Declare status variable */
	uint8_t status;
	/* Initialize registers */
	I2C_InitRegisters(u8_I2C_CH);
	/* Enable TWI, generate START */
	*gvpu8_I2C_Control_R = (I2C_START_BIT | I2C_EN | I2C_INTERRUPT_FLAG);
	/* Wait until TWI finish its current job */
	// while (!(*gvpu8_I2C_Control_R & I2C_INTERRUPT_FLAG));
	while (! (READ_BIT(*gvpu8_I2C_Control_R, TWINT)));
	/* Read TWI status register */
	status = *gvpu8_I2C_Status_R & I2C_STATUS_BITS;
	/* Wait until START transmitted*/
	while(status != I2C_STATUS_START);
	/* return success macro */
	return I2C_SUCCESS;
}

I2C_STATUS_t I2C_RepeatedStart(uint8_t u8_I2C_CH)
{
	/* Declare status variable */
	uint8_t status;
	/* Initialize registers */
	I2C_InitRegisters(u8_I2C_CH);
	/* Enable TWI, generate START */
	*gvpu8_I2C_Control_R = (I2C_START_BIT | I2C_EN | I2C_INTERRUPT_FLAG);
	/* Wait until TWI finish its current job */
	// while (!(*gvpu8_I2C_Control_R & I2C_INTERRUPT_FLAG));
	while (!(*gvpu8_I2C_Control_R & I2C_INTERRUPT_FLAG));
	/* Read TWI status register */
	status = *gvpu8_I2C_Status_R & I2C_STATUS_BITS;
	/* Wait until Repeat START transmitted*/
	while(status != I2C_STATUS_REPEATED_START);
	/* return success macro */
	return I2C_SUCCESS;
}

I2C_STATUS_t I2C_Stop(uint8_t u8_I2C_CH)
{
	/* Initialize registers */
	I2C_InitRegisters(u8_I2C_CH);
	/* Enable TWI, generate STOP */
	*gvpu8_I2C_Control_R = (I2C_STOP_BIT | I2C_EN | I2C_INTERRUPT_FLAG);
	/* Wait until TWI stop */
	while (READ_BIT(*gvpu8_I2C_Control_R, TWSTO));
	/* return success macro */
	return I2C_SUCCESS;
}

I2C_STATUS_t I2C_Write(uint8_t u8_I2C_CH, uint8_t u8_Data)
{
	/* Declare status variable */
	/* Initialize registers */
	I2C_InitRegisters(u8_I2C_CH);
	/* Copy data in TWI data register */
	*gvpu8_I2C_Data_R = u8_Data;
	/* Enable TWI and clear interrupt flag */
	*gvpu8_I2C_Control_R = (I2C_EN | I2C_INTERRUPT_FLAG);
	/* Read TWI status register */
	while (!(*gvpu8_I2C_Control_R & I2C_INTERRUPT_FLAG));
	/* return success macro */
	return I2C_SUCCESS;
}

I2C_STATUS_t I2C_ReadAck(uint8_t u8_I2C_CH, uint8_t * pu8_Data)
{
	/* Initialize registers */
	I2C_InitRegisters(u8_I2C_CH);
	/* Enable TWI, Ack and clear interrupt flag */
	*gvpu8_I2C_Control_R = (I2C_EN | I2C_INTERRUPT_FLAG | I2C_ACK_EN);
	/* Wait until TWI finish its current job */
	while (!(*gvpu8_I2C_Control_R & I2C_INTERRUPT_FLAG));
	/* Copy data in TWI data register */
	*pu8_Data = *gvpu8_I2C_Data_R;
	/* return success macro */
	return I2C_SUCCESS;
}

I2C_STATUS_t I2C_ReadNotAck(uint8_t u8_I2C_CH, uint8_t * pu8_Data)
{
	/* Initialize registers */
	I2C_InitRegisters(u8_I2C_CH);
	/* Enable TWI, Ack and clear interrupt flag */
	*gvpu8_I2C_Control_R |= (I2C_EN | I2C_INTERRUPT_FLAG);
	/* Wait until TWI finish its current job */
	while (!(*gvpu8_I2C_Control_R & I2C_INTERRUPT_FLAG));
	/* Copy data in TWI data register */
	*pu8_Data = *gvpu8_I2C_Data_R;
	/* return success macro */
	return I2C_SUCCESS;
}

I2C_STATUS_t I2C_GetStatus(uint8_t u8_I2C_CH, uint8_t * pu8_Status)
{
	/* check the pointer before using it */
	if(pu8_Status == NULL_PTR)
	{
		return I2C_NULL_PTR;
	}
	
	/* Initialize registers */
	I2C_InitRegisters(u8_I2C_CH);
	
	/* Copy data in TWI status register */
	*pu8_Status = (*gvpu8_I2C_Status_R & I2C_STATUS_BITS);
	
	/* return success macro */
	return I2C_SUCCESS;
}

I2C_STATUS_t I2C_EnableInterrupt(uint8_t u8_I2C_CH)
{
	/* Initialize registers */
	I2C_InitRegisters(u8_I2C_CH);
	/* enable interrupt */
	*gvpu8_I2C_Control_R |= I2C_INTERRUPT_EN;
	/* return success macro */
	return I2C_SUCCESS;
}

I2C_STATUS_t I2C_DisableInterrupt(uint8_t u8_I2C_CH)
{
	/* Initialize registers */
	I2C_InitRegisters(u8_I2C_CH);
	/* enable interrupt */
	*gvpu8_I2C_Control_R &= ~(I2C_INTERRUPT_EN);
	/* return success macro */
	return I2C_SUCCESS;
}

I2C_STATUS_t I2C_SetCallback(uint8_t u8_I2C_CH, Ptr_VoidFuncVoid_t Callback)
{
	if(Callback == NULL_PTR)
	{
		return I2C_NULL_PTR;
	}
	 volatile uint8_t u8_I2C_Index;
	 switch(u8_I2C_CH)
	 {
		 case I2C_CH_0:
			 u8_I2C_Index = I2C_CH_0;
			 break;
		 default:
			return I2C_INVALID_CH;
	 }
	 g_Callback[u8_I2C_Index] = Callback;
	 
	 /* return success macro */
	 return I2C_SUCCESS;
}
