//
//  main.cpp
//  FileIO
//
//  Created by Cyan on 2022/03/31.
//

#include <iostream>
#include "Header.h"
void Write() {
    std::ofstream out{"data.txt", std::ios::out};
    out << "Hello world" << std::endl;
    out << 10 << std::endl;
    out.close();
}
void Read() {
    std::ifstream input{ "data.txt", std::ios::in };
    //if (!input.is_open()) {
    //    std::cout << "Could not open the file" << std::endl;
    //    return;
    //}
    
    if (input.fail()) {
        std::cout << "Could not open the file" << std::endl;
        return;
    }
    std::string message;
    std::getline(input, message);
    int value{};
    input >> value;
//    input >> value;
    if (input.eof()) {
        std::cout << "End of file encountered" << std::endl;
    }
    if (input.good()) {
        std::cout << "I/O operations are successful" << std::endl;
    }
    else {
        std::cout << "Some I/O operations failed" << std::endl;
    }
    input.setstate(std::ios::failbit);
    input.clear();
    input.close();
    std::cout << message << ":" << value << std::endl;
}
int main(int argc, const char * argv[]) {
    /*
    std::string fileName{"~/Desktop/Computer_Programming/ModernC++/FileIO/FileIO/newFile.txt"};
    std::cout<<fileName<<std::endl;
    
    //raw string literals with R"()"
    std::string rawLiteral{R"(raw string literal)"};
    std::cout<<rawLiteral<<std::endl;
    
    // delimeter for raw string literals
    std::string message{R"BLUE(C++ introduced filesystem API "(C++17)")BLUE"};
    std::cout<<message<<std::endl;
    */
    Write();
    Read();
    return 0;
}
