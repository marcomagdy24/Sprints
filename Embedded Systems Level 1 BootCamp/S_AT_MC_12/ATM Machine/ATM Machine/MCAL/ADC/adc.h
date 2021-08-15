/*
 * lcd.h
 *
 * Created: 7/26/2021 8:27:58 PM
 *  Author: Marco
 */ 


#ifndef ADC_H_
#define ADC_H_

/******************************************************************************
*                              Includes													*
*******************************************************************************/
#include "../../Infrastructure/registers.h"
#include "../../Infrastructure/adc_registers.H"
#include "../../Infrastructure/utils.h"
#include "adcConfig.h"
#include "adcRetval.h"
/******************************************************************************
*                               FUNCTION DECLARATIONS                         *
*******************************************************************************/
ADC_STATUS_t ADC_Init(void);
ADC_STATUS_t ADC_Read(uint8_t u8_ADC_CH, uint16_t * u8_Data);
ADC_STATUS_t ADC_EnableInterrupt(void);
ADC_STATUS_t ADC_DisableInterrupt(void);
ADC_STATUS_t ADC_SetCallback(Ptr_VoidFuncVoid_t Callback);


#endif /* ADC_H_ */