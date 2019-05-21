#include <stdio.h>

extern unsigned char calculate(unsigned char a, unsigned char c, unsigned char d);

int main(int argc, char *argv[])
{
    unsigned char a = 48, c = 48, d = 48;

    printf("\nAll positive:\n");
    printf("A: %i; C: %i; D: %i; | ", a, c, d);
    printf("Result: %i\n\n", calculate(a, c, d));

    return 0;
}