//
//  main.cpp
//  MemoryManagement_Part2
//
//  Created by Cyan on 2022/01/26.
//

#include "Integer.hpp"
#include <memory>
#include <iostream>

/*
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
*/
/*
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
//for shared pointers
class Project{
    std::string m_Name;
public:
    void SetName(const std::string &name){
        m_Name = name;
    }
    void ShowProjectDetails() const{
        std::cout<< "[Project Name] " <<m_Name <<'\n';
    }
};
*/
/*
class Employee{
//    Project * m_pProject{}; //every obj has to be manually deleted
//    std::unique_ptr<Project> m_pProject{};    //cannot be shared
    std::shared_ptr<Project> m_pProject{};
public:
//    void SetProject(Project *prj){
//        m_pProject = prj;
//    }
    
//    void SetProject(std::unique_ptr<Project> &prj){
//        m_pProject = std::move(prj);    //unique pointer cannot be copied
                                          // m_pProject has been moved, no longer exists
//    }
    
    void SetProject(const std::shared_ptr<Project> &prj){
        m_pProject = prj;    // shared pointer supports copu
    }
    
//    const Project* GetProject()const{
//        return m_pProject;
//    }
    
//    const std::unique_ptr<Project>& GetProject()const{
//        return m_pProject;
//    }
    
    const std::shared_ptr<Project>& GetProject()const{
        return m_pProject;
    }
};
 */

//void ShowInfo(Employee *emp){
//    std::cout << "Employee project details : \n";
//    emp->GetProject()->ShowProjectDetails();
//}

//void ShowInfo(const std::unique_ptr<Employee> &emp){
//    std::cout << "Employee project details : \n";
//    emp->GetProject()->ShowProjectDetails();
//}

//void ShowInfo(const std::shared_ptr<Employee> &emp){
//    std::cout << "Employee project details : \n";
//    emp->GetProject()->ShowProjectDetails();
//}

class Printer
{
    //    int *m_pValue{};
    //    std::shared_ptr<int> m_pValue;
    std::weak_ptr<int> m_pValue;

public:
    //    void SetValue(int *p){
    //        m_pValue = p;
    //    }

    //    void SetValue(std::shared_ptr<int>p){
    //        m_pValue = p;   //a copy of the shared pointer is created : reference count = 2
    //    }

    void SetValue(std::weak_ptr<int> p)
    {
        m_pValue = p; //a copy of the shared pointer is created : reference count = 2
    }

    void Print()
    {
        // needed : something that checks if the pointer is still valid
        //        std::cout << "Ref count : "  << m_pValue.use_count() << std::endl;
        //        std::cout << "Value is : " << *m_pValue << std::endl;
        if (m_pValue.expired())
        {
            std::cout << "resource is no longer available" << std::endl;
            return;
        }
        auto sp = m_pValue.lock();
        std::cout << "Value is : " << *sp << std::endl;
        std::cout << "Ref count : " << sp.use_count() << std::endl;
    }
};

int mai(int argc, const char *argv[])
{
    Printer prn;
    int num{};
    std::cin >> num;
    //    int *p = new int{num};
    //try using a shared pointer?
    std::shared_ptr<int> p{new int{num}};
    prn.SetValue(p);
    if (*p > 10)
    {
        //        delete p;      //p may be deleted
        p = nullptr; // only decremented by 1, reference count = 1, underlying memory is not released
    }

    prn.Print(); // if p is deleted, m_pValue will point to invalid memory that already has been released
                 //    delete p;

    //    Operate(5);
    //classical pointer
    /*
    Project *prj = new Project{};
    prj->SetName("Video Decoder");
     
    Employee *e1 = new Employee{};
    e1->SetProject(prj);
    Employee *e2 = new Employee{};
    e2->SetProject(prj);
    Employee *e3 = new Employee{};
    e3->SetProject(prj);
    
    ShowInfo(e1);
    ShowInfo(e2);
    ShowInfo(e3);
    prj->ShowProjectDetails();
    
    delete prj;
    delete e1;
    delete e2;
    delete e3;
    */
    //Unique pointer
    /*
    std::unique_ptr<Project> prj{new Project{}};// prj is empty because it is moved
                                                // the unique pointer prj cannot be shared
    prj->SetName("Video Decoder");
    std::unique_ptr<Employee> e1{new Employee{}};
    e1->SetProject(prj);
    std::unique_ptr<Employee> e2{new Employee{}};
    e2->SetProject(prj);
    std::unique_ptr<Employee> e3{new Employee{}};
    e3->SetProject(prj);
    ShowInfo(e1);
    ShowInfo(e2);
    ShowInfo(e3);
    prj->ShowProjectDetails();
     */

    //Shared pointer
    /*
    std::shared_ptr<Project> prj{ new Project{}};
    prj->SetName("Video Decoder");
    std::cout<< "Reference Count : " << prj.use_count() <<'\n';
    std::shared_ptr<Employee> e1{new Employee{}};
    e1->SetProject(prj);
    std::cout<< "Reference Count : " << prj.use_count() <<'\n';
    std::shared_ptr<Employee> e2{new Employee{}};
    e2->SetProject(prj);
    std::cout<< "Reference Count : " << prj.use_count() <<'\n';
    std::shared_ptr<Employee> e3{new Employee{}};
    e3->SetProject(prj);
    std::cout<< "Reference Count : " << prj.use_count() <<'\n';
    ShowInfo(e1);
    ShowInfo(e2);
    ShowInfo(e3);
    prj->ShowProjectDetails();  //there are four copies of the shared pointer
    std::cout<< "Reference Count : " << prj.use_count() <<'\n';
    
    if(e3){ //check if e3 is a valid pointer
        
    }
    else{
        
    }
    e1.reset(); // destroys the underlying obj, reference count decremented
    e2.reset(new Employee{});  //decrement the reference count (delete underlying pointer if the reference count becomes zero
                               //take ownership of this new pointer
                               //the reference count of the new smart pointer is 1
    */

    return 0;
}
