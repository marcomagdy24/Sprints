#include <assert.h>
#include <string.h>
#include "balancedParentheses.h"

void TestCase1(void)
{
    /* Balanced Cases */
    assert(strcmp(balancedParentheses("(2*3+(5/2+(4*3)))"), "Balanced") == 0);
    // assert(strcmp(balancedParentheses("3"), Balance) == 0);
    // assert(strcmp(balancedParentheses("({2+3}*(4+5))"), Balance) == 0);
    // assert(strcmp(balancedParentheses("{}"), Balance) == 0);
    // assert(strcmp(balancedParentheses("()"), Balance) == 0);
    // assert(strcmp(balancedParentheses("({})"), Balance) == 0);
    // assert(strcmp(balancedParentheses("((){})"), Balance) == 0);

    // /* Not Balanced Cases */
    // assert(strcmp(balancedParentheses("{({2+10}}*11}"), Not_Balance) == 0);
    // assert(strcmp(balancedParentheses("({3)}"), Not_Balance) == 0);
    // assert(strcmp(balancedParentheses("(}"), Not_Balance) == 0);
    // assert(strcmp(balancedParentheses("({}"), Not_Balance) == 0);
    assert(strcmp(balancedParentheses("}{)("), "Not Balanced") == 0);
}

int main(void)
{
    TestCase1();

    /* if no assertion error happened, print all tests passed message. */
    printf("All test cases passed successfully! :))\n");
    return 1;
}