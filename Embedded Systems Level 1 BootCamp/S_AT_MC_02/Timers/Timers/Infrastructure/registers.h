/*
* registers.h
*
* Created: 7/8/2021 6:11:30 PM
*  Author: Marco
*/


#ifndef REGISTERS_H_
#define REGISTERS_H_

/******************************************************************************
*                              Includes			                          *
*******************************************************************************/
#include "types.h"

/******************************************************************************
*                              Constants			                          *
*******************************************************************************/

/*------------------------------ PORTA REGISTERS -----------------------------*/
#define PORTA_DATA  *((volatile uint8_t*) (0x3B))
#define PORTA_DIR   *((volatile uint8_t*) (0x3A))
#define PORTA_INPUT *((volatile uint8_t*) (0x39))

/*------------------------------ PORTB REGISTERS -----------------------------*/
#define PORTB_DATA  *((volatile uint8_t*) (0x38))
#define PORTB_DIR   *((volatile uint8_t*) (0x37))
#define PORTB_INPUT *((volatile uint8_t*) (0x36))

/*------------------------------ PORTC REGISTERS -----------------------------*/
#define PORTC_DATA  *((volatile uint8_t*) (0x35))
#define PORTC_DIR   *((volatile uint8_t*) (0x34))
#define PORTC_INPUT *((volatile uint8_t*) (0x33))

/*------------------------------ PORTD REGISTERS -----------------------------*/
#define PORTD_DATA  *((volatile uint8_t*) (0x32))
#define PORTD_DIR   *((volatile uint8_t*) (0x31))
#define PORTD_INPUT *((volatile uint8_t*) (0x30))

/*------------------------------ TIMER0 REGISTERS ----------------------------*/
#define TCNT0  *((volatile uint8_t*) (0x52))
#define TCCR0  *((volatile uint8_t*) (0x53))
#define CS00  (uint8_t) 0
#define CS01  (uint8_t) 1
#define CS02  (uint8_t) 2
#define WGM01 (uint8_t) 3
#define COM00 (uint8_t) 4
#define COM01 (uint8_t) 5
#define WGM00 (uint8_t) 6
#define FOC0  (uint8_t) 7


#define TIFR   *((volatile uint8_t*) (0x58))
#define TOV0  (uint8_t) 0
#define OCF0  (uint8_t) 1


#define TIMSK  *((volatile uint8_t*) (0x59))
#define TOIE0  (uint8_t) 0
#define OCIE0  (uint8_t) 1


#define OCR0   *((volatile uint8_t*) (0x5C))


#endif /* REGISTERS_H_ */