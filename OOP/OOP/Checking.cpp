//
//  Checking.cpp
//  OOP
//
//  Created by Cyan on 2022/03/18.
//

#include "Checking.hpp"
#include <iostream>
//Checking::Checking(const std::string &name, float balance):Account(name, balance){
//    Checking(name, balance, 50);
//}
Checking::Checking(const std::string &name, float balance, float minbalance):
m_MinimumBalance(minbalance), Account(name, balance){
}

Checking::~Checking() {
}

void Checking::Withdraw(float amount) {
    if ((m_Balance - amount)  > m_MinimumBalance) {
        Account::Withdraw(amount);//a child class can always call base class' function
    }
    else {
        std::cout << "Invalid amount, balance is less than the required minimum" << std::endl;
    }
}

float Checking::GetMinimumBalance() const {
    return m_MinimumBalance;
}

