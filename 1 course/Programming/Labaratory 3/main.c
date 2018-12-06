/*
 * main.c
 * Copyright (C) 2018 daniil <admin@danpashin.ru>
 * 
 * Variant 20
 */

#include <stdio.h>
#include <math.h>

int main()
{
    int N = 0;
    double  a = 0.0,
            startX = 0.0,
            endX = 0.0;

    printf("\nВведите количество значений N:\n");
    scanf("%i", &N);

    printf("Введите a:\n");
    scanf("%lf", &a);

    printf("Введите начальный x:\n");
    scanf("%lf", &startX);

    printf("Введите конечный x:\n");
    scanf("%lf", &endX);

    double  delta = (endX - startX) / (N - 1), 
           currentX = startX;

    printf("\n");
    for(int i = 0; i < N; i++) {
        double y = log(a * a + currentX * currentX) / fabs(a + currentX);
        printf("y(%.5lf) = %.5lf\n", currentX, y);

        currentX += delta;
    }
    printf("\n");

    return 0;
}
