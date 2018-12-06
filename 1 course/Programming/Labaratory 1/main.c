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
	double  x = 0.0,
            a = 0.0, 
            b = 0.0;
	
	printf ("Введите значение x:\n");
	scanf("%lf", &x);
	
	printf ("Введите значение a:\n");
	scanf("%lf", &a);
	
	printf ("Введите значение b:\n");
	scanf("%lf", &b);

	double y = (pow(sin(x), 2.0) + 5.0) / 5.0;
	double p = pow(a * y + 57.0, 1.0 / 3.0);
	double z = p / (3.0 + fabs(cos(b)) + p);
	printf("y: %.5f, z: %.5f\n", y, z);
	
	return 0;
}
