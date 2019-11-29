//
//  CFour.hpp
//  Laboratory2
//
//  Created by Даниил on 29/11/2019.
//  Copyright © 2019 shad0wdev. All rights reserved.
//

#ifndef CFour_hpp
#define CFour_hpp

#include <stdio.h>
#include "CThree.hpp"

class CFour: public CThree {
protected:
    char *_someCharString = nullptr;
    
public:
    CFour();
    ~CFour();
    CFour(const char *someChar, const int someInt, const double doubleVar, COne *object);
    
    friend std::ostream & operator << (std::ostream &out, const CFour &object);
    
    char *getSomeCharString();
    void setSomeCharString(const char *someCharString);
};

#endif /* CFour_hpp */
