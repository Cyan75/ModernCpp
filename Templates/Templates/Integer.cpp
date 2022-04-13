//
//  Integer.cpp
//  Templates
//
//  Created by Cyan on 2022/04/12.
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
//Copy assignment
Integer & Integer::operator=(const Integer &obj){
    std::cout << "operator=(const Integer &obj)" << std::endl;
    if(this == & obj){
        return *this;
    }
    delete m_pInt;
    m_pInt = new int(*obj.m_pInt);
    return *this;
}
//Move assignment
Integer & Integer::operator=(Integer &&obj){
    std::cout << "operator=(Integer &&obj)" << std::endl;
    if(this == & obj){
        return *this;
    }
    delete m_pInt;
    m_pInt = obj.m_pInt;
    obj.m_pInt = nullptr;
    return *this;
}

int Integer::GetValue() const {
    return *m_pInt;
}

void Integer::SetValue(int value) {
    if(m_pInt == nullptr)// new memory address created for obj
        m_pInt = new int{};
    *m_pInt = value;
}

Integer::~Integer() {
    std::cout << "~Integer()" << std::endl;
    delete m_pInt;
}

std::ostream & operator<<(std::ostream & out, const Integer & obj)
{
    out << *obj.m_pInt;
    return out;
}
