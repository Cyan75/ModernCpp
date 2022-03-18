//
//  Checking.hpp
//  OOP
//
//  Created by Cyan on 2022/03/18.
//
#pragma once
#ifndef Checking_hpp
#define Checking_hpp

#include "Account.hpp"
class Checking :
    public Account {
    float m_MinimumBalance;
public:
    using Account::Account;
    Checking(const std::string &name, float balance, float minbalance);
    ~Checking();
    void Withdraw(float amount)override;
    float GetMinimumBalance()const;
};
#endif /* Checking_hpp */
