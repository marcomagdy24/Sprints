#include <stdio.h>
#include "../../../../Car/ECUAL/LCD/lcd.h"

#define NUMBER_OF_TESTCASES		(uint8_t)(7)
#define ONE                     (uint8_t)(1)
#define ZERO                    (uint8_t)(0)

void TestLcdInit(void);
void TestLcdWriteCommand(void);
void TestLcdWriteChar(void);
void TestLcdWriteString(void);
void TestLcdWriteNumber(void);
void TestLcdGoToXY(void);
void TestLcdClearScreen(void);
static uint8_t u8_ID;
static uint8_t* ptr_null;
static uint8_t u8_PassedCounter = 0;
static E_STATUS Lcd_ErrorState;

void TestLcdInit(void)
{
    u8_ID = 1;
    Lcd_ErrorState = LCD_INIT();

    if (E_OK == Lcd_ErrorState)
    {
        printf("Test Case ID: %u - PASSED \n", u8_ID);
        u8_PassedCounter++;
    }
    else
    {
        printf("Test Case ID: %u - FAILED \n", u8_ID);
    }

}

void TestLcdWriteCommand(void)
{
    u8_ID = 2;
    uint8_t command = 0x00;
    Lcd_ErrorState = LCD_WRITE_COMMAND(command);
    if (E_OK == Lcd_ErrorState)
    {
        printf("Test Case ID: %u - PASSED \n", u8_ID);
        u8_PassedCounter++;
    }
    else
    {
        printf("Test Case ID: %u - FAILED \n", u8_ID);
    }
}

void TestLcdWriteChar(void)
{
    u8_ID = 3;
    uint8_t data = 0x00;
    Lcd_ErrorState = LCD_WRITE_CHAR(data);
    if (E_OK == Lcd_ErrorState)
    {
        printf("Test Case ID: %u - PASSED \n", u8_ID);
        u8_PassedCounter++;
    }
    else
    {
        printf("Test Case ID: %u - FAILED \n", u8_ID);
    }
}

void TestLcdWriteString(void)
{
    u8_ID = 4;
    uint8_t data[] = "FKDSFM";
    Lcd_ErrorState = LCD_WRITE_STRING(&data);

    if (E_OK == Lcd_ErrorState)
    {
        printf("Test Case ID: %u - PASSED \n", u8_ID);
        u8_PassedCounter++;
    }
    else
    {
        printf("Test Case ID: %u - FAILED \n", u8_ID);
    }

}

void TestLcdWriteNumber(void)
{
    u8_ID = 5;
    long int number = 1000000;
    Lcd_ErrorState = LCD_WRITE_NUMBER(number);

    if (E_OK == Lcd_ErrorState)
    {
        printf("Test Case ID: %u - PASSED \n", u8_ID);
        u8_PassedCounter++;
    }
    else
    {
        printf("Test Case ID: %u - FAILED \n", u8_ID);
    }

}

void TestLcdGoToXY(void)
{
    u8_ID = 6;
    uint8_t line = 2;
    uint8_t position = 15;
    Lcd_ErrorState = LCD_GOTO_XY(line, position);

    if (E_OK == Lcd_ErrorState)
    {
        printf("Test Case ID: %u - PASSED \n", u8_ID);
        u8_PassedCounter++;
    }
    else
    {
        printf("Test Case ID: %u - FAILED \n", u8_ID);
    }

}

void TestLcdClearScreen(void)
{
    u8_ID = 7;
    Lcd_ErrorState = LCD_clear_screen();

    if (E_OK == Lcd_ErrorState)
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
    TestLcdInit();

    TestLcdWriteCommand();

    TestLcdWriteChar();

    TestLcdWriteString();

    TestLcdWriteNumber();

    TestLcdGoToXY();

    TestLcdClearScreen();

    printf("%u/%u TestCases passed.\n", u8_PassedCounter, NUMBER_OF_TESTCASES);
    return 0;
}
