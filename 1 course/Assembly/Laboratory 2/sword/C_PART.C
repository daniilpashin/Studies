#include <stdio.h>

extern signed int calculate(signed int a, signed int b);

int main()
{
    printf("Testing positive numbers:\n");
    printf("Test 1: equal. Result: %i\n", calculate(0, 0));
    printf("Test 2: A > B. Result: %i\n", calculate(1, 0));
    printf("Test 3: A < B. Result: %i\n\n", calculate(0, 1));

    printf("Testing negative numbers:\n");
    printf("Test 1: A > B. Result: %i\n", calculate(-2, -3));
    printf("Test 2: A < B. Result: %i\n", calculate(-3, -2));

    return 0;
}