//
//  main.c
//  Laboratory 9
//
//  Created by Даниил on 20/02/2019.
//  Copyright © 2019 Даниил. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "string_change.h"

unsigned int get_lines_count(void);
unsigned int get_min_word_length(void);

int main(int argc, const char * argv[])
{
    unsigned int lines_number = get_lines_count();
    unsigned int min_word_length = get_min_word_length();
    
    printf("Выполните ввод строк:\n");
    char **strings = malloc(lines_number * sizeof(char *));
    for (int i = 0; i < lines_number; i++) {
        size_t size = 0;
        strings[i] = fgetln(stdin, &size);
    }
    printf("\n------------\n");
    
    for (int i = 0; i < lines_number; i++) {
        char *string = strings[i];
        str_remove_word_more_than_or_equal(string, min_word_length);
        printf("%s\n", string);
        free(string);
    }
    free(strings);
    
    return 0;
}

unsigned int get_lines_count(void)
{
    unsigned int lines_number = 0;
    printf("Введите количество строк:\n");
    scanf("%d", &lines_number);
    fseek(stdin, 0, SEEK_END);
    
    return lines_number;
}

unsigned int get_min_word_length(void)
{
    unsigned int min_word_length = 0;
    printf("Введите минимальную длину слова для удаления:\n");
    scanf("%d", &min_word_length);
    fseek(stdin, 0, SEEK_END);
    
    return min_word_length;
}

