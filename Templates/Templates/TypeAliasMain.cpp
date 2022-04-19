//
//  TypeAliasMain.cpp
//  Templates
//
//  Created by Cyan on 2022/04/19.
//

#include <iostream>
#include <vector>
#include <list>

const char * GetErrorMessage(int errorNo) {
    return "Empty";
}
//typedef
//typedef const char *(*PFN)(int);

//ttype alias
using PFN = const char *(*)(int);
void ShowError(PFN pfn){
    
}
//typedef std::vector < std::list<std::string>> Names;

//template<typename T>
//using Names = std::vector<std::list<T>>;

using Names = std::vector<std::list<std::string>>;

int main() {
    Names names;
    Names nnames;

    PFN pfn = GetErrorMessage;
    ShowError(pfn);
    return 0;
}
