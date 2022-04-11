//
//  PerfectForwardMain.cpp
//  Templates
//
//  Created by Cyan on 2022/04/12.
//

#include "Integer.hpp"
#include <iostream>

class Employee{
    std::string m_Name;
    Integer m_Id;
public:
    Employee(const std::string &name, const Integer &id) : m_Name{name}, m_Id{id} {
        std::cout<<"Employee(const std::string &name, const Integer &id)" << std::endl;
    }
//    Employee(std::string &&name, Integer &&id): m_Name{name}, m_Id{id /* not temporal : L-value -> copy CTOR */}{
//        std::cout<<"Employee(std::string &&name, Integer &&id)"<<std::endl;
//    }
    Employee(std::string &&name, Integer &&id): m_Name{name}, m_Id{std::move(id)} {
        std::cout<<"Employee(std::string &&name, Integer &&id)"<<std::endl;
    }
};

int main(){
    Employee emp{"Jake", 100};
    return 0;
}
