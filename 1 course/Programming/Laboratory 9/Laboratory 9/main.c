//
//  main.c
//  Laboratory 9
//
//  Created by Даниил on 20/02/2019.
//  Copyright © 2019 Даниил. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "string_change.h"
#include <stdlib.h>

int main(int argc, const char * argv[])
{
    printf("Введите строку:\n");
    size_t size = 0;
    char *string = fgetln(stdin, &size);
    
    str_remove_final_line_break(string);
    
    printf("Введите минимальную длину слова для удаления:\n");
    unsigned int min_word_length = 0;
    scanf("%i", &min_word_length);
    
    str_remove_word_more_than_or_equal(string, min_word_length);
    
    printf("\nОбработанная строка: %s\n", string);
    free(string);
    
    return 0;
}
