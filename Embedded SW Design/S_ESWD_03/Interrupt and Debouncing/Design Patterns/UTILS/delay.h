/*
 * delay.h
 *
 *  Created on: 10/8/2021
 *  
 */
#include "types.h"

#ifndef DELAY_H_
#define DELAY_H_

#define  F_CPU 8000000UL

static inline void _delay_us(double __us) __attribute__((always_inline));
static inline void _delay_ms(double __ms) __attribute__((always_inline));

static inline void _delay_loop_1(uint8_t __count) __attribute__((always_inline));
static inline void _delay_loop_2(uint16_t __count) __attribute__((always_inline));


void _delay_loop_1(uint8_t __count)
{
	__asm__ volatile (
		"1: dec %0" "\n\t"
		"brne 1b"
		: "=r" (__count)
		: "0" (__count)
	);
}


void _delay_loop_2(uint16_t __count)
{
	__asm__ volatile (
		"1: sbiw %0,1" "\n\t"
		"brne 1b"
		: "=w" (__count)
		: "0" (__count)
	);
}

void _delay_us(double __us)
{
	uint8_t __ticks;
	double __tmp = ((F_CPU) / 3e6) * __us;
	if (__tmp < 1.0)
		__ticks = 1;
	else if (__tmp > 255)
	{
		_delay_ms(__us / 1000.0);
		return;
	}
	else
		__ticks = (uint8_t)__tmp;
	_delay_loop_1(__ticks);
}

void _delay_ms(double __ms)
{
	uint16_t __ticks;
	double __tmp = ((F_CPU) / 4e3) * __ms;
	if (__tmp < 1.0)
		__ticks = 1;
	else if (__tmp > 65535)
	{
		//	__ticks = requested delay in 1/10 ms
		__ticks = (uint16_t) (__ms * 10.0);
		while(__ticks)
		{
			// wait 1/10 ms
			_delay_loop_2(((F_CPU) / 4e3) / 10);
			__ticks --;
		}
		return;
	}
	else
		__ticks = (uint16_t)__tmp;
	_delay_loop_2(__ticks);
}

#endif /* DELAY_H_ */
