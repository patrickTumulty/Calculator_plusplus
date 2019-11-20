//
//  Calculator.hpp
//  Calculator++
//
//  Created by Patrick Tumulty on 11/8/19.
//  Copyright © 2019 Patrick Tumulty. All rights reserved.
//

#ifndef CalculatorMemory_hpp
#define CalculatorMemory_hpp

#include <stdio.h>
#include <stack>
#include <string>

class CalculatorMemory
{
private:
    std::stack <std::string> * user_inputs;
    std::stack <std::string> * redo_store;
    
public:
    CalculatorMemory();
    ~CalculatorMemory();
    
    std::string undo_mem();
    std::string redo_mem();
    std::string view_previous();
    void save_input(std::string input_string);
};

#endif /* Calculator_hpp */
