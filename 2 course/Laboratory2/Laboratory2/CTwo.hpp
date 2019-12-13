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
protected:
    double _doubleVar;
    COne _object;
    
public:
    CTwo();
    virtual ~CTwo();
    CTwo(CTwo &object);
    CTwo(double doubleVar, COne *object);
    
    friend std::ostream & operator << (std::ostream &out, const CTwo &object);
    CTwo & operator = (CTwo &object);
    
    virtual void print();
    
    COne getObject();
    double getDouble();
    
    void setObject(COne &object);
    void setDouble(double doubleVar);
};

#endif /* CTwo_hpp */
