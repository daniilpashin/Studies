//
//  main.cpp
//  Laboratory2
//
//  Created by Daniil on 24/11/2019.
//  Copyright © 2019 shad0wdev. All rights reserved.
//

#include <iostream>
#include "CFour.hpp"

int main(int argc, const char * argv[]) {
    
    std::string str = std::string("TEST");
    COne *first = new COne(10, &str);
    
    std::cout << std::endl;
    
    CTwo *second = new CTwo(30.0, first);
    std::cout << *second << std::endl;
    delete second;
    
    std::cout << std::endl;
    
    CThree *three = new CThree(2, 30.0, first);
    std::cout << *three << std::endl;
    delete three;
    
    std::cout << std::endl;
    
    const char *test_string = "test string";
    CFour *four = new CFour(test_string, 2, 30.0, first);
    std::cout << *four << std::endl;
    delete four;
    
    std::cout << std::endl;
    
    delete first;
    
    return 0;
}
