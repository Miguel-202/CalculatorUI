#include "pch.h"
#include "CalculatorProcessorTests.h"

float CalculatorProcessorTests::SolveOperationAdditionThenMultiplications(std::string op)
{
	_processor->AddOperationAddition();
	_processor->AddOperationMultiplication();
	float result = _processor->Calculate(op);
	return result;
}

float CalculatorProcessorTests::SolveOperationSubstraction(std::string op)
{
	_processor->AddOperationSubstraction();
	float result = _processor->Calculate(op);
	return result;
}
int CalculatorProcessorTests::SolveOperationDecimalToBinary(int dec)
{
	_processor->SetBaseNumber(dec);
	int result = stoi(_processor->GetBinary());
	return result;
}
std::string CalculatorProcessorTests::SolveOperationDecimalToHex(int dec)
{
	_processor->SetBaseNumber(dec);
	std::string result = _processor->GetHexadecimal();
	return result;
}

int CalculatorProcessorTests::SolveOperationDecimalToBinaryAndBackToDecimal(int dec)
{
	_processor->SetBaseNumber(dec);
	_processor->GetBinary();
	int result = stoi(_processor->GetDecimal());
	return result;
}
int CalculatorProcessorTests::SolveOperationModulus(std::string op)
{
	_processor->AddOperationMod();
	float result = _processor->Calculate(op);
	return result;
}

float CalculatorProcessorTests::OperationToNegative(int num)
{
	_processor->SetBaseNumber(num);
	return stoi(_processor->GetNegative());
}