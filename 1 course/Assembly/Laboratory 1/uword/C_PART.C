#include <stdio.h>

extern unsigned int calculate(unsigned int a, unsigned int c, unsigned int d);

int main()
{
    unsigned int a = 49, c = 42, d = 1;

    printf("A: %i; C: %i; D: %i; | ", a, c, d);
    printf("Result: %i\n\n", calculate(a, c, d));

    return 0;
}