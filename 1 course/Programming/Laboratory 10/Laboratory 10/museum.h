//
//  museum.h
//  Laboratory 10
//
//  Created by Даниил on 21/02/2019.
//  Copyright © 2019 Даниил. All rights reserved.
//

#ifndef museum_h
#define museum_h

#include <stdio.h>

typedef struct {
    char country[128];
    char city[128];
    char street[128];
    int house_number;
} Address;

typedef struct {
    char name[128];
    Address address;
    int found_year;
    double ticket_price;
} Museum;

Museum *get_spb_museums(int *count);

void print_museum(Museum museum);

#endif /* museum_h */
