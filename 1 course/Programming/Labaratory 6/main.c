//
//  main.m
//  laba6
//
//  Created by Даниил on 25/11/2018.
//  Copyright © 2018 Даниил. All rights reserved.
//

#include <stdio.h>
#include <math.h>

double calculateFunction(double a, int n, int m);
void readValuesFromKeyboard(double *a, int *n, int *m);

int main(int argc, const char * argv[])
{
    double a = 0.0;
    int n = 0,
        m = 0;
    
    readValuesFromKeyboard(&a, &n, &m);
    
    double y = calculateFunction(a, n, m);
    printf("y = %.5f\n\n", y);
    
    return 0;
}



double calculateFunction(double a, int n, int m)
{
    double num = a;
    for (int k = 2; k <= n; k++) {
        num += 2.0 * pow(k, 3.0) + 1.0;
    }
    
    double denum = 2.0;
    for (int k = 1; k <= m; k++) {
        denum += pow(k, 3.0) + a;
    }
    
    return num / denum;
}


void readValuesFromKeyboard(double *a, int *n, int *m)
{
#define read(variable, format) printf("Введите значение переменной " # variable "\n"); scanf(format, variable);
    
    read(a, "%lf")
    read(n, "%i")
    read(m, "%i")
    
#undef read
}
