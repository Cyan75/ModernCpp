//
//  main.cpp
//  FileIO
//
//  Created by Cyan on 2022/03/31.
//

#include <iostream>
#include "Header.h"
//#include <experimental/filesystem>

void Write() {
    std::ofstream out{"data.txt", std::ios::out};
    if(!out){
        std::cout << "Could not open the file for writing" << std::endl;
        return;
    }
//    out << "Hello world" << std::endl;
//    out << 10 << std::endl;
    std::string message{"C++ was invented by Bjarne"};
    for (char ch : message) {
        out.put(ch);
    }
//    std::cout<<"Current position is: "<<out.tellp()<<std::endl;
    out.seekp(5);
    out.put('#');
    out.close();
}
void Read() {
    std::ifstream input{ "data.txt", std::ios::in };
    if(!input){
        std::cout<<"Source file not founnd"<<std::endl;
        return;
    }
//    input.seekg(5);
//    input.seekg(5, std::ios::beg);
//    input.seekg(-7, std::ios::end);
    std::cout<<"Current position is: "<<input.tellg()<<std::endl;
    char ch{};
    while (input.get(ch)) {
        std::cout<<ch;
    }
    //if (!input.is_open()) {
    //    std::cout << "Could not open the file" << std::endl;
    //    return;
    //}
    /*
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
     */
}
void UsingFstream(){
    std::fstream stream{"file.txt"};
    if(!stream){
        std::ofstream out {"file.txt"};
        out.close();
    }
    std::cout<<"Hello World"<<std::endl;
    
    stream.seekg(0);
    std::string line;
    std::getline(stream, line);
    std::cout<<line<<std::endl;
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
    /*depricated?*/
    /*
    using namespace std::experimental::filesystem;
    path source(current_path());
    source /= "main.cpp";
    
    path dest(current_path());
    dest /="Copy.cpp";
    std::ifstream input{source};
    if(!input){
        std::cout << "Source file not found" <<std::endl;
        return -1;
    }
    std::ofstream output{dest};
    std::string line;
    while(!std::getline(input, line).eof()){
        output<<line<<std::endl;
    }
    input.close();
    output.close();
     */
//     Write();
//     Read();
    UsingFstream();
    return 0;
}
