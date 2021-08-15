/*
 * I2C Master.c
 *
 * Created: 7/28/2021 12:59:13 AM
 * Author : Marco
 */ 

#include "APP/I2C_MASTER/master.h"

int main(void)
{
    I2C_Master_Init();
    I2C_Master_Update();
    while (1) 
    {
    }
}

