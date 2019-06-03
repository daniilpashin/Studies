#include <stdio.h>

extern signed int calculate(signed char x);

int main()
{
    signed char x = 1;

    printf("\nPositive:\n");
    printf("X: %i; | ", x);
    printf("Result: %i\n\n", calculate(x));

    x = -1;

    printf("Negative:\n");
    printf("X: %i; | ", x);
    printf("Result: %i\n\n", calculate(x));

    return 0;
}