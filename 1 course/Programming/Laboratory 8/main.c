//
//  main.c
//  Laboratory 8 - variant 20
//
//  Created by Даниил on 17/12/2018.
//  Copyright © 2018 Даниил. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

void printArray(int **numbers, const int linesCount, const int coloumnsCount);
void processArray(int **numbers, const int linesCount, const int coloumnsCount);
void randomiseAndPrintArray(int **numbers, const int linesCount, const int coloumnsCount);
void deleteArray(int **numbers, int linesCount);


int main(int argc, const char * argv[])
{
    int linesCount = 0,
        coloumnsCount = 0;
    
    printf("Введите количество строк:\t");
    scanf("%i", &linesCount);
    
    printf("Введите количество столбцов:\t");
    scanf("%i", &coloumnsCount);
    printf("\n");
    
    int **numbers = malloc(linesCount * sizeof(int *));
    
    randomiseAndPrintArray(numbers, linesCount, coloumnsCount);
    printf("\n");
    
    processArray(numbers, linesCount, coloumnsCount);
    printf("\n");
    
    printArray(numbers, linesCount, coloumnsCount);
    deleteArray(numbers, linesCount);
    
    
    return 0;
}

void randomiseAndPrintArray(int **numbers, const int linesCount, const int coloumnsCount)
{
    for (int line = 0; line < linesCount; line++) {
        numbers[line] = malloc(coloumnsCount * sizeof(int));
        
        for (int coloumn = 0; coloumn < coloumnsCount; coloumn++) {
            numbers[line][coloumn] = rand() % 300;
            
            printf("%3.i ", numbers[line][coloumn]);
        }
        printf("\n");
    }
}

void processArray(int **numbers, const int linesCount, const int coloumnsCount)
{
    int minLineIndex = 0,
        minLineProduct = __INT_MAX__;
    
    int maxLineIndex = 0,
        maxLineProduct = -__INT_MAX__;
    
    
    for (int line = 0; line < linesCount; line++) {
        
        double product = 1.0;
        
        for (int coloumn = 0; coloumn < coloumnsCount; coloumn++) {
            product *= numbers[line][coloumn];
        }
        
        if (product > maxLineProduct) {
            maxLineProduct = product;
            maxLineIndex = line;
        }
        
        if (product < minLineProduct) {
            minLineProduct = product;
            minLineIndex = line;
        }
        
        printf("Произведение для строки %i равно %.3f\n", line, product);
    }
    
    int *minLine = numbers[minLineIndex];
    numbers[minLineIndex] = numbers[maxLineIndex];
    numbers[maxLineIndex] = minLine;
}

void printArray(int **numbers, const int linesCount, const int coloumnsCount)
{
    for (int line = 0; line < linesCount; line++) {
        for (int coloumn = 0; coloumn < coloumnsCount; coloumn++) {
            printf("%3.i ", numbers[line][coloumn]);
        }
        printf("\n");
    }
}

void deleteArray(int **numbers, int linesCount)
{
    for (int line = 0; line < linesCount; line++) {
        free(numbers[line]);
    }
    
    free(numbers);
}
