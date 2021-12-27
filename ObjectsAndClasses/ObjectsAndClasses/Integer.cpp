//
//  Integer.cpp
//  ObjectsAndClasses
//
//  Created by Cyan on 2021/12/22.
//

#include "Integer.hpp"
/*
 Integer::Integer(){
    //default CTOR
    m_pInt = new int(0);
    m_value = 0;
}*/
// another way to write default CTOR
Integer::Integer() = default;

//default copy CTOR
//Integer::Integer(const Integer&) = default;

Integer::Integer(const Integer&) = delete;
void Integer::SetVal(int value){
    m_value = value;
}

Integer::Integer(int value){
    m_pInt = new int(value);
}
//Integer::Integer(const Integer &obj){
//    m_pInt = new int(*obj.m_pInt);
//}

int Integer::GetValue() const{
    return *m_pInt;
}
void Integer::SetValue(int value){
    *m_pInt = value;
}
Integer::~Integer(){
    delete m_pInt;
}
