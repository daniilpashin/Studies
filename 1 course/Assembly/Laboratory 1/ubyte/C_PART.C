#include <stdio.h>

extern unsigned char calculate(unsigned char a, unsigned char c, unsigned char d);

int main()
{
    unsigned char a = 32, c = 12, d = 2;

    printf("A: %i; C: %i; D: %i; | ", a, c, d);
    printf("Result: %i\n\n", calculate(a, c, d));

    return 0;
}