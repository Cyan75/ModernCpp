//
//  main.cpp
//  MemoryManagement
//
//  Created by Cyan on 2021/12/16.
//

#include <iostream>

void New();
void NewArray();
void Strings();
void TwoD();

int main(int argc, const char * argv[]) {
    New();
    NewArray();
    Strings();
    TwoD();
    return 0;
}

void New(){
    int *p = new int;
    int *p1 = new int(5);
    *p = 7;
    std::cout<<"*p : "<< *p << std::endl;
    std::cout<<"*p1 : "<<  *p1 << std::endl;
    delete p;
    delete p1;
    p = nullptr;
    p1 = nullptr;
}

void NewArray(){
    int *p = new int[5];
    for (int i = 0; i<5; i++) {
        *(p+i) = i;
        std::cout<< *(p+i) <<" ";
    }
    delete [] p;
}

void Strings(){
    char *p = new char[4]; // \0 at the end
    strcpy(p, "C++");
    std::cout<<p<<std::endl;
    delete [] p;
}

void TwoD(){
    int *r0 = new int[3];
    int *r1 = new int[3];
    
    int **t = new int *[2]; // array of pointers having two args
    *t = r0;
    *(t+1) = r1;
    
    for (int j = 0; j<3; j++) {
        *(r0+j) = 10 + j;
    }
    for (int j = 0; j<3; j++) {
        *(r1+j) = 10 - j;
    }
    
    for (int i = 0; i<2; i++) {
        for (int j = 0; j<3; j++) {
            std::cout<< t[i][j] <<" ";
        }
        std::cout << std::endl;
    }
    
    
    delete [] r0;
    delete [] r1;
    delete [] t;
    
}
