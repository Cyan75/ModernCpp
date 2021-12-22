//
//  main.cpp
//  ObjectsAndClasses
//
//  Created by Cyan on 2021/12/16.
//
# include "Car.hpp"
# include "Integer.hpp"
#include <iostream>

void Print(Integer i){  //2. a copy of an obj is passed by value to a function
    std::cout<< "integer : "<<i.GetValue()<<std::endl;
}

Integer Add(int x, int y){
    return Integer(x+y);    //3. copy of the obj is returned in value
}

int main(int argc, const char * argv[]) {
    /*
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
     */
    
    Integer i1(5);
    Integer i2(i1);   //1. copy constructor by manually creating one
    Integer *i3 = new Integer(1);
    // copy constructor : use deep copy(copying the value) not shallow copy(copying the address)
    // int *p1 = new int(5);
    // int *p2 = p1;    // shallow
    // int *p3 = new int(*p1);  //deep
    Print(i1);
    Print(i2);
    Print(*i3);
    delete i3;
    return 0;
}
