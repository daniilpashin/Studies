//
//  string_change.c
//  Laboratory 9
//
//  Created by Даниил on 20/02/2019.
//  Copyright © 2019 Даниил. All rights reserved.
//

#include "string_change.h"
#include <stdbool.h>
#include <string.h>

void move_null_terminated_to_end(char *string, const unsigned int length);


void str_remove_word_more_than_or_equal(char *string, const unsigned int min_word_length)
{
    const unsigned int string_length = (unsigned int)strlen(string);
    int current_word_length = 0;
    
    for (int i = 0; i < string_length; i++) {
        const bool is_last_index = i == string_length - 1;
        
        if (string[i] != ' ' && !is_last_index) {
            current_word_length++;
            continue;
        }
        
        if (is_last_index) current_word_length++;
        
        if (current_word_length >= min_word_length) {
            for (int j = current_word_length; j >= 0; j--) {
                string[i - j] = '\0';
            }
        }
        
        current_word_length = 0;
    }
    
    move_null_terminated_to_end(string, string_length);
}

void move_null_terminated_to_end(char *string, const unsigned int length)
{
    int symbols_count = 0;
    
    for (int i = 0; i < length; i++) {
        if (string[i] != '\0')
            string[symbols_count++] = string[i];
    }
    
    while (symbols_count < length) {
        string[symbols_count++] = '\0';
    }
}

void str_remove_final_line_break(char *string)
{
    const unsigned int last_index = (unsigned int)strlen(string) - 1;
    if (string[last_index] == '\n')
        string[last_index] = '\0';
}

