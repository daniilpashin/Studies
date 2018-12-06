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
    int n = 0;
    double x = 0.0;

    printf("Введите n:\n");
    scanf("%i", &n);

    printf("Введите x:\n");
    scanf("%lf", &x);

    double  y = 1.0 / x,
            index = -1.0;
    
    for (int k = 1; k <= n; k++) {
        y += index * (k * x) / (x * x + k * k);
        index = -index;
    }
    
    printf("y: %.5lf\n", y);

    return 0;
}
