//
//  COne.hpp
//  Laboratory2
//
//  Created by Daniil on 24/11/2019.
//  Copyright © 2019 shad0wdev. All rights reserved.
//

#ifndef COne_hpp
#define COne_hpp

#include <stdio.h>
#include <string>

class COne {
private:
    long _longVar;
    std::string *_stringVar = nullptr;
    
public:
    COne();
    ~COne();
    COne(COne &object);
    COne(long longVar, std::string *stringVar);
    
    friend std::ostream & operator << (std::ostream &out, const COne &object);
    COne & operator = (const COne &object);
    
    long getLong();
    std::string *getString();
    
    void setLong(long longVar);
    void setString(std::string *stringVar);
};

#endif /* COne_hpp */
