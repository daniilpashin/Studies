//
//  main.c
//  Laboratory 12
//
//  Created by Даниил on 14/04/2019.
//  Copyright © 2019 shad0wdev. All rights reserved.
//

#include <stdio.h>
#include <math.h>

double get_min_value_from(const double *array, const int size, double *min_arg, double (*func_ptr)(double));

int main(int argc, const char * argv[])
{
    double numbers[] = { 35.0, 45.0, 90.0 };
    const int count = sizeof(numbers) / sizeof(double);
    
    const double radian_coefficient = 0.0174533;
    for (int i = 0; i < count; i++) {
        numbers[i] *= radian_coefficient;
    }
    
    double min_number = 0.0;
    double min_value = get_min_value_from(numbers, count, &min_number, cos);
    printf("min value: %.5f, min number: %.5f\n", min_value, min_number / radian_coefficient);
    
    return 0;
}


double get_min_value_from(const double *array, const int size, double *min_arg, double (*func_ptr)(double))
{
    double min = __LONG_LONG_MAX__;
    for (int i = 0; i < size; i++) {
        double number = array[i];
        
        double _min = 0;
        if ((_min = func_ptr(number)) < min) {
            min = _min;
            *min_arg = number;
        }
    }
            
    return min;
}
