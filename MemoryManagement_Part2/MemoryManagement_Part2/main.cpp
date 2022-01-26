//
//  main.cpp
//  MemoryManagement_Part2
//
//  Created by Cyan on 2022/01/26.
//

#include "Integer.hpp"
#include <memory>

void Display(Integer *p){
    if(!p){
        return;
    }
    std::cout << p->GetValue() << std::endl;
}

Integer * GetPointer(int value){ //create an instance of Integer
    Integer *p = new Integer{value};
    return p;
}
//void Store(std::unique_ptr<Integer> p){
//    std::cout << "Storing data into a file: " << p->GetValue() << std::endl;
//}
void Store(std::unique_ptr<Integer> &p){
    std::cout << "Storing data into a file: " << p->GetValue() << std::endl;
}

void Operate(int value){
//    Integer *p = GetPointer(value); //General Pointer
    std::unique_ptr<Integer> p{GetPointer(value)};
    if(p == nullptr){ //overloaded compare operator
//        p = new Integer{value};
        p.reset(new Integer(value)); //allocate new memory, specify the value
    }
    p->SetValue(100);
    Display(p.get());
//    delete p;   //p is not a pointer it is an object // for general pointers
//    p = nullptr;    //overloaded assignment operator. It deletes underlying pointer and makes pointer variable null
//    p = new Integer{};  // for general pointers
    p.reset(new Integer{}); //above p=nullprt is no needed any longer
    *p = __LINE__;  // DFCN : store current line number
    Display(p.get());
//    delete p;   // for general pointers

    //Store(std::unique_ptr<Integer> p)
    //    Store(p);// calling a implicitly deleted copy CTOR of the unique_ptr
//    Store(std::move(p)); //as p is going to be destroyed after this line
                         // p of Operate() will be moved to p of Store()
                         // p of Operate() gives up ownership of the underlying pointer
                         // after p of Store() is destroyed, the memory will be freed
    //Store(std::unique_ptr<Integer> &p)
    Store(p);
    *p = 100;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    Operate(5);
    return 0;
}
