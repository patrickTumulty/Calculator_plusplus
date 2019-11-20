//
//  Calculator.cpp
//  Calculator++
//
//  Created by Patrick Tumulty on 11/8/19.
//  Copyright © 2019 Patrick Tumulty. All rights reserved.
//

#include "CalculatorMemory.hpp"


CalculatorMemory::CalculatorMemory()
{
    this->user_inputs = new std::stack<std::string>();
    this->redo_store = new std::stack<std::string>();
}

CalculatorMemory::~CalculatorMemory()
{
    delete this->user_inputs;
    delete this->redo_store;
}

std::string CalculatorMemory::undo_mem()
{
    if (user_inputs->empty())
    {
        return "ERROR>undo";
    }
    else
    {
        std::string temp = this->user_inputs->top();
        this->redo_store->push(temp);
        this->user_inputs->pop();
        return temp;
    }
}

std::string CalculatorMemory::redo_mem()
{
    if (redo_store->empty())
    {
        return "redo<ERROR";
    }
    else
    {
        std::string temp = this->redo_store->top();
        this->user_inputs->push(temp);
        this->redo_store->pop();
        return temp;
    }
}


std::string CalculatorMemory::view_previous()
{
    if (user_inputs->empty())
    {
        return "ERROR>undo";
    }
    else
    {
        return this->user_inputs->top();
    }
}

void CalculatorMemory::save_input(std::string input_string)
{
    this->user_inputs->push(input_string);
}


