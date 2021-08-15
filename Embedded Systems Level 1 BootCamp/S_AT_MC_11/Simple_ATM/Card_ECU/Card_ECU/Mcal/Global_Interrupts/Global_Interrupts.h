/*
 * Global_Interrupts.h
 *
 * Created: 7/24/2021 8:00:37 PM
 *  Author: Mohamed Wagdy
 */ 


#ifndef __GLOBAL_INTERRUPTS_H__
#define __GLOBAL_INTERRUPTS_H__

/*- INCLUDES -----------------------------------------------*/
#include "../../Infrastructure/STD_types.h"
#include "Global_Interrupts_Registers.h"
#include "Global_Interrupts_Config.h"

/*- FUNCTION DECLARATIONS ----------------------------------*/

/* Function that enables global interrupts. */
void GLOBALINTTERUPTS_Enable(void);

/* Function that disables global interrupts. */
void GLOBALINTTERUPTS_Disable(void);

#endif /* __GLOBAL_INTERRUPTS_H__ */