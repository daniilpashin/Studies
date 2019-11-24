//
//  main.cpp
//  Laboratory2
//
//  Created by Daniil on 24/11/2019.
//  Copyright © 2019 shad0wdev. All rights reserved.
//

#include <iostream>
#include "COne.hpp"
#include "CTwo.hpp"

void testNullPtr() {
    COne first;
    
    try {
        std::string *str = nullptr;
        first.setString(str);
    } catch (std::exception &e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    
    std::cout << first << std::endl;
}

void testCopy() {
    std::string str = std::string("TEST");
    COne first(10, &str);
    COne second;
    second = first;
    
    std::cout << first << std::endl;
    std::cout << second << std::endl;
}

int main(int argc, const char * argv[]) {
    
//    std::cout << "Passing nullptr:" << std::endl;
//    testNullPtr();
//    std::cout << std::endl;
//    
//    std::cout << "Copying:" << std::endl;
//    testCopy();
//    std::cout << std::endl;
    
    std::string str = std::string("TEST");
    COne *first = new COne(10, &str);
    std::cout << first << std::endl;
    CTwo second(0.0, first);
    
    
    return 0;
}
