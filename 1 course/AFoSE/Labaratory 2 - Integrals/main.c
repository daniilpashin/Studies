//
//  main.c
//  Integrals
//
//  Created by Даниил on 06/11/2018.
//  Copyright © 2018 Даниил. All rights reserved.
//

#include <stdio.h>
#include <math.h>

double F(double x);
double integral(void);


int main(int argc, const char * argv[])
{
    printf("Интеграл: %.5f\n", integral());
    
    return 0;
}


double F(double x)
{
    return sin(x);
}

double integral(void)
{
    const int numpoints = 2000;
    
    double right = 0.0, left = M_PI;
    const double step = (right - left) / (numpoints - 1);
    
    
    double integral = 0.0;
    
    for (int i = 0; i < numpoints; i++) {
        integral += step * F(step * i);
    }
    
    return integral;
}
