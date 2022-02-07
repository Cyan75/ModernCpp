//
//  main.cpp
//  C++Goodies
//
//  Created by Cyan on 2022/02/07.
//

#include <iostream>


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

enum class TrafficLight : char{RED, GREEN, YELLOW};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Colour c = Colour::RED;
    FillColour(c);
    FillColour(Colour::GREEN);
    FillColour(static_cast<Colour>(2));
    return 0;
}
