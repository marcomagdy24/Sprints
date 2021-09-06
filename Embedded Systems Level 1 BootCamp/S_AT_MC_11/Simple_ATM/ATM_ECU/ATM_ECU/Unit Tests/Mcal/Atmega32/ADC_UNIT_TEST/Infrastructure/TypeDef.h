#ifndef TypeDef_H_
#define TypeDef_H_

typedef unsigned char                    uint8_t;

typedef unsigned short int               uint16_t;
typedef unsigned long int                uint32_t;
typedef unsigned long long               uint64_t;

typedef signed char                      int8_t;
typedef signed short int                 int16_t;
typedef signed long int                  int32_t;
typedef signed long long                 int64_t;

typedef unsigned char *                  ptr_uint8_t;
typedef unsigned short int *             ptr_uint16_t;
typedef unsigned long int *              ptr_uint32_t;
typedef unsigned long long *             ptr_uint64_t;

typedef signed char *                    ptr_int8_t;
typedef signed short int *               ptr_int16_t;
typedef signed long int *                ptr_int32_t;
typedef signed long long *               ptr_int64_t;
typedef void(*Ptr_VoidFuncVoid_t)(void); // pointer to void function void

typedef float                            f32_t;
typedef double                           f64_t;

#define NULL_TERMINATOR    '\0'
#define NEW_LINE           '\r'
#define BACKSPACE          '\b'
#define ZERO_ASCII          '0'

#define ON                 1
#define OFF                (0)

#define ZERO               (uint8_t)0


#define NULL_PTR  ((void*)(0))

#endif /* TypeDef_H_ */
