//
//  main.c
//  Laboratory5 - variant 20
//
//  Created by Даниил on 20/11/2018.
//  Copyright © 2018 Даниил. All rights reserved.
//

#include <stdio.h>
#include <math.h>

/**
 Выполняет расчет значения функции в конкретной точке x.
 
 @param x Точка, для которой выполняется расчет.
 @param m Количество итераций суммы ряда функции.
 @return Возвращает значение функции.
 */
double calculateFunction(double x, int m);

/**
 Выполняет считывание данных с клавиатуры.

 @param startX Точка начального значения x.
 @param endX Точка конечного значения x.
 @param m Количество итераций суммы ряда функции.
 @param n Количество вычисляемых значений.
 */
void getArguments(double *startX, double *endX, int *m, int *n);


int main(int argc, const char * argv[])
{
    double  startX = 0.0,
            endX = 0.0;
    
    int m = 0,
        n = 0;
    
    getArguments(&startX, &endX, &m, &n);
    
    const double delta = (endX - startX) / n;
    double x = startX;
    
    for (int i = 0; i < n; i++) {
        double y = calculateFunction(x, m);
        printf("y(%.3f) = %.5f\n", x, y);
        
        x += delta;
    }
    
    printf("\n");
    return 0;
}


double calculateFunction(double x, int m)
{
    double y = 2.0 * x * x;
    for (int j = 1; j <= m; j++) {
        
        const double firstSum = 2.0 + x + j / x;
        double secondSum = 0.0;
        
        for (int k = 1; k <= m; k++) {
            secondSum += k * k;
        }
        
        y += pow(firstSum * secondSum, 2.0);
    }
    
    return sqrt(y);
}

void getArguments(double *startX, double *endX, int *m, int *n)
{
    printf("Введите начальный x:\n");
    scanf("%lf", startX);
    
    printf("Введите конечный x:\n");
    scanf("%lf", endX);
    
    printf("Введите m:\n");
    scanf("%d", m);
    
    printf("Введите n:\n");
    scanf("%d", n);
    printf("\n");
}
