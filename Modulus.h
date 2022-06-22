#pragma once
#include "IBaseCommand.h"
#include <cmath>
class Modulus :
    public IBaseCommand
{
public:
    double Execute(double num1, double num2)
    {
        double result = std::fmod(num2, num1);
        return result;
    }
};

