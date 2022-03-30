//
//  main.cpp
//  ExceptionHandling
//
//  Created by Cyan on 2022/03/27.
//

#include <iostream>
#include <memory>
#include <vector>
#include <random>
void Test(int x)noexcept(true) {
    std::cout << x << std::endl;
    throw x;
}
int Sum(int x, int y)noexcept(noexcept(Test(x))) {
    Test(x);
    return x + y;
}
class A {
public:
    //Destructors are implicitly noexcept(true) in C++11
    ~A() {
        throw 3;
    }
};
/*
class A{
public:
    A(){
        std::cout << "A()" <<std::endl;
    }
    ~A(){
        std::cout<< "~A()"<<std::endl;
    }
};

class B{
public:
    B(){
        std::cout << "B()" <<std::endl;
    }
    ~B(){
        std::cout<< "~B()"<<std::endl;
    }
};

class Test{
//    A *pA{};
//    B b{};
//    int *pInt{};
//    char *pStr{};
//    int *pArr{};
    std::unique_ptr<A> pA{};
    B b{};
    std::unique_ptr<int> pInt{};
    std::unique_ptr<char> *pStr{};
    std::vector<int> *pArr{};
public:
    Test(){
        std::cout<<"Test() : Acquire resources"<<std::endl;
        pA.reset(new A);
        throw std::runtime_error("Failed to initialise");
//        pA = new A;
//        pInt = new int;
//        pStr = new char[1000];
//        pArr = new int[50000];
    }
    ~Test(){
        std::cout<<"~Test() : Release resources"<<std::endl;
        throw std::runtime_error("Failed to release");
//        delete pA;
//        delete pInt;
//        delete pStr;
//        delete pArr;
    }
};
 */
/*
void ProcessRecords(int count){
//    Test t;
//    Test* pTest = new Test;
    // smart ptr : not a pointer but an object
    std::unique_ptr<Test> uniqueTest (new Test);
    if(count<10){
        throw std::out_of_range("Count should not be greater than 10" );
    }
//    int * p = new int[count];
//    int *pArray = (int*)malloc(count * sizeof(int));
//    if (pArray == nullptr){
////        std::cout<< "Failed to allocate memory" << std::endl;
//        throw std::runtime_error("Failed to allocate memory" );
//    }
    std::vector<int> v;
    v.reserve(count);
    std::vector<int> vArr;
    vArr.reserve(count);
    
    //Process the record
//    for (int i = 0; i<count; ++i) {
//        pArray[i] = i;
//    }
        for (int i = 0; i<count; ++i) {
            vArr.push_back(i);
        }
//    free(pArray);
//    delete[] p;
//    delete pTest;
    std::default_random_engine eng;
    std::bernoulli_distribution dist;
    int errors{};
    for ( int i = 0; i< count; ++i) {
        try{
            std::cout<< "Processing record # : " << i << " ";
            if(!dist(eng)){
                ++errors;
                throw  std::runtime_error("Could not process the record");
            }
            std::cout<<std::endl;
        }
        catch (std::runtime_error &ex){
            std::cout<<"[Error "<<ex.what() << "]" << std::endl;
            if(errors>4){
                std::runtime_error err("Too many errors. Abandoning operation");
                ex = err;
                //re throw exception
                throw;
            }
        }
    }
}
*/
int main(int argc, const char * argv[]) {
    
    /*try {
//        ProcessRecords(std::numeric_limits<int>::max());
        ProcessRecords(10);
    }
//    catch (std::runtime_error &ex) {
//        std::cout << ex.what()<<std::endl;
//    }
//    catch( std::out_of_range &ex){
//        std::cout<<ex.what()<<std::endl;
//    }
//    catch(std::bad_alloc &ex){
//        std::cout<<ex.what()<<std::endl;
//    }
    catch (std::exception&ex){
        std::cout<<ex.what()<<std::endl;
    }
    
    catch(...){
        std::cout<<"Exception"<<std::endl;
    }
    
//    std::cout<<ProcessRecords(std::numeric_limits<int>::max())<<std::endl;
     */
    /*
    try {
        Test t;
        throw std::runtime_error("Exception");
    } catch (std::runtime_error &ex) {
        std::cout << ex.what() <<std::endl;
    }
     */
    A a;
    //boolalpha manipulator prints 0 & 1 as false & true
    std::cout << std::boolalpha << noexcept(a.~A()) << std::endl;
    try {
        Sum(3, 5);
        //Other statements
    }
    catch (int x) {
        std::cout << x << std::endl ;
    }
    return 0;
}
