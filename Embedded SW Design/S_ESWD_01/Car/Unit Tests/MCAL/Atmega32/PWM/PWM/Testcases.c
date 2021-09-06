#include <stdio.h>
#include "../../../../../Car/MCAL/PWM/PWM.h"

#define NUMBER_OF_TESTCASES		(uint8_t)(2)
#define ONE                     (uint8_t)(1)
#define ZERO                    (uint8_t)(0)

void TestPWMStart(void);
void TestPWMStop(void);

static uint8_t u8_ID;
static uint8_t* ptr_null;
static uint8_t u8_PassedCounter = 0;
static E_STATUS PWM_ErrorState;
static PWM_TIMER timerno = PWM_TIMER0;
static uint8_t dutycycle = 90;

void TestPWMStart(void)
{
    u8_ID = 1;
    PWM_ErrorState = PWM_START(timerno, dutycycle);
    if (E_OK == PWM_ErrorState)
    {
        printf("Test Case ID: %u - PASSED \n", u8_ID);
        u8_PassedCounter++;
    }
    else
    {
        printf("Test Case ID: %u - FAILED \n", u8_ID);
    }

}

void TestPWMStop(void)
{
    u8_ID = 2;
    PWM_ErrorState = PWM_STOP(timerno);
    if (E_OK == PWM_ErrorState)
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
    TestPWMStart();

    TestPWMStop();

    printf("%u/%u TestCases passed.\n", u8_PassedCounter, NUMBER_OF_TESTCASES);
    return 0;
}
