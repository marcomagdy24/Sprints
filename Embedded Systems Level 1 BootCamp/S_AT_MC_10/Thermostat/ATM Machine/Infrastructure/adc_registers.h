/*
 * uart_registers.h
 *
 * Created: 7/13/2021 10:44:35 PM
 *  Author: Marco
 */ 


#ifndef ADC_REGISTERS_H_
#define ADC_REGISTERS_H_

/******************************************************************************
*                              Includes			                          *
*******************************************************************************/
#include "types.h"

/*------------------------------ ADC REGISTERS ------------------------------*/
/* ADC Transmit / Receive Data Buffer*/
#define ADCSRA			  *((volatile uint8_t*) (0x26))

#define ADEN    (uint8_t) 7
#define ADSC    (uint8_t) 6
#define ADATE   (uint8_t) 5
#define ADIF    (uint8_t) 4
#define ADIE    (uint8_t) 3
#define ADPS2   (uint8_t) 2
#define ADPS1   (uint8_t) 1
#define ADPS0   (uint8_t) 0


/* ADC Control and Status Register A*/
#define ADMUX		     *((volatile uint8_t*) (0x27))

#define REFS1   (uint8_t) 7
#define REFS0   (uint8_t) 6
#define ADLAR   (uint8_t) 5
#define MUX4    (uint8_t) 4
#define MUX3    (uint8_t) 3
#define MUX2    (uint8_t) 2
#define MUX1    (uint8_t) 1
#define MUX0    (uint8_t) 0

#define ADCH		     *((volatile uint8_t*) (0x25))
#define ADCL		     *((volatile uint8_t*) (0x24))
#endif /* ADC_REGISTERS_H_ */