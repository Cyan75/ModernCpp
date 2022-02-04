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
    return 0;
}
