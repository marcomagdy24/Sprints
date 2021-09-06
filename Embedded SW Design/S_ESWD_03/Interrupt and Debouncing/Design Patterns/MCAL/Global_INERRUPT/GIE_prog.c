/****************************************/
/* Author  : Monica Francis					*/
/* Date    : 24/2/2018					*/
/* Version : V01						*/
/****************************************/

#include "GIE_priv.h"
#include "GIE_config.h"
#include "GIE_int.h"

/* Description : Enable global interrupt	*/
void GIE_voidEnable(void)
{
	SET_BIT(SREG,GIE_uint8_t_BIT_INDEX);
}

/* Description : Disable global interrupt	*/
void GIE_voidDisable(void)
{
	CLR_BIT(SREG,GIE_uint8_t_BIT_INDEX);
}
