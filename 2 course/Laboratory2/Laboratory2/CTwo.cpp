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
    
}

CTwo::CTwo(CTwo &object) {
    this->setClass(object._classVar);
    this->setDouble(object._doubleVar);
}

CTwo::CTwo(const double doubleVar, COne *object) {
    this->setClass(object);
    this->setDouble(doubleVar);
}

CTwo::~CTwo() {
    if (this->_classVar != nullptr) {
        std::cout << "Removing class " << this->_classVar << std::endl;
        delete this->_classVar;
    }
}

#pragma mark - Operators
std::ostream & operator << (std::ostream &out, const CTwo &object) {
    out << "<CTwo: " << &object << "; ";
    out << "doubleVar = " << object._doubleVar << "; class = ";
    (object._classVar != nullptr) ? (out << object._classVar) : (out << "nullptr");
    out << ">";
    return out;
}
CTwo & CTwo::operator = (const CTwo &object)
{
#ifdef DEBUG
    std::cout << "this = " << this << std::endl;
#endif
    
    if (this != &object) {
        this->setClass(object._classVar);
        this->setDouble(object._doubleVar);
    }
    
    return *this;
}

#pragma mark - Methods
COne *CTwo::getClass() {
    return this->_classVar;
}

double CTwo::getDouble() {
    return this->_doubleVar;
}

void CTwo::setDouble(double doubleVar) {
    this->_doubleVar = doubleVar;
}

void CTwo::setClass(COne *object) {
    if (object == nullptr) {
        throw std::invalid_argument("object must be a not null pointer to COne!");
    }
    
    if (this->_classVar != nullptr) {
        delete this->_classVar;
    }
    
    this->_classVar = object;
}
