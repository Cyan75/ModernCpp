//
//  main.cpp
//  ModernC++Intro
//
//  Created by Cyan on 2021/11/30.
//

#include <iostream>

int Add(int *a, int *b) ;    //Add two numbers and return the sum
void AddVal(int *a, int *b, int *result); //Add two numbers and return the sum through the third pointer argument
void Swap(int *a, int *b) ;  //Swap the value of two integers
void Factorial(int *a, int *result);       //Generate the factorial of a number and return that through the second pointer argument

void Add(int a,int b, int &result) ;    //Add two numbers and return the result through a reference parameter
void Factorial(int a, int &result) ;    //Find factorial of a number and return that through a reference parameter
void Swap(int &a, int &b) ;            //Swap two numbers through reference arguments

void CreateWindow(const char * title, int x, int y, int width, int height);

void CreateWindow(const char * title, int x = -1, int y = -1, int width = -1, int height = -1){
    std::cout<< "Title : " << title << std::endl;
    std::cout<< "x : " << x << std::endl;
    std::cout<< "y : " << y << std::endl;
    std::cout<< "width : " << width << std::endl;
    std::cout<< "height : " << height << std::endl;
}

inline int Square(int x){
    return x * x;
}

void Print (int count, char ch){
    for (int i = 0; i<count; i++) {
        std::cout << ch;
    }
    std::cout<<std::endl;
}

void EndMessage(){
    std::cout<<"terminated (after main)"<<std::endl;
}

namespace Avg {
    float Calculate(float x, float y){
        return (x+y/2);
    }
}
namespace Basic{
    float Calculate(float x, float y){
        return (x+y);
    }

}

int main(int argc, const char * argv[]) {
    /*
    int a = 3;
    int *pa = &a;
    int b = 5;
    int *pb = &b;
    int c = 0;
    int *pc = &c;
    */
    
    /*
    std::cout << "Hello, World!\n"<< "initially : " << "a : "<< a <<"\n"<< "b : "<<b<<std::endl;
    std::cout << "Add : " << Add(pa, pb) << std::endl;
    AddVal(pa, pb, pc);
    std::cout << "AddVal , c:  " << *pc << std::endl;
    Swap(pa, pb);
    std::cout << "Swap , a:  " << *pa <<"\nb : "<< *pb << std::endl;
    Factorial(pa, pc);
    std::cout << "Factorial , c:  " << *pc << std::endl;
    */
    
    // Const Pointer and Reference
    //Try to modify x1 & x2 and see the compilation output
    
//    int x = 5;
//    const int MAX = 12;
//    int &ref_x1 = x;
//    const int &ref_x2 = x;
    
    //ref_x1 = 2; // OK
    //ref_x2 = 2; // Not OK
    
    //Try to modify the pointer (e.g. ptr1) and the pointee value (e.g. *ptr1)
    
//    const int* ptr1 = &x;   // a pointer to a constant int
//    int* const ptr2 = &x;   // a constant pointer to an int
//    const int* const ptr3 = &x; // a constant pointer to a constant int
    
    //*ptr1 = 10; // Not OK, the content is const
    //*ptr2 = 10; // OK
    //*ptr3 = 11; // Not OK, the content is const
    
    //Find which declarations are valid. If invalid, correct the declaration
//    const int *ptr3 = &MAX;
    //int * ptr4 = &MAX; // should be const int*
    
//    const int &r1 = ref_x1;
//    const int &r2 = ref_x2;   // should be const int
    
    
//    int *&p_ref1 = ptr1;  //cannot modify const
//    *ptr1 = 10;
//    const int *&p_ref2 = ptr2; //Not OK, should be int * const
//    *ptr2 = 10;
    
//    std::cout<< " x = "<< x << std::endl;
    
    /*
    const int y = 10;
    const auto var = y; //auto is const int
    auto &var1 = y; //var1 is a reference to y. auto is the same as the type of y. auto is a const int
    auto ptr = &y;  //auto is a pointer to y. auto is a pointer to a const int
    //auto * ptr2 = &y// do not use asterisk with auto
    
    auto list = {1,2,3,4};  //auto is a std::initializer_list<int>
    auto l{1};  //auto is an int
    */
    
//    int arr[] = {1,2,3,4,5};
    /*
    for(auto &i : arr) {    //use reference to avoid copying of the arr elements
       std::cout<<i<<" ";
    }
    
    for(const auto &i : arr) {    //arr elements cannot be modified
       std::cout<<i<<" ";
    }
     */
    
    /*
//    int * pBegin = &arr[0];
    int * pBegin = std::begin(arr);
//    int * pEnd = &arr[5];
    int * pEnd = std::end(arr);
     
     while (pBegin != pEnd){
     std::cout<< *pBegin <<" ";
     ++pBegin;
     }
    */
    /*
    auto range = arr;
    auto begin = std::begin(arr);
    auto end = std::end(arr);
    for(;begin!=end;begin++){
        auto v = *begin;
    }
        
    std::cout<<std::endl;
    
    CreateWindow("Notepad", 150, 200, 500, 600);
    CreateWindow("Notepad"); //CreateWindow("Notepad", -1, -1, -1, -1);
    CreateWindow("Notepad", 150, 100); //CreateWindow("Notepad", 150, 100, -1, -1);
    */
    
    /*
    int val = 5;
    int result = Square(val+1);
    std::cout<< result <<std::endl;
    */
    
    /*
    Print(5,'#');
    void (*pfn)(int, char) = &Print;
    (*pfn)(7, '@');
    pfn(11,'^');
    atexit(EndMessage);
    */
    
    std::cout<<Avg::Calculate(3.9f, 1.5f)<<std::endl;
    std::cout<<Basic::Calculate(3.9f, 1.5f)<<std::endl;
    
    return 0;
}

int Add(int *a, int *b){
    return (*a + *b);
}

void AddVal(int *a, int *b, int *result){
    *result = *a + *b;
}

void Swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Factorial(int *a, int *result){
    *result = 1;
    int i = *a;
    while(i > 0){
        *result *= i;
        i--;
    }
}

void Add(int a,int b, int &result){
    int &refa = a;
    int &refb = b;
    result = refa + refb;
}
void Factorial(int a, int &result) {
    int &ref = a;
    int i = ref;
    while(i > 1){
        result *=i;
        i--;
    }
}

void Swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}


