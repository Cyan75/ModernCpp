//
//  Integer.hpp
//  Operator Overloading
//
//  Created by Cyan on 2022/01/11.
//

#ifndef Integer_hpp
#define Integer_hpp

#include <iostream>
class Integer {
    int *m_pInt;
public:
    //Default constructor
    Integer();
    //Parameterized constructor
    /*explicit */ Integer(int value);
    //Copy constructor
    Integer(const Integer &obj);
    //Move constructor
    Integer(Integer &&obj);
    int GetValue()const;
    void SetValue(int value);
    ~Integer();
    Integer & operator ++();
    Integer operator ++(int);
    bool operator ==(const Integer &a)const;

    //Copy assignment
    Integer & operator =(const Integer &a);
    //Move assignment
    Integer & operator =(Integer &&a);
    Integer operator +(const Integer & a)const;

    void operator ()();
    operator int(); //type conversion opertor
//    explicit operator int(); : the compiler can never use implicit conversion
};
Integer operator +(int x, const Integer &y);
std::ostream & operator <<(std::ostream & out, const Integer &a);
std::istream & operator >> (std::istream &input, Integer &a);

#endif /* Integer_hpp */
