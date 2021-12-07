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
    
    int x = 5;
    const int MAX = 12;
    int &ref_x1 = x;
    const int &ref_x2 = x;
    
    //ref_x1 = 2; // OK
    //ref_x2 = 2; // Not OK
    
    //Try to modify the pointer (e.g. ptr1) and the pointee value (e.g. *ptr1)
    
    const int* ptr1 = &x;   // a pointer to a constant int
    int* const ptr2 = &x;   // a constant pointer to an int
    const int* const ptr3 = &x; // a constant pointer to a constant int
    
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
    
    std::cout<< " x = "<< x << std::endl;
    
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


