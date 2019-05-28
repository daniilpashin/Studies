#include <stdio.h>

extern float calculate(float a, float c, float d);

int main()
{
    float a = 48.0, c = 48.0, d = 48.0;

    printf("\nAll positive:\n");
    printf("A: %.5f; C: %.5f; D: %.5f; | ", a, c, d);
    printf("Result: %.5f\n\n", calculate(a, c, d));

    a = -a;

    printf("Part positive:\n");
    printf("A: %.5f; C: %.5f; D: %.5f; | ", a, c, d);
    printf("Result: %.5f\n\n", calculate(a, c, d));

    c = -c;
    d = -d;

    printf("All negative:\n");
    printf("A: %.5f; C: %.5f; D: %.5f; | ", a, c, d);
    printf("Result: %.5f\n", calculate(a, c, d));

    return 0;
}