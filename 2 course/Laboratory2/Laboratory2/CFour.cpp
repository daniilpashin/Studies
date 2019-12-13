//
//  CFour.cpp
//  Laboratory2
//
//  Created by Даниил on 29/11/2019.
//  Copyright © 2019 shad0wdev. All rights reserved.
//

#include "CFour.hpp"
#include <iostream>

CFour::CFour() {
    std::cout << "CFour::CFour()" << std::endl;
}

CFour::CFour(const char *someCharString, const int someInt, const double doubleVar, COne *object)
: CThree(someInt, doubleVar, object){
    std::cout << "CFour::CFour(char*, int, double, COne*)" << std::endl;
    this->setSomeCharString(someCharString);
}

CFour::~CFour() {
    std::cout << "CFour::~CFour()" << std::endl;
    if (this->_someCharString != nullptr) {
        std::free(this->_someCharString);
        this->_someCharString = nullptr;
    }
}

std::ostream & operator << (std::ostream &out, const CFour &object) {
    out << "<CFour: " << &object << ";";
    out << " charString=" << object._someCharString << "; intVar = " << object._someInt << ";";
    out << " doubleVar = " << object._doubleVar << "; object = " << object._object << ";";
    out << ">";
    return out;
}

void CFour::print() {
    std::cout << "CFour::print()" << std::endl;
    std::cout << *this << std::endl;
}

void CFour::setSomeCharString(const char *someCharString) {
    if (this->_someCharString != nullptr) {
        std::free(this->_someCharString);
    }
    
    this->_someCharString = (someCharString != nullptr) ? strdup(someCharString) : nullptr;
}

char *CFour::getSomeCharString() {
    if (this->_someCharString == nullptr) {
        return nullptr;
    }
    
    return strdup(this->_someCharString);
}
