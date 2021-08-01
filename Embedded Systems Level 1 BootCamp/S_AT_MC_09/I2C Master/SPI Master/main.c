/*
 * I2C Master.c
 *
 * Created: 7/14/2021 10:33:03 PM
 * Author : Marco
 */ 

/******************************************************************************
*                              Includes													*
*******************************************************************************/
#include "APP/I2C_MASTER/master.h"

int main(void)
{
    /* Replace with your application code */
	 I2C_Master_Init();
	 
    while (1) 
    {
		I2C_Master_Update();
    }
}

