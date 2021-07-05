#include "stack.h"
#include "balancedParentheses.h"

int main()
{
    uint8_t expression[20] = "{1+(2/5)+2}";
    uint8_t *response = balancedParentheses(expression);
    printf("%s\n", response);
    return 1;
}