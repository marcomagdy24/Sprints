/*
 ============================================================================
 Name        : S_DS_01.c
 Author      : Marco
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include "./Stack/stack.h"
#include "Balanced Parentheses/balancedParentheses.h"

int main()
{
    uint8_t expression[20] = "{1+(2/5)+2";
    uint8_t *response = balancedParentheses(expression);
    printf("%s\n", response);
    return 0;
}
