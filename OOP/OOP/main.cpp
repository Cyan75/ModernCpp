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

int main(int argc, const char * argv[]) {
    Checking ch("Bob", 100, 50);
    Transact(&ch);
    std::unique_ptr<Checking> chOscar {new Checking{"Oscar", 200,100} };
    auto chCyan = std::make_unique<Checking>("Cyan", 50,50);
    Transact(&chOscar);
    Transact(&chCyan);

    return 0;
}
