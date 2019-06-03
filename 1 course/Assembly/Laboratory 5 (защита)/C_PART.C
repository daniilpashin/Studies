#include <stdio.h>

extern float calculate(float x);

int main()
{
    printf("Result: %.5f\n", calculate(10.0));
    return 0;
}