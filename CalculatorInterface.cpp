//
//  CalculatorInterface.cpp
//  Calculator++
//
//  Created by Patrick Tumulty on 11/8/19.
//  Copyright © 2019 Patrick Tumulty. All rights reserved.
//

#include "CalculatorInterface.hpp"
#include <iostream>
#include <cmath>
#include <string>
#include <stdlib.h>

CalculatorInterface::CalculatorInterface()
{
//    CalculatorMemory * calcMem = new CalculatorMemory();
    std::string new_equation;
}

CalculatorInterface::~CalculatorInterface()
{
    delete this->calcMem;
}

void CalculatorInterface::get_user_input()
{
    std::cout<<"Enter Math << ";
    std::getline(std::cin, new_equation);
    calcMem->save_input(new_equation);
}

void CalculatorInterface::undo()
{
    std::cout<<calcMem->undo_mem()<<std::endl;
}

void CalculatorInterface::redo()
{
    std::cout<<calcMem->redo_mem()<<std::endl;
}

double CalculatorInterface::evaluate_input(std::string s)
{
    s = remove_whitespace(s);
    double output;
    std::string eval[3];
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != '.' && isdigit(s[i]) == false)
        {
            eval[0] = s.substr(0, i);
            eval[1] = s[i];
            eval[2] = s.substr(++i, s.length()-1);
            break;
        }
    }
    if (eval[1] == "+")
    {
        output = std::stod(eval[0]) + std::stod(eval[2]);
    }
    else if (eval[1] == "-")
    {
        output = std::stod(eval[0]) - std::stod(eval[2]);
    }
    else if (eval[1] == "*")
    {
        output = std::stod(eval[0]) * std::stod(eval[2]);
    }
    else if (eval[1] == "/")
    {
        output = std::stod(eval[0]) / std::stod(eval[2]);
    }
    else if (eval[1] == "%")
    {
        output = std::stoi(eval[0]) % std::stoi(eval[2]);
    }
    else if (eval[1] == "^")
    {
        output = pow(std::stod(eval[0]), std::stod(eval[2]));
    }
    else
    {
        output = 0;
    }
    return output;
}

void CalculatorInterface::clearScreen()
{
    for (int i = 0; i < 10; i++)
    {
        std::cout<<"\n\n\n\n\n"<<std::endl;
    }
}

std::string CalculatorInterface::remove_whitespace(std::string s)
{
    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != ' ')
        {
            s[count++] = s[i];
        }
    }
    return s.substr(0, count);
}

