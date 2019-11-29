//
//  CTwo.cpp
//  Laboratory2
//
//  Created by Daniil on 24/11/2019.
//  Copyright © 2019 shad0wdev. All rights reserved.
//

#include "CTwo.hpp"
#include <iostream>


#pragma mark  - Constructors/Destructors
CTwo::CTwo() {
    std::cout << "CTwo::CTwo()" << std::endl;
}

CTwo::CTwo(CTwo &object) {
    std::cout << "CTwo::CTwo(CTwo)" << std::endl;
    this->setObject(object._object);
    this->setDouble(object._doubleVar);
}

CTwo::CTwo(const double doubleVar, COne *object) {
    std::cout << "CTwo::CTwo(double, COne)" << std::endl;
    this->setObject(object);
    this->setDouble(doubleVar);
}

CTwo::~CTwo() {
    std::cout << "CTwo::~CTwo()" << std::endl;
    if (this->_object != nullptr) {
        delete this->_object;
    }
}

#pragma mark - Operators
std::ostream & operator << (std::ostream &out, const CTwo &object) {
    out << "<CTwo: " << &object << "; ";
    out << "doubleVar = " << object._doubleVar << "; class = ";
    (object._object != nullptr) ? (out << *object._object) : (out << "nullptr");
    out << ">";
    return out;
}

CTwo & CTwo::operator = (const CTwo &object)
{
#ifdef DEBUG
    std::cout << "this = " << this << std::endl;
#endif
    
    if (this != &object) {
        this->setObject(object._object);
        this->setDouble(object._doubleVar);
    }
    
    return *this;
}

#pragma mark - Methods
COne *CTwo::getObject() {
    return this->_object;
}

double CTwo::getDouble() {
    return this->_doubleVar;
}

void CTwo::setDouble(double doubleVar) {
    this->_doubleVar = doubleVar;
}

void CTwo::setObject(COne *object) {
    if (object == nullptr) {
        throw std::invalid_argument("object must be a not null pointer to COne!");
    }
    
    if (this->_object != nullptr && object != this->_object) {
        delete this->_object;
    }
    
    this->_object = object;
}
