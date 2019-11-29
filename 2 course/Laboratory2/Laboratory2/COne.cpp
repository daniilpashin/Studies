//
//  COne.cpp
//  Laboratory2
//
//  Created by Daniil on 24/11/2019.
//  Copyright © 2019 shad0wdev. All rights reserved.
//

#include "COne.hpp"
#include <iostream>

#pragma mark  - Constructors/Destructors
COne::COne() {
    std::cout << "COne::COne()" << std::endl;
}

COne::COne(long longVar, std::string *stringVar) {
    std::cout << "COne::COne(long, string)" << std::endl;
    this->setLong(longVar);
    this->setString(stringVar);
}

COne::~COne() {
    std::cout << "COne::~COne()" << std::endl;
    if (this->_stringVar != nullptr) {
        delete this->_stringVar;
    }
}

COne::COne(const COne &object) {
    this->setString(object._stringVar);
    this->setLong(object._longVar);
}

#pragma mark - Operators
std::ostream & operator << (std::ostream &out, const COne &object) {
    out << "<COne: " << &object << "; ";
    out << "longVar = " << object._longVar << "; stringVar = ";
    out << ((object._stringVar != nullptr) ? *object._stringVar : "nullptr");
    out << ">";
    return out;
}

COne & COne::operator = (const COne &object)
{
#ifdef DEBUG
    std::cout << "this = " << this << std::endl;
#endif
    
    if (this != &object) {
        this->setLong(object._longVar);
        this->setString(object._stringVar);
    }
    
    return *this;
}

#pragma mark - Methods
long COne::getLong() {
    return this->_longVar;
}

std::string *COne::getString() {
    return (this->_stringVar != nullptr) ? new std::string(*this->_stringVar) : nullptr;
}

void COne::setString(std::string *stringVar) {
    if (stringVar == nullptr) {
        throw std::invalid_argument("stringVar must be a not null pointer to std::string!");
    }
    
    if (this->_stringVar != nullptr) {
        delete this->_stringVar;
    }
    
    this->_stringVar = new std::string(*stringVar);
}

void COne::setLong(long longVar) {
    this->_longVar = longVar;
}
