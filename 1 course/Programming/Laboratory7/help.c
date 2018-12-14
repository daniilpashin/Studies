//
//  help.c
//  Laboratory7
//
//  Created by Даниил on 11/12/2018.
//  Copyright © 2018 Даниил. All rights reserved.
//

#include "help.h"

void readSequence(double *sequence, const size_t size)
{
    for (int i = 0; i < size; i++) {
        double number = 0.0;
        scanf("%lf", &number);
        
        sequence[i] = number;
    }
}

void printSequence(const double *sequence, const size_t size)
{
    for (int i = 0; i < size; i++) {
        printf("%.3f\n", sequence[i]);
    }
}

void buildSequence(double *firstSequence, const double *secondSequence, const size_t size)
{
    for (int i = 0; i < size; i++) {
        const double firstNumber = firstSequence[i];
        const double secondNumber = secondSequence[i];
        
        if (firstNumber < 0.0 && secondNumber > 0.0) {
            firstSequence[i] = secondNumber;
        } else if (firstNumber <= 0.0 || secondNumber >= 0.0) {
            firstSequence[i] = 0.0;
        }
    }
}
