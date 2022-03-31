//
//  Header.h
//  FileIO
//
//  Created by Cyan on 2022/03/31.
//

#ifndef Header_h
#define Header_h

#pragma once
#include <iostream>
#include <fstream>
#include <sstream>

class Test {
    std::fstream fstream;
    std::ifstream ifstream;
    std::ofstream ofstream;
    std::istringstream istringstream;
    std::ostringstream ostringstream;
    std::stringstream str;
};

#endif /* Header_h */
