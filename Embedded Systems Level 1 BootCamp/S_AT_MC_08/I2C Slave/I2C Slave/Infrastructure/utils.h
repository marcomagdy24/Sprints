/*
 * utils.h
 *
 * Created: 7/11/2021 11:42:16 AM
 *  Author: marco
 */ 


#ifndef UTILS_H_
#define UTILS_H_

/******************************************************************************
*                               FUNCTION-LIKE MACROS                          *
*******************************************************************************/
#define SET_BIT(PORT,BIT)	  (PORT|=(1<<BIT))
#define RESET_BIT(PORT,BIT)	  (PORT&=~(1<<BIT))
#define TOGGLE_BIT(PORT,BIT)  (PORT^=(1<<BIT))
#define READ_BIT(PORT,BIT)	  (PORT&(1<<BIT))


#endif /* UTILS_H_ */