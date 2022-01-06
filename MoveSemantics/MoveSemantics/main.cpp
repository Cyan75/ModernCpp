//
//  main.cpp
//  MoveSemantics
//
//  Created by Cyan on 2021/12/28.
//
#include "Integer.hpp"
#include <iostream>
class Number{
    Integer m_Value{};
public:
    Number() = default; //with no initialisation list
    Number(int value): m_Value{value}{
    }
    //if there is a copy CTOR here, any move operation will not happen
//    Number(const Number &obj): m_Value{obj.m_Value}{
//
//    }
    //if there is a destructor here,any move operation will not happen
//    ~Number(){
//
//    }
    //if there is a customised move operation here,
    //any copy operation and move operation will be deleted
//    Number(Number &&obj):m_Value{std::move(obj.m_Value)}{
//
//    }
    //or
    //DEFAULT specifier : internally call the move assignment of Integer
    //synthesized automatically
    Number(Number &&obj) = default; //move CTOR : synthesized automatically
    Number(const Number &obj) = default; //copy CTOR : synthesized automatically
    Number & operator=(Number&&) = default; // move assignment : synthesized automatically
    Number & operator=(const Number&) = default; // copy assignment : synthesized automatically
};
Number CreateNumber(int num){
    Number n{num};
    return n;
}
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
/*
Integer Add(const Integer &a, const Integer &b){
    Integer temp ;  //w/ default CTOR
    temp.SetValue(a.GetValue() + b.GetValue()) ;
    return temp ;   //return by value ⟶ temprary w/ copy CTOR
}
*/
Integer Add(int a, int b){
    Integer temp(a+b);  // an obj created by value
    /*
    return temp;        // invoking Add will make another obj to store temp
                        // Named return value optimisation : the temp obj returned by value is elided
    */
    return Integer(a+b);    // Retrun value optimisation : a batter implementation
                            // the obj will be elided too here
     
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
    /*
    Integer a(1), b(3) ;
    a.SetValue(Add(a,b).GetValue()) ;  //Add(a,b) returns a temporary
    */
//    Number n1{1};   // L-value : the compiler uses copy CTOR
//    std::cout<<std::endl;
//    auto n2(n1);    //internally invoke the copy CTOR of Integer
//    std::cout<<std::endl;
//    n2 = n1;    //internally invoke copy assignmennt of Integer
//    std::cout<<std::endl;
    
    /*
    auto n3{CreateNumber(3)};   // CreateNumber(3) is an R-value : compiler will choose move CTOR
                                // Number does not have move CTOR
                                // the compiler will invoke the move CTOR of Integer
    std::cout<<std::endl;
    n3 = CreateNumber(3);
    */
    Integer a = 3;
    // the same as
//    Integer a = Integer(3);
    // invokes a parametrised CTOR : elision
    // the compiler elides this object Integer(3)
    // compilation with -fno-elide-constructors keeps the elision from occurring. : this will invoke a move CTOR instead
    
    Integer b = Add(3, 5);
    // elision : this will invoke single CTOR call
    // no elision : this will invoke total 3 obj CTOR calls  - two from Add
    
    std::cout<<std::endl;
    return 0;
}
