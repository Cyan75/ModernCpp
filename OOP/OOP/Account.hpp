//
//  Account.hpp
//  OOP
//
//  Created by Cyan on 2022/03/18.
//
// a base class

#pragma once
#ifndef Account_hpp
#define Account_hpp

#include <string>
class Account {
    std::string m_Name;
    int m_AccNo;
    static int s_ANGenerator;
protected:
    float m_Balance;
public:
    Account(const std::string &name, float balance);
    virtual ~Account();
    const std::string GetName()const;
    float GetBalance()const;
    int GetAccountNo()const;

    virtual void AccumulateInterest();
    virtual void Withdraw(float amount);
    void Deposit(float amount);
    virtual float GetInterestRate()const;
};

#endif /* Account_hpp */
