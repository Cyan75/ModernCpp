//
//  Savings.cpp
//  OOP
//
//  Created by Cyan on 2022/03/18.
//

#include "Savings.hpp"
#include <iostream>


//must invoke the base class CTOR 
Savings::Savings(const std::string & name, float balance, float rate):Account(name, balance), m_Rate(rate) {
    std::cout << "Savings(const std::string &, float)" << std::endl;
}

Savings::~Savings() {
    std::cout << "~Savings()" << std::endl;
}

float Savings::GetInterestRate() const {
    return m_Rate;
}

void Savings::AccumulateInterest() {
    m_Balance += (m_Balance * m_Rate);
}

