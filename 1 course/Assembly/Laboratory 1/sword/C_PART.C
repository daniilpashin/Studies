#include <stdio.h>

extern signed int calculate(signed int a, signed int c, signed int d);

int main(int argc, char *argv[])
{
    signed int a = 48, c = 48, d = 48;

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