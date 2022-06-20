#pragma once
#include <string>
#include <vector>
#include <sstream>
#include "IBaseCommand.h"
#include "Addition.h"
#include "Multiplication.h"
#include "Divition.h"
#include "Substraction.h"
class Processor
{
private:
	static Processor* _processor;
	long baseNumber;
	std::vector<double> numbsToCalculate;
	std::vector<IBaseCommand* > operations;
	Processor(){}
public:
	void Clear()
	{
		numbsToCalculate.clear();
		operations.clear();
	}
	void AddOperationAddition()
	{
		Addition* add = new Addition();
		operations.push_back(add);
	}
	void AddOperationSubstraction()
	{
		Substraction* add = new Substraction();
		operations.push_back(add);
	}
	void AddOperationMultiplication()
	{
		Multiplication* add = new Multiplication();
		operations.push_back(add);
	}
	void AddOperationDivition()
	{
		Divition* add = new Divition();
		operations.push_back(add);
	}
	void AddNumberToCalculate(double num)
	{
		numbsToCalculate.push_back(num);
	}
	float Calculate(std::string op)
	{
		numbsToCalculate.clear();
		op.push_back('*');
		std::string temp;
		for (size_t i = 0; i < op.size(); i++)
		{
			if (op[i] >= 48 && op[i] <= 57 || op[i] == 46)
			{
				temp.push_back(op[i]);
			}
			else
			{
				double num = std::stod(temp);
				temp.clear();
				numbsToCalculate.push_back(num);
			}
		}
		for (size_t i = operations.size(); i > 0; i--)
		{
			if (numbsToCalculate.size() > 1)
			{
				double num1 = numbsToCalculate[i];
				double num2 = numbsToCalculate[i - 1];
				num2 = operations[i-1]->Execute(num1,num2);
				numbsToCalculate.erase(numbsToCalculate.begin() + i);
				numbsToCalculate[i-1] = num2;
			}
		}
		operations.clear();
		return numbsToCalculate[0];
	}
	static Processor* GetInstance()
	{
		if (_processor == nullptr)
		{
			_processor = new Processor;
		}
		return _processor;
	}
	void SetBaseNumber(long number)
	{
		baseNumber = number;
	}

	Processor(Processor& other) = delete;
	void operator=(const Processor& other) = delete;

	std::string GetDecimal()
	{

	}
	std::string GetBinary()
	{
		std::string results = "";
		long number = baseNumber;
		for (long i = 0; i < 32; i++)
		{
			if (number % 2 == 0)
			{
				results = "0" + results;
			}
			else
			{
				results = "1" + results;
			}
			number = number / 2;
		}
		return results;
	}
	std::string GetHexadecimal()
	{
		std::string results = "";
		long number = baseNumber;
		while (number > 0)
		{
			int mod = number % 16;
			if (mod < 10)
			{
				results = std::to_string(mod) + results;
			}
			else if(mod == 10)
			{
				results = "A" + results;
			}
			else if (mod == 11)
			{
				results = "B" + results;
			}
			else if (mod == 12)
			{
				results = "C" + results;
			}
			else if (mod == 13)
			{
				results = "D" + results;
			}
			else if (mod == 14)
			{
				results = "E" + results;
			}
			else if (mod == 15)
			{
				results = "F" + results;
			}
			number = number / 16;

		}
		results = "0x" + results;
		return results;
	}


};
Processor* Processor::_processor = nullptr;
