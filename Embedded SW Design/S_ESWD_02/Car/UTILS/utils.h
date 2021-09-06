/*
 * utils.h
 *
 * Created: 7/20/2021 2:37:53 PM
 *  Author: Marco Magdy
 */ 


#ifndef __UTILS_H__
#define __UTILS_H__

/*- INCLUDES -----------------------------------------------*/
#include "types.h"
#include <math.h>

/******************************************************************************
*                               FUNCTION-LIKE MACROS                          *
*******************************************************************************/

#define SET_BIT(PORT,BIT)	  (PORT|=(1<<BIT))
#define RESET_BIT(PORT,BIT)	  (PORT&=~(1<<BIT))
#define TOGGLE_BIT(PORT,BIT)  (PORT^=(1<<BIT))
#define READ_BIT(PORT,BIT)	  (PORT&(1<<BIT))

#define CLEAR_BIT(PORT,BIT)	  (PORT&=~(1<<BIT))
#define conc_Bit(B7,B6,B5,B4,B3,B2,B1,B0)				CONC_HELP(B7,B6,B5,B4,B3,B2,B1,B0)
#define CONC_HELP(B7,B6,B5,B4,B3,B2,B1,B0) 				0b##B7##B6##B5##B4##B3##B2##B1##B0
#define CLR_BIT(REG,BIT)			(REG&=(~(1<<BIT)))
#define Set_Bit(reg,bit)             (reg|=((uint8_t)1<<bit))
#define Get_Bit(reg,bit)            (((reg>>bit)&(uint8_t)(0x01)))

#define REG_WRITE(REG,VAL) REG=VAL

#define END_OF_STRING				(uint8_t)('\0')
#define NEW_LINE					(uint8_t)('\r')
	
#define ONE							(uint8_t)(1)
#define ZERO						(uint8_t)(0)

#define TRUE						(uint8_t)(1)
#define FALSE						(uint8_t)(0)

#define BIT_LOW 0
#define BIT_HIGH 1

#define BIT_WRITE(REG,BITNO,VAL) REG=(REG&(~(BIT_HIGH<<BITNO)))|(VAL<<BITNO)
//BIT_GET TO KNOW THE BIT VALUE
#define BIT_GET(REG,BITNO) ((REG>>BITNO)&BIT_HIGH)
#define TWO_BITS_GET(REG,FIRSTBITNO) ((REG>>FIRSTBITNO)&TWO_BITS_HIGH)

//REG_GET TO KNOW THE VALUE IN THE REGISTER
#define REG_GET(REG) (REG)

#define BIT_TOGGLE(REG,BITNO) REG^=(BIT_HIGH<<BITNO)
#define REG_TOGGLE(REG) REG=~REG

typedef uint8_t E_STATUS;

#define E_NOK (E_STATUS) 0
#define E_OK (E_STATUS)  1


/*- FUNCTION DECLARATIONS ----------------------------------*/

/* dummy delay for nearly 50ms */
void dummy_delay(void);

/* compares two strings if identical */
uint8_t StringCompare(uint8_t * str1, uint8_t * str2);

/* get string size */
uint8_t StringLength(uint8_t * string);

/* get string size */
void reverse(ptr_uint8_t str, uint8_t len);

/* get string size */
uint8_t intToStr(uint32_t x, uint8_t str[], uint32_t d);

/* get string size */
void ftos(float32_t n, ptr_uint8_t res, uint8_t afterpoint);

/* get string size */
float32_t stof(ptr_uint8_t str);

#endif /* __UTILS_H__ */