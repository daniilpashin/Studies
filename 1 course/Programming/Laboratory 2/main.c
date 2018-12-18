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
	double x = 0.0;

	printf("Введите значение x:\n");
	scanf("%lf", &x);

	double y = 0.0;
	if (x > 9.0) {
		y = sqrt(x);
	} else if (x > 2.0) {
		y = 5.0 * exp(-x);
	} else if (x > 1.0) {
		y = exp(x);
	} else {
		y = cos(x);
	}

	printf("y: %.5f\n", y);
	
	return 0;
}

