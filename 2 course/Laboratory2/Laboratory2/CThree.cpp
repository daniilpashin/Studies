//
//  CThree.cpp
//  Laboratory2
//
//  Created by Даниил on 29/11/2019.
//  Copyright © 2019 shad0wdev. All rights reserved.
//

#include "CThree.hpp"
#include <iostream>

CThree::CThree() {
    std::cout << "CThree::CThree()" << std::endl;
}

CThree::CThree(CThree &object): CTwo(object) {
    std::cout << "CThree::CThree(CThree&)" << std::endl;
    this->setSomeInt(object._someInt);
}

CThree::CThree(const int someInt, const double doubleVar, COne *object): CTwo(doubleVar, object) {
    std::cout << "CThree::CThree(int, double, COne*)" << std::endl;
    this->setSomeInt(someInt);
}

CThree::~CThree() {
    std::cout << "CThree::~CThree()" << std::endl;
}

std::ostream & operator << (std::ostream &out, const CThree &object) {
    out << "<CThree: " << &object << "; ";
    out << "intVar = " << object._someInt << "; doubleVar = " << object._doubleVar << ";";
    out << " object = " << object._object << ";";
    out << ">";
    return out;
}

void CThree::setSomeInt(const int someInt) {
    this->_someInt = someInt;
}

int CThree::getSomeInt() {
    return this->_someInt;
}
