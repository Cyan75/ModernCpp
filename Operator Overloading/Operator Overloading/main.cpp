//
//  main.cpp
//  Operator Overloading
//
//  Created by Cyan on 2022/01/11.
//

#include "Integer.hpp"
#include <iostream>
#include <memory>

// an object instead of a point
// an object behaves like a pointer
class IntPtr {
    Integer *m_p;
public:
    IntPtr(Integer *p) :m_p(p) {

    }
    ~IntPtr() {
        delete m_p;
    }
    Integer *operator ->() {
        return m_p;
    }
    Integer & operator *() {
        return *m_p;
    }
};
void Process(Integer val) {
    
}

void Process(std::unique_ptr<Integer> ptr){
    std::cout << ptr->GetValue() << std::endl;
}

void Process(std::shared_ptr<Integer> ptr){
    std::cout << ptr->GetValue() << std::endl; //ref count of shared pointer incremented
} //ref count decremented when ptr is destroyed

void CreateInteger() {
    IntPtr p1 = new Integer(5);
    (*p1).SetValue(4);
    p1->SetValue(3);
    
     std::unique_ptr<Integer> p(new Integer);
    //auto p2(p);
    (*p).SetValue(2);
    //std::cout << p->GetValue() << std::endl;
//    Process(p);// won't work cannot copy a unique pointer
    Process(std::move(p));  //unique pointer can be moved
    
    std::shared_ptr<Integer> ps(new Integer);
    (*ps).SetValue(10);
    Process(ps);    //ref count of shared pointer incremented
    std::cout << ps->GetValue() << std::endl; 
    
} // the shared pointer ps is destroyed at the end of the scope
// the reference count is decremented to 0, the underlying resource will be released

int main(int argc, const char * argv[]) {
//    Integer a(3);
    /*auto b(std::move(a));
    std::cout << a << std::endl;*/
//    Process(std::move(a));
    CreateInteger();
    return 0;
}
