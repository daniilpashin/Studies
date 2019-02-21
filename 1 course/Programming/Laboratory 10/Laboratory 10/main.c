//
//  main.c
//  Laboratory 10
//
//  Created by Даниил on 21/02/2019.
//  Copyright © 2019 Даниил. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "museum.h"
#include "date_helper.h"

int main(int argc, const char * argv[])
{
    int years_old = 0;
    printf("Введите минимальный срок работы музея (в годах):\n");
    scanf("%i", &years_old);
    printf("\nМузеи, чей срок работы превышает %i лет:\n", years_old);
    
    int museums_count = 0;
    Museum *museums = get_spb_museums(&museums_count);
    
    int current_year = get_current_year();
    for (int i = 0; i < museums_count; i++) {
        Museum museum = museums[i];
        
        if (current_year - museum.found_year > years_old) {
            print_museum(museum);
        }
    }
    
    free(museums);
    
    printf("\n");
    return 0;
}
