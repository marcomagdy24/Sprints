/*
 * I2C Slave.c
 *
 * Created: 7/28/2021 1:00:03 AM
 * Author : Marco
 */ 

#include "APP/I2C_SLAVE/slave.h"


int main(void)
{
    /* Replace with your application code */
	 I2C_Slave_Init();
	 
    while (1) 
    {
		 I2C_Slave_Update();
    }
}

