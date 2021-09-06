/*
 * interrupt.h
 *
 *  Created on: 10/8/2021
 *      Author: Bishoy Nabil
 */

#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include "../../UTILS/registers.h"
#include "../../UTILS/types.h"
#include "../../UTILS/utils.h"
#include "../../MCAL/DIO/DIO.h"

#define ISR(vector, ...)            \
		void vector (void) __attribute__ ((signal)) __VA_ARGS__; \
		void vector (void)
#define _VECTOR(N) __vector_ ## N
#define INT0_vect				_VECTOR(1)
#define INT1_vect				_VECTOR(2)
#define INT2_vect				_VECTOR(3)
#define TIMER2_COMP_vect		_VECTOR(4)
#define TIMER2_OVF_vect			_VECTOR(5)
#define TIMER1_COMPA_vect		_VECTOR(7)
#define TIMER1_COMPB_vect		_VECTOR(8)
#define TIMER1_OVF_vect			_VECTOR(9)
#define TIMER0_COMP_vect		_VECTOR(10)
#define TIMER0_OVF_vect			_VECTOR(11)

enum
{
	interrupt0,
	interrupt1,
	interrupt2
};

enum
{
	low_lvl,
	any_logic_lvl,
	falling_edge,
	rising_edge
};

#define ISC2 6

enum
{
	int2_bit=5,
	int0_bit,
	int1_bit
};

E_STATUS external_interrupt_init(uint8_t external_INT_num, uint8_t edge);

#endif /* INTERRUPT_H_ */
