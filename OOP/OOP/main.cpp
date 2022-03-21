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

//    Dog d;
//    d.Eat();
//    d.Run();
//    d.Speak();
    
    Account acc("Cyan", 1000);
    std::cout <<"initial balance : "<<acc.GetBalance() << std::endl;
    acc.Deposit(200);
    acc.Withdraw(380);
    std::cout <<"Balance : "<<acc.GetBalance()<<std::endl; 

//    Checking ch1("David", 200, 50);
        Checking ch1("David", 200);
    ch1.Withdraw(170);
    std::cout <<"Balance : "<<ch1.GetBalance()<<std::endl;
    
//    Checking ch("Bob", 700, 50);
//    Transact(&ch);
    return 0;
}
