//
//  main.cpp
//  MoveSemantics
//
//  Created by Cyan on 2021/12/28.
//
#include "Integer.hpp"
#include <iostream>

/*
//Returns r-value
int Add(int x, int y) {
    return x + y;
}
//Return l-value
int & Transform(int &x) {
    x *= x;
    return x;
}

void Print(int &x) {
    std::cout << "Print(int&)" << std::endl;
}
void Print(const int &x) {
    std::cout << "Print(const int&)" << std::endl;

}
void Print(int &&x) {
    std::cout << "Print(int &&)" << std::endl;
}*/
Integer Add(const Integer &a, const Integer &b){
    Integer temp ;  //w/ default CTOR
    temp.SetValue(a.GetValue() + b.GetValue()) ;
    return temp ;   //return by value ⟶ temprary w/ copy CTOR
}

int main(int argc, const char * argv[]) {
    /*
    int x = 10; //x is lvalue
    int &ref = x ;  //ref is l-value reference
    int &ref2 = Transform(x) ;  //Transform returns an l-value
    Print(x);   //Binds to function that accepts l-value reference
    
    int &&rv = 8 ;  //rv is r-value reference
    
    int &&rv2 = Add(3,5) ;    //Add returns a temporary (r-value)

    Print(3);    //Binds to function that accepts a temporary, i.e. r-value reference
    */
    Integer a(1), b(3) ;
    a.SetValue(Add(a,b).GetValue()) ;  //Add(a,b) returns a temporary
    
    return 0;
}
