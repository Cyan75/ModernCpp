//
//  main.cpp
//  ObjectsAndClasses
//
//  Created by Cyan on 2021/12/16.
//
# include "Car.hpp"
#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    Car::ShowCount();   //static function does not require any obj
    std::cout << "Hello, World!\n";
    Car a;
    Car b(1);
    Car c(5);
    
    const Car d(2);
    
    a.Dashboard();
    b.Dashboard();
    c.Dashboard();
    d.Dashboard();
    Car::ShowCount();
    return 0;
}
