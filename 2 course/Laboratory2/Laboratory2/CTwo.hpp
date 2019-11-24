//
//  CTwo.hpp
//  Laboratory2
//
//  Created by Daniil on 24/11/2019.
//  Copyright © 2019 shad0wdev. All rights reserved.
//

#ifndef CTwo_hpp
#define CTwo_hpp

#include <stdio.h>
#include "COne.hpp"

class CTwo {
private:
    double _doubleVar;
    COne *_classVar = nullptr;
    
public:
    CTwo();
    ~CTwo();
    CTwo(CTwo &object);
    CTwo(double doubleVar, COne *object);
    
    friend std::ostream & operator << (std::ostream &out, const CTwo &object);
    CTwo & operator = (const CTwo &object);
    
    COne *getClass();
    double getDouble();
    
    void setClass(COne *object);
    void setDouble(double doubleVar);
};

#endif /* CTwo_hpp */
