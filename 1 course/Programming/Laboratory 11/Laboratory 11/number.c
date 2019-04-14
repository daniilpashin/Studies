//
//  number.c
//  Laboratory 11
//
//  Created by Даниил on 18/03/2019.
//  Copyright © 2019 Даниил. All rights reserved.
//

#include "number.h"

const int size_for_int_part(const double *numbers, const size_t size)
{
    int length = 0;
    
    for (int i = 0; i < size; i++) {
        int number = (int)numbers[i];
        while (number != 0) {
            number /= 10;
            length++;
        }
    }
    
    return length;
}

char *concat_numbers(const double *numbers, const size_t count, size_t *out_length)
{
    const int length = (int)(7 * count) + size_for_int_part(numbers, count);
    
    char *string = malloc((length + 1) * sizeof(char));
    
    uint32_t current_position = 0;
    for (int i = 0; i < count; i++) {
        current_position += sprintf(&string[current_position], "%.5lf ", numbers[i]);
    }
    *out_length = current_position;
    
    return string;
}
