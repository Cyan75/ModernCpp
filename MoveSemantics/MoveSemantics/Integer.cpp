//
//  Integer.cpp
//  MoveSemantics
//
//  Created by Cyan on 2021/12/28.
//

#include "Integer.hpp"
#include <iostream>
Integer::Integer() {
    std::cout << "Integer()" << std::endl;
    m_pInt = new int(0);
}

Integer::Integer(int value) {
    std::cout << "Integer(int)" << std::endl;
    m_pInt = new int(value);
}

//a copy constructor
Integer::Integer(const Integer & obj) {
    std::cout << "Integer(const Integer&)" << std::endl;
    m_pInt = new int(*obj.m_pInt);
}

//a move constructor by shallow copy
Integer::Integer(Integer && obj) {
    std::cout << "Integer(int&&)" << std::endl;
    m_pInt = obj.m_pInt;
    obj.m_pInt = nullptr;
}

int Integer::GetValue() const {
    return *m_pInt;
}

void Integer::SetValue(int value) {
    *m_pInt = value;
}

Integer::~Integer() {
    std::cout << "~Integer()" << std::endl;
    delete m_pInt;
}






