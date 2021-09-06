/*
 * interrupt.h
 *
 *  Created on: 10/8/2021
 *      Author: Bishoy Nabil
 */

#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/Timer/Timer.h"

#define INT0_vect				_VECTOR(0)
#define INT1_vect				_VECTOR(1)
#define Button_Interrupt _VECTOR(3)

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

E_STATUS ExInterrupt_INIT(uint8_t external_INT_num, uint8_t edge);
E_STATUS ExInterrupt_DeINIT(uint8_t external_INT_num);
void Timer_SetCallBack (Ptr_VoidFuncVoid_t Timer_ISR);
void Button_SetCallBack (Ptr_VoidFuncVoid_t Button_ISR);

#endif /* INTERRUPT_H_ */
