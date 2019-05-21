#include <stdio.h>

extern unsigned int calculate(unsigned int a, unsigned int c, unsigned int d);

int main(int argc, char *argv[])
{
    unsigned int a = 48, c = 48, d = 48;

    printf("\nAll positive:\n");
    printf("A: %i; C: %i; D: %i; | ", a, c, d);
    printf("Result: %i\n\n", calculate(a, c, d));

    return 0;
}