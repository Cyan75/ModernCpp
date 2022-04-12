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
    //
    template<typename T1, typename T2>
    Employee(T1 &&name, T2 &&id): m_Name{std::forward<T1>(name)}, m_Id{std::forward<T2>(id)}{
        std::cout <<"Employee(T1 &&name, T2 &&id)"<<std::endl;
    }
};

template<typename T1, typename T2>
Employee *Create(T1 &&a, T2 &&b){
    return new Employee(a,std::forward<T2>(b));
}
int main(){
//    Employee emp1{"Jake", 100};
//    std::string name = "Cyan";
//    Employee emp2{name, 75};    //even though the second argument is temporary, Id obj is initialised with this temporary, then copied to the attribute of the linitialiser list of copy CTOR
//    Employee emp3{"Yu", Integer{10}};   // this invokes copy CTOR
//    Integer val{500};
//    Employee emp4{std::string{"Kumar"},val};    //name is an R-value reference : move CTOR will be invoked due to std::forward
                                                //Id is an L-value reference : copy CTOR will be invked due to std::forward
    auto emp = Create("Jane", Integer{250});
    return 0;
}
