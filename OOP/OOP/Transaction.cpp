//
//  Transaction.cpp
//  OOP
//
//  Created by Cyan on 2022/03/18.
//

#include "Transaction.hpp"
#include <iostream>
#include "Checking.hpp"
void Transact(Account * pAccount) {
    std::cout << "Transaction started" << std::endl;
    std::cout << "Initial balance:" << pAccount->GetBalance() << std::endl;
    pAccount->Deposit(100);
    pAccount->AccumulateInterest();
    //if (typeid(*pAccount) == typeid(Checking)) {
    //    Checking *pChecking = static_cast<Checking*>(pAccount);
    //    std::cout << "Minimum balance of Checking:" << pChecking->GetMinimumBalance() << std::endl;
    //}

    Checking *pChecking = dynamic_cast<Checking*>(pAccount);
    if (pChecking != nullptr) {
        std::cout << "Minimum balance of Checking:" << pChecking->GetMinimumBalance() << std::endl;
    }

    pAccount->Withdraw(170);
    std::cout << "Interest rate:" << pAccount->GetInterestRate() << std::endl;
    std::cout << "Final balance:" << pAccount->GetBalance() << std::endl;
}


