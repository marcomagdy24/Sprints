#include "balancedParentheses.h"

// Initialize head Node
StackNode *top = NULL;

int isMatching(char char1, char char2)
{
    if (char1 == '(' && char2 == ')')
        return 1;
    else if (char1 == '{' && char2 == '}')
        return 1;
    else if (char1 == '[' && char2 == ']')
        return 1;
    else
        return 0;
}

uint8_t *balancedParentheses(uint8_t *expression)
{
    uint8_t *result = (uint8_t *)malloc(15);
    uint8_t exp_index = 0;
    while (expression[exp_index])
    {
        if (expression[exp_index] == '{' || expression[exp_index] == '(' || expression[exp_index] == '[')
            push(expression[exp_index]);
        if (expression[exp_index] == '}' || expression[exp_index] == ')' || expression[exp_index] == ']')
        {
            if (top == NULL)
            {
                return (uint8_t *)Not_Balance;
            }
            else if (!isMatching(pull(), expression[exp_index]))
            {
                // *result = BALANCED;
                return (uint8_t *)Balance;
            }
        }

        exp_index++;
    }
    if (top == NULL)
    {
        // *result = BALANCED;
        return (uint8_t *)Balance;
    }
    else
    {
        // *result = NOT_BALANCED;
        return (uint8_t *)Not_Balance;
    }
}