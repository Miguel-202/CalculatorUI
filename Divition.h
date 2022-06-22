#pragma once
#include "IBaseCommand.h"
class Divition :
    public IBaseCommand
{
public:
    double Execute(double num1, double num2)
    {
        double result = num2 / num1;
        return result;
    }
    
};

