//
//  main.c
//  Laboratory 7 - variant 20
//
//  Created by Даниил on 11/12/2018.
//  Copyright © 2018 Даниил. All rights reserved.
//

#include "help.h"

int main(int argc, const char * argv[])
{
    int n = 0;
    printf("Введите количество чисел в последовательностях:\n");
    scanf("%i", &n);
    
    const size_t sizeOfSequence = n * sizeof(double);
    
    double *firstSequence = malloc(sizeOfSequence);
    double *secondSequence = malloc(sizeOfSequence);
    double *thirdSequence = malloc(sizeOfSequence);
    
    printf("Введите первую последовательность, начиная с новой строки:\n");
    readSequence(firstSequence, n);
    
    printf("Введите вторую последовательность, начиная с новой строки:\n");
    readSequence(secondSequence, n);
    
    printf("Введите третью последовательность, начиная с новой строки:\n");
    readSequence(thirdSequence, n);
    
    printf("Новая последовательность 1:\n");
    buildSequence(firstSequence, secondSequence, n);
    printSequence(firstSequence, n);
    free(firstSequence);
    
    printf("Новая последовательность 2:\n");
    buildSequence(secondSequence, thirdSequence, n);
    printSequence(secondSequence, n);
    
    free(secondSequence);
    free(thirdSequence);
    
    return 0;
}
