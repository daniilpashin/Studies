#include <stdio.h>

extern signed char calculate(signed char a, signed char c, signed char d);

int main()
{
    signed char a = 32, c = 12, d = 2;

    printf("\nPositive:\n");
    printf("A: %i; C: %i; D: %i; | ", a, c, d);
    printf("Result: %i\n\n", calculate(a, c, d));

    a = -a;
    c = -c;
    d = -d;

    printf("Negative:\n");
    printf("A: %i; C: %i; D: %i; | ", a, c, d);
    printf("Result: %i\n\n", calculate(a, c, d));

    return 0;
}