//
//  Integer.hpp
//  MoveSemantics
//
//  Created by Cyan on 2021/12/28.
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
    Integer(int value);
    //Copy constructor
    Integer(const Integer &obj);
    //Move constructor
    Integer(Integer &&obj);
    int GetValue()const;
    void SetValue(int value);
    ~Integer();

};

#endif /* Integer_hpp */
