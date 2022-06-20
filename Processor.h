#pragma once
#include <string>
#include <vector>
#include <sstream>
class Processor
{
private:
	static Processor* _processor;
	long baseNumber;
	std::vector<double> numbsToCalculate;
	std::vector<char> operations;
	Processor(){}
public:
	void Clear()
	{
		numbsToCalculate.clear();
		operations.clear();
	}
	void AddOperation(char c)
	{
		operations.push_back(c);
	}
	void AddNumberToCalculate(double num)
	{
		numbsToCalculate.push_back(num);
	}
	float Calculate(std::string my_str)
	{
		std::stringstream s_stream(my_str);
		while (s_stream.good()) 
		{
			std::string substr;
			getline(s_stream, substr, '+');
			if (double num = std::stod(substr))
				numbsToCalculate.push_back(num);
		}
		for (size_t i = 0; i < operations.size(); i++)
		{
			if (numbsToCalculate.size() > 1)
			{
				double num1 = numbsToCalculate[0];
				double num2 = numbsToCalculate[1];
				if (operations[i] == '+')
				{
					num1 = num1 + num2;
					numbsToCalculate.erase(numbsToCalculate.begin());
					numbsToCalculate.erase(numbsToCalculate.begin());
					if (numbsToCalculate.size() < 1)
					{
						numbsToCalculate.push_back(num1);
					}
					else
					{
						numbsToCalculate[i] = num1;
					}
				}
				operations.erase(operations.begin());
			}
		}
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
