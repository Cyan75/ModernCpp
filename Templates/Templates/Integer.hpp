//
//  Integer.hpp
//  Templates
//
//  Created by Cyan on 2022/04/12.
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
    //Copy assignment
    Integer & operator=(const Integer &obj);
    //Move assignment
    Integer & operator=(Integer &&obj);
    
    int GetValue()const;
    void SetValue(int value);
    ~Integer();

    friend std::ostream & operator <<(std::ostream & out, const Integer &obj);
};
#endif /* Integer_hpp */
