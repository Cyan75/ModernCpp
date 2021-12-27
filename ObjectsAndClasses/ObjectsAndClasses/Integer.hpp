//
//  Integer.hpp
//  ObjectsAndClasses
//
//  Created by Cyan on 2021/12/22.
//

#ifndef Integer_hpp
#define Integer_hpp

#include <stdio.h>
class Integer{
    int* m_pInt;
    int m_value;
public:
    Integer();
    Integer(int value);
    void SetVal(int value);
    Integer(const Integer &obj); // for copy constructor - deep copy
    int GetValue() const;
    void SetValue(int value);
    ~Integer();
};
#endif /* Integer_hpp */
