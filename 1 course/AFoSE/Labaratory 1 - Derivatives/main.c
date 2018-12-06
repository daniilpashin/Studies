//
//  main.c
//  Derivatives
//
//  Created by Даниил on 10/11/2018.
//  Copyright © 2018 Даниил. All rights reserved.
//

#include <stdio.h>
#include <math.h>

double func(double x);


int main(int argc, const char * argv[])
{
    double  x = 5.0,
            deltaX = 0.01;
    
    double derivative = (func(x + deltaX) - func(x)) / deltaX;
    printf("Производная %.1f равна %.1f\n", x, derivative);
    
    return 0;
}

double func(double x)
{
    return x * x;
}
