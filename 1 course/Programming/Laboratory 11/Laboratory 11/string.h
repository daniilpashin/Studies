//
//  string.h
//  Laboratory 11
//
//  Created by Даниил on 18/03/2019.
//  Copyright © 2019 Даниил. All rights reserved.
//

#ifndef string_h
#define string_h

#include <stdio.h>
#include <stdbool.h>

char *normalize_line(const char *line, const size_t length, size_t *out_length);
bool is_numeric_string(const char *string);

#endif /* string_h */
