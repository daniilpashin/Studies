//
//  number.h
//  Laboratory 11
//
//  Created by Даниил on 18/03/2019.
//  Copyright © 2019 Даниил. All rights reserved.
//

#ifndef number_h
#define number_h

#include <stdio.h>

const int size_for_int_part(const double *numbers, const size_t size);

char *concat_numbers(const double *numbers, const size_t length, size_t *out_length);

#endif /* number_h */
