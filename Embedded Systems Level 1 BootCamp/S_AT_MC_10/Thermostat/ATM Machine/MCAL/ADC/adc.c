/*
* adc.c
*
* Created: 7/26/2021 8:28:06 PM
*  Author: Marco
*/

/******************************************************************************
*                              Includes													*
*******************************************************************************/
#include "adc.h"
/******************************************************************************
*										GLOBAL VARIABLES											*
*******************************************************************************/
static Ptr_VoidFuncVoid_t g_Callback;
/******************************************************************************
*                         APIS IMPLEMENTATION											*
*******************************************************************************/
ADC_STATUS_t ADC_Init(void)
{
	/* Enable ADC, fr/128  */
	ADCSRA |= (ADC_ENABLE | ADC_PRESCALER_SELECTION);
	/* Vref: Avcc */
	ADMUX |= VOLTAGE_REFERENCE_SELECTION ;
	return ADC_SUCCESS;
}

ADC_STATUS_t ADC_Read(uint8_t u8_ADC_CH, uint16_t * u8_Data)
{
	/* Set input channel to read */
	if (u8_Data == NULL_PTR)
	{
		return ADC_NULL_PTR;
	}
	else if ((u8_ADC_CH > ADC_CHANNEL_7) || (u8_ADC_CH < ADC_CHANNEL_0))
	{
		return ADC_INVALID_CH;
	}
	/* Select the required ADC channel */
	
	ADMUX |= (u8_ADC_CH & 0x1F);
	/* Start conversion */
	
	ADCSRA |= ADC_START_CONVERSION;
	/* Monitor end of conversion interrupt */
	while(! (ADCSRA&(1<<ADIF)));	
	/* clear interrupt flag */
	ADCSRA |= ADIF;
	*u8_Data = (ADCL);
	*u8_Data += (ADCH << 8);
	return ADC_SUCCESS;
}

ADC_STATUS_t ADC_EnableInterrupt(void)
{
	ADCSRA |= ADC_INTERRUPT_ENABLE;
	return ADC_SUCCESS;
}

ADC_STATUS_t ADC_DisableInterrupt(void)
{
	ADCSRA &= ~(ADC_INTERRUPT_ENABLE);
	return ADC_SUCCESS;
}

ADC_STATUS_t ADC_SetCallback(Ptr_VoidFuncVoid_t Callback)
{
	if(NULL_PTR == Callback)
	{
		return ADC_NULL_PTR;
	}
	
	/* set callback function */
	g_Callback = Callback;
	return ADC_SUCCESS;
}