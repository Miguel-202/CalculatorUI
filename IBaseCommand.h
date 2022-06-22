#pragma once
class IBaseCommand
{
public:
	//IBaseCommand();
	~IBaseCommand();
	virtual double Execute(double num1, double num2) = 0;
};

