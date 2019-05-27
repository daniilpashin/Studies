#include <stdio.h>
#include <stdlib.h>

extern "C" int get_num_between(int *array, int count, int c, int d);

int main()
{
    randomize();

    int numbers_count = 100;
    int *numbers = (int *)malloc(numbers_count * sizeof(int));

    const int random_lower = -50;
    const int random_upper = 50;

    const int between_lower = -10;
    const int between_upper = 0;
    int between_count = 0;

    int i = 0;
    for (i = 0; i < numbers_count; i++)
    {
        numbers[i] = (rand() % (random_upper - random_lower + 1)) + random_lower;
        printf("%i ", numbers[i]);
        if (numbers[i] < 0 && numbers[i] >= between_lower && numbers[i] <= between_upper)
        {
            between_count++;
        }
    }

    printf("\n\n");

    printf("C between %i and %i is: %i\n", between_lower, between_upper, between_count);
    printf("ASM between %i and %i is: %i\n", between_lower, between_upper, get_num_between(numbers, numbers_count, between_lower, between_upper));

    free(numbers);

    return 0;
}