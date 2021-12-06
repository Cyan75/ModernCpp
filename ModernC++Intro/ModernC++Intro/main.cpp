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

int main(int argc, const char * argv[]) {
    int a = 3;
    int *pa = &a;
    int b = 5;
    int *pb = &b;
    int c = 0;
    int *pc = &c;
    
    std::cout << "Hello, World!\n"<< "initially : " << "a : "<< a <<"\n"<< "b : "<<b<<std::endl;
    std::cout << "Add : " << Add(pa, pb) << std::endl;
    AddVal(pa, pb, pc);
    std::cout << "AddVal , c:  " << *pc << std::endl;
    Swap(pa, pb);
    std::cout << "Swap , a:  " << *pa <<"\nb : "<< *pb << std::endl;
    Factorial(pa, pc);
    std::cout << "Factorial , c:  " << *pc << std::endl;
    
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


