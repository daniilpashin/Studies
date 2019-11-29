//
//  CThree.hpp
//  Laboratory2
//
//  Created by Даниил on 29/11/2019.
//  Copyright © 2019 shad0wdev. All rights reserved.
//

#ifndef CThree_hpp
#define CThree_hpp

#include <stdio.h>
#include "CTwo.hpp"

class CThree: public CTwo {
protected:
    int _someInt;
    
public:
    CThree();
    ~CThree();
    CThree(const int someInt, const double doubleVar, COne *object);
    
    friend std::ostream & operator << (std::ostream &out, const CThree &object);
    
    int getSomeInt();
    void setSomeInt(const int someInt);
};

#endif /* CThree_hpp */
