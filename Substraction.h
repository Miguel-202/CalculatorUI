#pragma once
#include "IBaseCommand.h"
class Substraction :
    public IBaseCommand
{
public:
    double Execute(double num1, double num2)
    {
        double result = -num1 + num2;
        return result;
    }
};

