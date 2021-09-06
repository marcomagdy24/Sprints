/*
* registers.h
*
* Created: 7/8/2021 6:11:30 PM
*  Author: Marco
*/


#ifndef REGISTERS_H_
#define REGISTERS_H_

/******************************************************************************
*                              INCLUDES			                          *
*******************************************************************************/
#include "types.h"

/******************************************************************************
*                              Constants			                          *
*******************************************************************************/
#define  TEST 0
#if !TEST
	/*------------------------------ PORTA REGISTERS -----------------------------*/
	#define PORTA_DATA  *((volatile uint8_t*) (0x3B))
	#define PORTA_DIR   *((volatile uint8_t*) (0x3A))
	#define PORTA_INPUT *((volatile uint8_t*) (0x39))

	#define PORTA  *((volatile uint8_t*) (0x3B))
	#define DDRA   *((volatile uint8_t*) (0x3A))
	#define PINA   *((volatile uint8_t*) (0x39))

	/*------------------------------ PORTB REGISTERS -----------------------------*/
	#define PORTB_DATA  *((volatile uint8_t*) (0x38))
	#define PORTB_DIR   *((volatile uint8_t*) (0x37))
	#define PORTB_INPUT *((volatile uint8_t*) (0x36))

	#define PORTB  *((volatile uint8_t*) (0x38))
	#define DDRB   *((volatile uint8_t*) (0x37))
	#define PINB   *((volatile uint8_t*) (0x36))

	/*------------------------------ PORTC REGISTERS -----------------------------*/
	#define PORTC_DATA  *((volatile uint8_t*) (0x35))
	#define PORTC_DIR   *((volatile uint8_t*) (0x34))
	#define PORTC_INPUT *((volatile uint8_t*) (0x33))

	#define PORTC  *((volatile uint8_t*) (0x35))
	#define DDRC   *((volatile uint8_t*) (0x34))
	#define PINC	*((volatile uint8_t*) (0x33))

	/*------------------------------ PORTD REGISTERS -----------------------------*/
	#define PORTD_DATA  *((volatile uint8_t*) (0x32))
	#define PORTD_DIR   *((volatile uint8_t*) (0x31))
	#define PORTD_INPUT *((volatile uint8_t*) (0x30))

	#define PORTD  *((volatile uint8_t*) (0x32))
	#define DDRD   *((volatile uint8_t*) (0x31))
	#define PIND   *((volatile uint8_t*) (0x30))
	
	/*------------------------------ TIMER0 REGISTERS ----------------------------*/
	/*----------------------------- Output Compare Register ----------------------*/
	#define OCR0		*((volatile uint8_t*) (0x5C))
	/*----------------------------- Timer/Counter Register -----------------------*/
	#define TCNT0		*((volatile uint8_t*) (0x52))
	/*----------------------- Timer/Counter Control Register ---------------------*/
	#define TCCR0		*((volatile uint8_t*) (0x53))
	/*------------------ Timer/Counter Interrupt Flag Register -------------------*/
	#define	TOV0 		(uint8_t) (0)		/* Timer/Counter0 Overflow Flag */
	#define	OCF0 		(uint8_t) (1)		/* Output Compare Flag 0 */
	/*------------------ Timer/Counter Interrupt Mask Register -------------------*/
	#define	TOIE0 		(uint8_t) (0)		/* Timer/CounterTimer/Counter0 Overflow Interrupt Enable */
	#define	OCIE0 		(uint8_t) (1)		/* Timer/CounterTimer/Counter0 Output Compare Match Interrupt Enable */


	/*------------------------------ TIMER1 REGISTERS ----------------------------*/
	#define TIMSK	*((volatile uint8_t*)0x59)
	#define TIFR	*((volatile uint8_t*)0x58)
	#define TOIE1   2	/*bit2 in TIMSK register */
	/******************************************/
	#define TCCR1A	*((volatile uint8_t*)0x4F)

	#define TCCR1B	*((volatile uint8_t*)0x4E)

	#define TCNT1   *((volatile uint16_t*)0x4C)
	#define TCNT1L  *((volatile uint8_t*)0x4C)
	#define TCNT1H  *((volatile uint8_t*)0x4D)

	#define OCR1A	*((volatile uint16_t*)0x4A)
	#define OCR1AL	*((volatile uint8_t*)0x4A)
	#define OCR1AH	*((volatile uint8_t*)0x4B)
	#define OCR1B  *( ( volatile uint16_t* ) 0x48 )
	#define OCR1BH *( ( volatile uint8_t* ) 0x49 )
	#define OCR1BL *( ( volatile uint8_t* ) 0x48 )
	#define ICR1   *( ( volatile uint16_t* ) 0x46 )
	#define ICR1H  *( ( volatile uint8_t* ) 0x47 )
	#define ICR1L  *( ( volatile uint8_t* ) 0x46 )


	/*------------------------------ TIMER2 REGISTERS ----------------------------*/
	/*------------------------ Asynchronous Status Register ----------------------*/
	#define ASSR		*((volatile uint8_t*) (0x42))
	#define	TCR2UB 		(uint8_t) (0)		/* Timer/Counter Control Register2 Update Busy */
	#define	OCR2UB 		(uint8_t) (1)		/* Output Compare Register2 Update Busy */
	#define	TCN2UB 		(uint8_t) (2)		/* Timer/Counter2 Update Busy */
	#define	AS2 		(uint8_t) (3)		/* Asynchronous Timer/Counter2 */
	/*----------------------------- Output Compare Register ----------------------*/
	#define OCR2		*((volatile uint8_t*) (0x43))
	/*----------------------------- Timer/Counter Register -----------------------*/
	#define TCNT2		*((volatile uint8_t*) (0x44))
	/*----------------------- Timer/Counter Control Register ---------------------*/
	#define TCCR2		*((volatile uint8_t*) (0x45))
	/*------------------------ Special Function IO Register ----------------------*/
	#define SFIOR		*((volatile uint8_t*) (0x50))
	#define	PSR2 		(uint8_t) (1)		/* Timer/Counter0 Overflow Flag */
	/*------------------ Timer/Counter Interrupt Flag Register -------------------*/
	#define	TOV2 		(uint8_t) (6)		/* Timer/Counter0 Overflow Flag */
	#define	OCF2 		(uint8_t) (7)		/* Output Compare Flag 0 */
	/*------------------ Timer/Counter Interrupt Mask Register -------------------*/
	#define	TOIE2 		(uint8_t) (6)		/* Timer/CounterTimer/Counter0 Overflow Interrupt Enable */
	#define	OCIE2 		(uint8_t) (7)		/* Timer/CounterTimer/Counter0 Output Compare Match Interrupt Enable */
	
	#define MCUCR *((volatile uint8_t*)0x55)
/*------------------ INTERRUPT REGEISTERS -------------------*/
	/* MCUCR */
	#define SE      7
	#define SM2     6
	#define SM1     5
	#define SM0     4
	#define ISC11   3
	#define ISC10   2
	#define ISC01   1
	#define ISC00   0


	#define MCUCSR *((volatile uint8_t*)0x54)

	/* MCUCSR */
	#define JTD     7
	#define ISC2    6
	/* bit 5 reserved */
	#define JTRF    4
	#define WDRF    3
	#define BORF    2
	#define EXTRF   1
	#define PORF    0

	#define GICR *((volatile uint8_t*)0x5B)
	/* GICR */
	#define INT1    7
	#define INT0    6
	#define INT2    5
	#define IVSEL   1
	#define IVCE    0

	#define SREG *((volatile uint8_t*)0x5F)
#else
	/*------------------------------ PORTA REGISTERS -----------------------------*/
	extern volatile uint8_t PORTA_DATA;
	extern volatile uint8_t PORTA_DIR;
	extern volatile uint8_t PORTA_INPUT;

	extern volatile uint8_t PORTA;
	extern volatile uint8_t DDRA;
	extern volatile uint8_t PINA;

	/*------------------------------ PORTB REGISTERS -----------------------------*/
	extern volatile uint8_t PORTB_DATA;
	extern volatile uint8_t PORTB_DIR;
	extern volatile uint8_t PORTB_INPUT;

	extern volatile uint8_t PORTB;
	extern volatile uint8_t DDRB;
	extern volatile uint8_t PINB;

	/*------------------------------ PORTC REGISTERS -----------------------------*/
	extern volatile uint8_t PORTC_DATA;
	extern volatile uint8_t PORTC_DIR;
	extern volatile uint8_t PORTC_INPUT;

	extern volatile uint8_t PORTC;  
	extern volatile uint8_t DDRC;  
	extern volatile uint8_t PINC;

	/*------------------------------ PORTD REGISTERS -----------------------------*/
	extern volatile uint8_t PORTD_DATA;
	extern volatile uint8_t PORTD_DIR;
	extern volatile uint8_t PORTD_INPUT;

	extern volatile uint8_t PORTD;
	extern volatile uint8_t DDRD;
	extern volatile uint8_t PIND;
	/*------------------------------ TIMER0 REGISTERS ----------------------------*/
	extern volatile uint8_t OCR0;
	/*----------------------------- Timer/Counter Register -----------------------*/
	extern volatile uint8_t TCNT0;
	/*----------------------- Timer/Counter Control Register ---------------------*/
	extern volatile uint8_t TCCR0;
	/*------------------ Timer/Counter Interrupt Flag Register -------------------*/
	extern volatile uint8_t TIFR0;
	/*------------------ Timer/Counter Interrupt Mask Register -------------------*/
	extern volatile uint8_t TIMSK0;
	
	/*------------------------------ TIMER2 REGISTERS ----------------------------*/
	/*------------------------ Asynchronous Status Register ----------------------*/
	extern volatile uint8_t ASSR;
	/*----------------------------- Output Compare Register ----------------------*/
	extern volatile uint8_t OCR2;
	/*----------------------------- Timer/Counter Register -----------------------*/
	extern volatile uint8_t TCNT2;
	/*----------------------- Timer/Counter Control Register ---------------------*/
	extern volatile uint8_t TCCR2;
	/*------------------------ Special Function IO Register ----------------------*/
	extern volatile uint8_t SFIOR;
	/*------------------ Timer/Counter Interrupt Flag Register -------------------*/
	extern volatile uint8_t TIFR2;
	/*------------------ Timer/Counter Interrupt Mask Register -------------------*/
	extern volatile uint8_t TIMSK2;
#endif


#endif /* REGISTERS_H_ */