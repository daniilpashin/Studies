#include <stdio.h>

extern signed char calculate(signed char a, signed char c, signed char d);

int main(int argc, char *argv[])
{
    signed char a = 49, c = 48, d = 48;

    printf("\nAll positive:\n");
    printf("A: %i; C: %i; D: %i; | ", a, c, d);
    printf("Result: %i\n\n", calculate(a, c, d));

    a = -a;

    printf("Part positive:\n");
    printf("A: %i; C: %i; D: %i; | ", a, c, d);
    printf("Result: %i\n\n", calculate(a, c, d));

    c = -c;
    d = -d;

    printf("All negative:\n");
    printf("A: %i; C: %i; D: %i; | ", a, c, d);
    printf("Result: %i\n", calculate(a, c, d));

    return 0;
}