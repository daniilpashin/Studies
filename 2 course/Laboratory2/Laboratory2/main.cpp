//
//  main.cpp
//  Laboratory2
//
//  Created by Daniil on 24/11/2019.
//  Copyright © 2019 shad0wdev. All rights reserved.
//

#include <iostream>
#include "CFour.hpp"

void printAll(CTwo **array, int count);
void printAll(CTwo **array, int count) {
    for (int i = 0; i < count; i++) {
        std::cout << "Object "  << i << ": " << *(array[i]) << std::endl;
    }
}

int main(int argc, const char * argv[]) {
    
    std::string str = std::string("TEST");
    COne *first = new COne(10, &str);
    
    std::cout << std::endl;
    
//    CTwo *second = new CTwo(30.0, first);
//    second->print();
//    delete second;
//    
//    std::cout << std::endl;
//    
//    const char *test_string1 = "test string";
//    CFour *three = new CFour(test_string1, 2, 30.0, first);
//    three->print();
//    three = (CFour*)second;
//    three->print();
//    std::cout << *three << std::endl;
//    delete three;
    
    std::cout << std::endl;
    std::cout << std::endl;
    
    const char *test_string = "test string";
    
    const int array_count = 10;
    CTwo **objects = new CTwo*[array_count];
    for (int i = 0; i < array_count; i++) {
        if (i % 3 == 0) {
            objects[i] = new CFour(test_string, 2, 30.0, first);
        } else if (i % 2 == 0) {
            objects[i] = new CThree(2, 30.0, first);
        } else {
            objects[i] = new CTwo(30.0, first);
        }
    }
    
    printAll(objects, array_count);
    
    for (int i = 0; i < array_count; i++) {
        delete objects[i];
        std::cout << std::endl;
    }
    delete [] objects;
    
//    CFour *four = new CFour(test_string, 2, 30.0, first);
//    std::cout << *four << std::endl;
//    delete four;
    
    std::cout << std::endl;
    
    delete first;
    
    return 0;
}
