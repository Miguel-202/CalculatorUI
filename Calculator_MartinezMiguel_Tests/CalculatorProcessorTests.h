#pragma once
#include "..\Processor.h"
#include <string>
class CalculatorProcessorTests
{
private:
	Processor* _processor = _processor->GetInstance();
public:
	float SolveOperationAdditionThenMultiplications(std::string op);
	float SolveOperationSubstraction(std::string op);
	int SolveOperationDecimalToBinary(int dec);
	std::string SolveOperationDecimalToHex(int dec);
	int SolveOperationDecimalToBinaryAndBackToDecimal(int dec);
	int SolveOperationModulus(std::string op);
	float OperationToNegative(int num);
};

