//
//  source.cpp
// for circular reference
//  MemoryManagement_Part2
//
//  Created by Cyan on 2022/02/04.
//

#include <iostream>
/*
 class Employee;
class Project{
public:
//    Employee *m_emp;
    std::shared_ptr<Employee>m_emp;
    Project(){
        std::cout << "Project()" << std::endl;
    }
    ~Project(){
        std::cout << "~Project()" << std::endl;
    }
};
class Employee {
public:
//    Project *m_prj;
//    std::shared_ptr<Project>m_prj;
    std::weak_ptr<Project>m_prj;
    Employee(){
        std::cout << "Employee()" << std::endl;
    }
    ~Employee(){
        std::cout << "~Employee()" << std::endl;
    }
};
*/
//a custom deleter : function object
struct Free{
    void operator()(int *p){
        free(p);
        std::cout << "pointer freed\n";
    }
};
//another custom deleter : function pointer
void MallocFree(int*p){
    free(p);
    std::cout << "pointer freed\n";
}

void SharedPtrDeleters(){
    //function object
    std::shared_ptr<int> p {(int*) malloc(4), Free()};
    //function pointer
//    std::shared_ptr<int> p {(int*)malloc(4), MallocFree};
    *p = 100;
    std::cout << *p << '\n';
}

class Point{
public:
    Point(int x, int y){
        
    }
};

int main(){
    // unique pointer
    //    std::unique_ptr<int, Free> p {(int*) malloc(4), Free()};
//    std::unique_ptr<int, void (*)(int*)> p {(int*)malloc(4), MallocFree};
//    *p = 100;
//    std::cout << *p << '\n';
    SharedPtrDeleters();
/*
 //raw pointers
//    Employee *emp = new Employee{};
//    Project *prj = new Project{};
    
    //use shared pointers instead
    std::shared_ptr<Employee> emp {new Employee{}};
    std::shared_ptr<Project> prj {new Project{}};
    
    emp->m_prj = prj;
    prj->m_emp = emp;
//    delete emp;
//    delete prj;
 */
    /*
    std::unique_ptr<int> p1{new int[5]{1,2,3,4,5}};
//    p1[0] = 10; // smart pointer of a primitive type does not support this.
    p1.get()[0] = 10; // this is OK but it does not delete properly
    
    // use this
    std::unique_ptr<int[]> p2{new int[5]{1,2,3,4,5}};
    p2[0] = 10;
    
    //for shared pointer, C++17 or later supports
    std::shared_ptr<int[]> p3{new int[5]{1,2,3,4,5}};
    p3[0] = 10;
    */
    // construct without using new
    {
        //    std::unique_ptr<int[]> p{new int[5]};
        auto p = std::make_unique<int>(5);
        auto pt = std::make_unique<Point>(3,5);
        auto pArr = std::make_unique<int[]>(5);
        pArr[0] = 0;
    }
    {
        auto p = std::make_shared<int>(5);
        auto pt = std::make_shared<Point>(3,5);
//        auto pArr = std::make_shared<int[]>(5);   //C++20
        pArr[0] = 0;
    }

    return 0;
}
