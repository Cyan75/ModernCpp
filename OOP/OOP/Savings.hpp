//
//  Savings.hpp
//  OOP
//
//  Created by Cyan on 2022/03/18.
//
#pragma once
#ifndef Savings_hpp
#define Savings_hpp

#include "Account.hpp"
class Savings :
    public Account {
    float m_Rate; // used to accumulate the interest into the Saving account
public:
    Savings(const std::string &name, float balance, float rate);
    ~Savings();
    float GetInterestRate()const override;
    void AccumulateInterest() override;
};


#endif /* Savings_hpp */
