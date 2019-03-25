//
//  main.c
//  Laboratory 11
//
//  Created by Даниил on 21/02/2019.
//  Copyright © 2019 Даниил. All rights reserved.
//

#include <stdlib.h>
#include "string.h"
#include <string.h>

void parse_file_and_write(FILE *input, FILE *output);

int main(int argc, const char *argv[])
{
    if (argc < 3) {
        printf("Укажите путь к исходному и выходному файлам.\n");
        return EXIT_FAILURE;
    }
    
    FILE *input_file = fopen(argv[1], "r");
    if (!input_file) {
        printf("Исходный файл не существует!\n");
        return EXIT_FAILURE;
    }
    
    FILE *output_file = fopen(argv[2], "w");
    if (!output_file) {
        printf("Не удается создать выходной файл!\n");
        return EXIT_FAILURE;
    }
    
    parse_file_and_write(input_file, output_file);
    
    fclose(input_file);
    fclose(output_file);
    
    return EXIT_SUCCESS;
}

void parse_file_and_write(FILE *input, FILE *output)
{
    int line_number = 0;
    while (!feof(input)) {
        ++line_number;
        
        char *line = NULL;
        size_t line_size = 0;
        ssize_t line_length = getline(&line, &line_size, input);
        if (line == NULL) {
            fwrite("\n", sizeof(char), 1, output);
            printf("Строка %i невалидна!\n", line_number);
            continue;
        }
        
        size_t out_length = 0;
        char *normalized = normalize_line(line, line_length, &out_length);
        if (!normalized) {
            free(line);
            fwrite("\n", sizeof(char), 1, output);
            printf("Строка %i невалидна!\n", line_number);
            continue;
        }
        
        if (normalized[out_length - 1] != '\n') {
            char *norm;
            asprintf(&norm, "%s\n", normalized);
            if (norm) {
                out_length++;
                free(normalized);
                normalized = norm;
            }
        }
        
        fwrite(normalized, out_length, 1, output);
        printf("%i - %s\n", line_number, normalized);
        free(normalized);
        free(line);
    }
}
