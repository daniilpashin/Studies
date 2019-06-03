#include <stdio.h>

extern signed int calculate(signed int a, signed int b);

int main()
{
    printf("Testing positive numbers:\n");
    printf("Test 1: equal. Result: %i\n", calculate(1, 1));

    return 0;
}