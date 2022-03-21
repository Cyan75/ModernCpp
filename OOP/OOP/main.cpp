//
//  main.cpp
//  OOP
//
//  Created by Cyan on 2022/03/18.
//

#include <iostream>
#include "Savings.hpp"
#include "Checking.hpp"
#include "Transaction.hpp"
#include <typeinfo>


class Animal{
public:
    void Eat(){
        std::cout<<" Animal eating "<<std::endl;
    }
    void Run(){
        std::cout<<" Animal running "<<std::endl;
    }
    void Speak(){
        std::cout<<" Animal speaking "<<std::endl;
    }
};
class Dog : public Animal{
public:
    void Eat(){
        std::cout<<" Dog eating meat "<<std::endl;
    }
    void Speak(){
        std::cout<<" Dog barking "<<std::endl;
    }
};


int main(int argc, const char * argv[]) {

    Dog d;
    d.Eat();
    d.Run();
    d.Speak();
    
//    Checking ch("Bob", 100, 50);
//    Transact(&ch);
    return 0;
}
