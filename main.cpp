//
//  main.cpp
//  Calculator++
//
//  Created by Patrick Tumulty on 11/8/19.
//  Copyright © 2019 Patrick Tumulty. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cmath>
#include "CalculatorMemory.hpp"
#include "CalculatorInterface.hpp"

int main(int argc, const char * argv[]) {
    CalculatorInterface * calculator = new CalculatorInterface();
    std::string prev;
    std::string ans = "...";
    std::string current;
    bool first = false;
    while(1)
    {
        calculator->clearScreen();
        std::cout<<"_______________"<<std::endl;
        std::cout<<"|Calculator ++|"<<std::endl;
        std::cout<<"|  +   -   *  |"<<std::endl;
        std::cout<<"|_ ^   %   / _|"<<std::endl;
        std::cout<<"@|===========|@ "<<std::endl;
        std::cout<<"Enter a valid equation [ 3 ^ 3 ]\n[u]ndo or [r]edo "<<std::endl;
        if (first)
        {
            prev = calculator->calcMem->view_previous();
            ans = std::to_string(calculator->evaluate_input(prev));
            std::cout<<"\n[ " + prev + " = " + ans + " ]\n"<<std::endl;
        }
        
        std::cout<<"Enter Math >> ";
        std::getline(std::cin, current);
        if (current == "R" || current == "r")
        {
            prev = calculator->calcMem->redo_mem();
        }
        else if (current == "U" || current == "u")
        {
            prev = calculator->calcMem->undo_mem();
        }
        else
        {
            calculator->calcMem->save_input(current);
        }
        first = true;
    }
 
    return 0;
}
