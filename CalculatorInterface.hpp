//
//  CalculatorInterface.hpp
//  Calculator++
//
//  Created by Patrick Tumulty on 11/8/19.
//  Copyright © 2019 Patrick Tumulty. All rights reserved.
//

#ifndef CalculatorInterface_hpp
#define CalculatorInterface_hpp

#include <stdio.h>
#include <string>
#include "CalculatorMemory.hpp"

class CalculatorInterface
{
private:
    std::string new_equation;
public:
    CalculatorInterface();
    ~CalculatorInterface();
    
    CalculatorMemory * calcMem = new CalculatorMemory();
    
    void clearScreen();
    void get_user_input();
    void undo();
    void redo();
    double evaluate_input(std::string s);
    std::string remove_whitespace(std::string s);
    
};

#endif /* CalculatorInterface_hpp */
