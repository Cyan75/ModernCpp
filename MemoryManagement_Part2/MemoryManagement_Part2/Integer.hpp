//
//  Integer.hpp
//  MemoryManagement_Part2
//
//  Created by Cyan on 2022/01/26.
//
#pragma once
#ifndef Integer_hpp
#define Integer_hpp

class Integer
{
    int *m_pInt;

public:
    //Default constructor
    Integer();
    //Parameterized constructor
    Integer(int value);
    //Copy constructor
    Integer(const Integer &obj);
    //Move constructor
    Integer(Integer &&obj);
    //Copy assignment
    Integer &operator=(const Integer &obj);
    //Move assignment
    Integer &operator=(Integer &&obj);

    int GetValue() const;
    void SetValue(int value);
    ~Integer();
};

#endif /* Integer_hpp */
