//
//  main.cpp
//  C++Goodies
//
//  Created by Cyan on 2022/02/07.
//

#include <iostream>

/*
enum class Colour{RED, GREEN, BLUE};//global scope

void FillColour(Colour colour){
    // fill the background
    if (colour == Colour::RED) {
        // paint with red
        std::cout<< " RED " << std::endl;
    }
    else if (colour == Colour::GREEN){
        // paint with green
        std::cout<< " GREEN " << std::endl;
    }
    else if (colour == Colour::BLUE){
        // paint with blue
        std::cout<< " BLUE " << std::endl;
    }
}
*/
void UsingStdString(){
    //String
    //Initialisation and assign
    std::string s = "Hello";
    
    //Access
    s[0] = 'W';
    char ch = s[1];
    std::cout<<s<<std::endl;
//    std::cin>s;
    std::getline(std::cin, s);
    
    //Size
    s.length();
    
    //Insert & concatenate
    std::string s1{"hello"}, s2{"world"};
    s = s1 + s1;
    s+=s1;
    s.insert(6,"world");
    
    //Comparison
    if (s1 != s2){
        
    }
    //Removal
    s.erase();
    s.erase(0,5);
    s.clear();
    
    //Search
    auto pos = s.find("world", 0);  //substring
    if (pos != std::string::npos){
        //found
    }
}

enum class TrafficLight : char{RED, GREEN, YELLOW};
int main(int argc, const char * argv[]) {
    /*
    std::cout << "Hello, World!\n";
    Colour c = Colour::RED;
    FillColour(c);
    FillColour(Colour::GREEN);
    FillColour(static_cast<Colour>(2));
    */
    //TODO lower to upper upper to lower translation using ToUpper and ToLower
    
    return 0;
}
