/*
 * adcConfig.h
 *
 * Created: 7/13/2021 8:58:57 PM
 *  Author: Marco
 */ 


#ifndef ADCCONFIG_H_
#define ADCCONFIG_H_

/******************************************************************************
*                              Includes													*
*******************************************************************************/
#include "../../Infrastructure/MC_REGISTERS.h"
#include "../../Infrastructure/STD_TYPES.h"
/******************************************************************************
*                              CONSTANTS													*
*******************************************************************************/
/*------------------------------ ADC REDGISTERS -----------------------------*/
#define ADC_PORT				PORTA_DATA
#define DataDir_ADC_PORT	PORTA_DIR

/*-------------------------- ADC CHANNEL NUMBERS ---------------------------*/
#define ADC_CHANNEL_0					(uint8_t)(0x00)
#define ADC_CHANNEL_1					(uint8_t)(0x01)
#define ADC_CHANNEL_2					(uint8_t)(0x02)
#define ADC_CHANNEL_3					(uint8_t)(0x03)
#define ADC_CHANNEL_4					(uint8_t)(0x04)
#define ADC_CHANNEL_5					(uint8_t)(0x05)
#define ADC_CHANNEL_6					(uint8_t)(0x06)
#define ADC_CHANNEL_7					(uint8_t)(0x07)

/*-------------------------- ADC Prescaler Selections ---------------------------*/
#define ADC_PRESCALAR_2             (uint8_t)(0x01)
#define ADC_PRESCALAR_4             (uint8_t)(0x02)
#define ADC_PRESCALAR_8             (uint8_t)(0x03)
#define ADC_PRESCALAR_16            (uint8_t)(0x04)
#define ADC_PRESCALAR_32            (uint8_t)(0x05)
#define ADC_PRESCALAR_64            (uint8_t)(0x06)
#define ADC_PRESCALAR_128           (uint8_t)(0x07)

/*------------------------- Voltage Reference Selection -------------------------*/
#define VOLTAGE_REFERENCE_EXTERNAL  (uint8_t)(0x00)
#define VOLTAGE_REFERENCE_AVCC      (uint8_t)(0x40)
#define VOLTAGE_REFERENCE_INTERNAL  (uint8_t)(0xC0)


/*----------------------------- ADC PINS ---------------------------*/
#define ADC_START_CONVERSION			(uint8_t)(0x40)
#define ADC_ENABLE						(uint8_t)(0x80)
#define ADC_INTERRUPT_ENABLE        (uint8_t)(0X08)

/*----------------------------- ADC CONFIGS ---------------------------*/

#define ADC_PRESCALER_SELECTION			ADC_PRESCALAR_128
#define VOLTAGE_REFERENCE_SELECTION		VOLTAGE_REFERENCE_AVCC

/******************************************************************************
*                              FUNCTION-LIKE MACROS									*
*******************************************************************************/
#define BITRATE(TWSR)	((F_CPU/SCL_CLK)-16)/(2* (TWSR&((1<<TWPS0)|(1<<TWPS1))))

#endif /* ADCCONFIG_H_ */