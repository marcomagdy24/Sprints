#ifndef TYPES_H_

#define TYPES_H_


/******************************************************************************
*                              TYPEDEFFS			                          *
*******************************************************************************/

typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;
typedef unsigned long int uint32_t;

typedef signed char sint8_t;
typedef signed short int sint16_t;
typedef signed long int sint32_t;

typedef float ufloat32_t;

typedef void(*Ptr_VoidFuncVoid_t)(void);
typedef unsigned char* ptr_uint8_t;
typedef signed char* ptr_sint8_t;

#define NULL_PTR        ((void*)(0))

#define FALSE					(uint8_t)(0)
#define TRUE					(uint8_t)(1)
#define STRING_END			(uint8_t)('\0')
#define END_OF_STRING		(uint8_t)('\0')
#define NULL_TERMINATOR    (uint8_t)('\0')
#define NEW_LINE           (uint8_t)('\r')
#define BACKSPACE          (uint8_t)('\b')

#endif
