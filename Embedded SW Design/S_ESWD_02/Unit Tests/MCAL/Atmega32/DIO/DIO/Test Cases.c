#include <stdio.h>
#include "../../../../../Car/MCAL/DIO/dio.h"

#define NUMBER_OF_TESTCASES		(uint8_t)(5)
#define ONE                     (uint8_t)(1)
#define ZERO                    (uint8_t)(0)

void TestInit(void);
void TestReadPIN(void);
void TestWritePIN(void);
void TestWritePORT(void);
void TestToggelPIN(void);

static uint8_t u8_ID;
static uint8_t* ptr_null;
static uint8_t u8_PassedCounter = 0;
static E_STATUS DIO_ErrorState;
static uint8_t data;
static uint8_t port = DIO_PORTA;
static uint8_t pin = 7; 

void TestInit(void)
{
    u8_ID = 1;
    configs.port = DIO_PORTA;
    configs.pin = 7;
    configs.dir = OUTPUT;
    DIO_ErrorState = DIO_Init(&configs);
    if (E_OK == DIO_ErrorState) 
    {
        printf("Test Case ID: %u - PASSED \n", u8_ID);
        u8_PassedCounter++;
    }
    else
    {
        printf("Test Case ID: %u - FAILED \n", u8_ID);
    }

}

void TestReadPIN(void)
{
    u8_ID = 2;
    PORTA_DATA = 0x00;
    SET_BIT(PORTA_DATA, pin);
    DIO_ReadPIN(port, pin, &data);
    if (ONE == Get_Bit(PORTA_DATA, pin))
    {
        printf("Test Case ID: %u - PASSED \n", u8_ID);
        u8_PassedCounter++;
    }
    else
    {
        printf("Test Case ID: %u - FAILED \n", u8_ID);
    }
    RESET_BIT(port, pin);
}

void TestWritePIN(void)
{
    u8_ID = 3;
    PORTA_DATA = 0x00;
    DIO_WritePIN(port, pin, HIGH);
    if (READ_BIT(PORTA_DATA, pin))
    {
        printf("Test Case ID: %u - PASSED \n", u8_ID);
        u8_PassedCounter++;
    }
    else
    {
        printf("Test Case ID: %u - FAILED \n", u8_ID);
    }
}

void TestWritePORT(void)
{
    u8_ID = 4;
    PORTA_DATA = 0x00;
    DIO_WritePORT(port, 0xF0);
    if (0xF0 == PORTA_DATA)
    {
        printf("Test Case ID: %u - PASSED \n", u8_ID);
        u8_PassedCounter++;
    }
    else
    {
        printf("Test Case ID: %u - FAILED \n", u8_ID);
    }
}

void TestToggelPIN(void)
{
    u8_ID = 5;
    PORTA_DATA = 0x00;
    DIO_ErrorState = DIO_TogglePIN(port, pin);
    if (E_OK == DIO_ErrorState)
    {
        printf("Test Case ID: %u - PASSED \n", u8_ID);
        u8_PassedCounter++;
    }
    else
    {
        printf("Test Case ID: %u - FAILED \n", u8_ID);
    }
    RESET_BIT(port, pin);
}



int main()
{
    TestInit();

    TestReadPIN();

    TestWritePIN();

    TestWritePORT();

    TestToggelPIN();

    printf("%u/%u TestCases passed.\n", u8_PassedCounter, NUMBER_OF_TESTCASES);
    return 0;
}
