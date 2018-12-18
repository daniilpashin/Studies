//
//  help.h
//  Laboratory7
//
//  Created by Даниил on 11/12/2018.
//  Copyright © 2018 Даниил. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

/**
 Выполняет считывание последовательности с клавиатуры.

 @param sequence Массив чисел с типом long.
 @param size Длина последовательности.
 */
void readSequence(double *sequence, const size_t size);


/**
 Выполняет вывод последовательности в консоль.

 @param sequence Массив чисел с типом long.
 @param size Длина последовательности.
 */
void printSequence(const double *sequence, const size_t size);

/**
 Выполняет построение новой последовательности из двух старых.

 @param firstSequence  Массив первой последовательности с типом double.
 @param secondSequence  Массив второй последовательности с типом double.
 @param size Длина последовательности.
 */
void buildSequence(double *firstSequence, const double *secondSequence, const size_t size);
