//
//  TypeAliasMain.cpp
//  Templates
//
//  Created by Cyan on 2022/04/19.
//

#include <iostream>
#include <vector>
#include <list>
#include <type_traits>

/*
const char * GetErrorMessage(int errorNo) {
    return "Empty";
}
//typedef
//typedef const char *(*PFN)(int);

//type alias
using PFN = const char *(*)(int);
void ShowError(PFN pfn){
    
}
//typedef std::vector < std::list<std::string>> Names;

//template<typename T>
//using Names = std::vector<std::list<T>>;

using Names = std::vector<std::list<std::string>>;
*/

template<typename T>
T Divide(T a, T b){
    /*
    static_assert(std::is_floating_point<T>::value, "Only floating point type supported");
    if (std::is_floating_point<T>::value == false) {
        std::cout << "Use floating point types only\n";
        return 0;
    }
     */
    if(std::is_floating_point<T>::value == false){
        std::cout << "use floating point types only \n";
        return 0;
    }
    return a / b;
}

template<typename T>
void Check(T&&){
    std::cout << std::boolalpha ;
    std::cout << "Is referce?" << std::is_reference<T>::value << std::endl;
    
    std::cout << "After removing" << std::is_reference<typename std::remove_reference<T>::type>::value << std::endl;
}

int main() {
//    Names names;
//    Names nnames;
//
//    PFN pfn = GetErrorMessage;
//    ShowError(pfn);
    
    /*
//    static_assert(sizeof(void *) == 4, "Compile in 32-bit mode only");
    if (sizeof(void *) != 4){
        std::cout << "Not, 32-bit mode\n";
        return 0;
    }
    else{
        //Alright
    }
    std::cout << std::boolalpha << "Is Integer?" << std::is_integral<int>::value << std::endl;
    
    std::cout << Divide(5.1,2.7) <<std::endl;
    
//    return 0;
    */
    /*
    std::cout << std::boolalpha << "Is integer " << std::is_integral<int>::value << std::endl;
    std::cout << Divide(5, 2) << std::endl;
     */
    Check(5);
    int value{};
    Check(value);
}
