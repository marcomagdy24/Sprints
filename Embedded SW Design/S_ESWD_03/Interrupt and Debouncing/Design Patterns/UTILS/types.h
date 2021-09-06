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

typedef float float32_t;

typedef void (*Ptr_VoidFuncVoid_t)(void);
typedef void (*ButtonVectorPtr)(void);

typedef unsigned char* ptr_uint8_t;
typedef float* ptr_float32_t;

#define NULL_PTR        ((void*)(0))

#define ISR(vector, ...)            \
void vector (void) __attribute__ ((signal)) __VA_ARGS__; \
void vector (void)
#define _VECTOR(N) __vector_ ## N

#endif
