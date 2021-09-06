#include <stdio.h>
#include "../../../../Car/ECUAL/Motor/DC_Motor.h"

#define NUMBER_OF_TESTCASES		(uint8_t)(3)
#define ONE                     (uint8_t)(1)
#define ZERO                    (uint8_t)(0)

void TestMotorInit(void);
void TestMotorStart(void);
void TestMotorStop(void);
static uint8_t u8_ID;
static uint8_t* ptr_null;
static uint8_t u8_PassedCounter = 0;
static E_STATUS Motor_ErrorState;

void TestMotorInit(void)
{
    u8_ID = 1;
	Motor_ErrorState=DC_MotorInit(MOTOR_LEFT);

    if (E_OK == Motor_ErrorState)
    {
        printf("Test Case ID: %u - PASSED \n", u8_ID);
        u8_PassedCounter++;
    }
    else
    {
        printf("Test Case ID: %u - FAILED \n", u8_ID);
    }

}

void TestMotorStart(void)
{
    u8_ID = 2;

    Motor_ErrorState=DC_MotorStart(MOTOR_LEFT,6,MOTOR_FORWARD);
    if (E_OK == Motor_ErrorState)
    {
        printf("Test Case ID: %u - PASSED \n", u8_ID);
        u8_PassedCounter++;
    }
    else
    {
        printf("Test Case ID: %u - FAILED \n", u8_ID);
    }
}

void TestMotorStop(void)
{
    u8_ID = 3;
    Motor_ErrorState=DC_MotorStop(MOTOR_LEFT);
    if (E_OK == Motor_ErrorState)
    {
        printf("Test Case ID: %u - PASSED \n", u8_ID);
        u8_PassedCounter++;
    }
    else
    {
        printf("Test Case ID: %u - FAILED \n", u8_ID);
    }
}



int main()
{
    TestMotorInit();

    TestMotorStart();

    TestMotorStop();



    printf("%u/%u TestCases passed.\n", u8_PassedCounter, NUMBER_OF_TESTCASES);
    return 0;
}
