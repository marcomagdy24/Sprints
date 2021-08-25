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

#define REG_WRITE(REG,VAL) REG=VAL

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

#endif /* UTILS_H_ */