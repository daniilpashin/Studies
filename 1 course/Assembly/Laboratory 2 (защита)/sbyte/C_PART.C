#include <stdio.h>

extern signed int calculate(signed char a);

int main()
{
    printf("Less 0: %i\n", calculate(-1));
    printf("More or equal 0: %i\n", calculate(100));

    return 0;
}