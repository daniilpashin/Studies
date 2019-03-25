//
//  museum.c
//  Laboratory 10
//
//  Created by Даниил on 21/02/2019.
//  Copyright © 2019 Даниил. All rights reserved.
//

#include "museum.h"
#include <stdlib.h>

Museum *get_spb_museums(int *count)
{
    *count = 3;
    Museum *museums = malloc(*count * sizeof(Museum));
    
    Address grm_address = {"Россия", "Санкт-Петербург", "Ул. Цветочная", 1};
    Museum grand_maket = {"Гранд Макет", grm_address, 1953, 480.0};
    museums[0] = grand_maket;
    
    Address issaac_address = {"Россия", "Санкт-Петербург", "Исаакиевская пл.", 4};
    Museum issaac = {"Исаакиевский собор", issaac_address, 1928, 250.0};
    museums[1] = issaac;
    
    Address hermitage_addr = {"Россия", "Санкт-Петербург", "Дворцовая пл.", 2};
    Museum hermitage = {"Эрмитаж", hermitage_addr, 1764, 400.0};
    museums[2] = hermitage;
    
    return museums;
}

void print_museum(Museum museum)
{
    Address address = museum.address;
    printf("%s: '%s, %s, %s %i'; Год основания: %i; Цена билета: %.2f₽\n", museum.name,
           address.country, address.city,
           address.street, address.house_number,
           museum.found_year, museum.ticket_price);
}
