//
//  main.cpp
//  ObjectOrientedProgramming
//
//  Created by Cyan on 2022/03/17.
//

#include <iostream>
#include "Savings.hpp"
#include "Checking.hpp"
#include "Transaction.hpp"
#include <typeinfo>

int main(int argc, const char * argv[]) {
    Checking ch("Bob", 100, 50);
    Transact(&ch);
    return 0;
}
