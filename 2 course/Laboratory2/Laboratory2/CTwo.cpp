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
    std::cout << "CTwo::CTwo(CTwo&)" << std::endl;
    this->setObject(object._object);
    this->setDouble(object._doubleVar);
}

CTwo::CTwo(const double doubleVar, COne *object) {
    std::cout << "CTwo::CTwo(double, COne*)" << std::endl;
    this->setObject(*object);
    this->setDouble(doubleVar);
}

CTwo::~CTwo() {
    std::cout << "CTwo::~CTwo()" << std::endl;
}

#pragma mark - Operators
std::ostream & operator << (std::ostream &out, const CTwo &object) {
    out << "<CTwo: " << &object << "; ";
    out << "doubleVar = " << object._doubleVar << "; object = " << object._object << ";";
    out << ">";
    return out;
}

CTwo & CTwo::operator = (CTwo &object)
{
    std::cout << "this = " << this << std::endl;
    
    if (this != &object) {
        this->setObject(object._object);
        this->setDouble(object._doubleVar);
    }
    
    return *this;
}

void CTwo::print() {
    std::cout << "CTwo::print()" << std::endl;
    std::cout << *this << std::endl;
}

#pragma mark - Methods
COne CTwo::getObject() {
    return this->_object;
}

double CTwo::getDouble() {
    return this->_doubleVar;
}

void CTwo::setDouble(double doubleVar) {
    this->_doubleVar = doubleVar;
}

void CTwo::setObject(COne &object) {
    this->_object = object;
}
