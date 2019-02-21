//
//  date_helper.c
//  Laboratory 10
//
//  Created by Даниил on 21/02/2019.
//  Copyright © 2019 Даниил. All rights reserved.
//

#include "date_helper.h"
#include <time.h>

int get_current_year(void)
{
    time_t rawtime;
    struct tm *timeinfo;
    
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    
    return 1900 + timeinfo->tm_year;
}
