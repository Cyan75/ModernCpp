//
//  Transaction.hpp
//  OOP
//
//  Created by Cyan on 2022/03/18.
//
#pragma once
#ifndef Transaction_hpp
#define Transaction_hpp

#include "Account.hpp"
void Transact(Account *pAccount);
void Transact(std::shared_ptr<Account> *shr_pAccount);

#endif /* Transaction_hpp */
