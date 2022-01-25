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

void Print(Integer a){
    std::cout<<a.GetValue()<<std::endl;
}

//void Print(const Integer &a){
//    std::cout<<a.GetValue()<<std::endl;
//}

class Product{
    Integer m_Id;   //Integer()
public:
    //Assignment
//    Product(const Integer &id){
//        std::cout << "Product(const Integer &id)" << std::endl;
//        m_Id = id;  // assignment operator for Integer
//    }
    // or Member Initialiser List
     Product(const Integer &id) : m_Id(id){
         std::cout << "Product(const Integer &id)" << std::endl;
     }
    
    ~Product(){
        std::cout << "~Product()" << std::endl;
    }
};

int main(int argc, const char * argv[]) {
    /*auto b(std::move(a));
    std::cout << a << std::endl;*/
//    Process(std::move(a));
//    CreateInteger();
    
    /*
    //----------------TYPE CONVERSION : primitive to primitive
    int a = 5, b = 3;
    float f = static_cast<float>(a)/b;
//    char *p = static_cast<char*>(&a);// not working
    // what is going to be done : cast a pointer to an integer to a pointer to a char
    char *p = reinterpret_cast<char*>(&a);
    const int x = 1;
    int *ip = const_cast<int*>(&x);
    */
    
    /*
    //----------------TYPE CONVERSION : primitive to user-defined
    Integer a1(3);
    
    //Initialisation
    Integer a2 = 5;
    //cannot use explicit CTOR for implicit type conversion
    
    Print(5);// Integer i(5) is invoked
    //Assignment
    a1 = 7; //invokes the move assignment Integer & operator =(Integer &&a)
    
    //----------------TYPE CONVERSION : user-defined to primitive
    int x1 = a1;    // no proper conversion function -> type conversion operator
    */
    
    /*
    //Initialisation vs Assignment vs Member initialiser list
    Integer a(5);   //initialisation
    std::cout << std::endl;
    
    std::cout << a << std::endl;
    std::cout << std::endl;
    
    Integer b;
    std::cout << std::endl;
    b = 7;
    // a temporary parametrised CTOR (with 7)created for assignment
    // assigned to the obj on the left hand side
    // assignment operator is invoked
    // CONCLUSION : assignment requires more function calls than initialisation
    std::cout << b << std::endl;
    */
    Product p(5);   // Integer(int) : 5 is converted to Integer
    
    return 0;
}
