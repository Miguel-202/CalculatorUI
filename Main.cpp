#include "Main.h"
#include "ButtonFactory.h"
#include "Processor.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

wxBEGIN_EVENT_TABLE(Main, wxFrame)
EVT_BUTTON(wxID_ANY, OnButtonClicked)
wxEND_EVENT_TABLE();

double width = 375;
double height = 679;
Main::Main() : wxFrame(nullptr, wxID_ANY, "Calculator", wxPoint(600,100), wxSize(width,height))
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtSetBreakAlloc(-1);
	CreateButtons();
}

Main:: ~Main()
{
}


void Main::CreateButtons()
{
	//GRID 4x6
	double xSize = (width - 20) / 4;
	double ySize = (height - 35) / 7;
	double currentX = 0;
	double currentY = 0;

	ButtonFactory factory;

	operations = new wxTextCtrl(this, 10040, "", wxPoint(currentX, currentY), wxSize(xSize * 4, ySize), wxTE_READONLY); currentY += ySize;

	power = factory.CreatePowerButton(this, currentX, currentY, xSize, ySize); currentX += xSize;
	mod = factory.CreateModButton(this, currentX, currentY, xSize, ySize); currentX += xSize;
	negative = factory.CreateNegativeButton(this, currentX, currentY, xSize, ySize); currentX += xSize;
	clear = factory.CreateClearButton(this, currentX, currentY, xSize, ySize); currentX = 0; currentY += ySize;

	seven = factory.CreateNumberButton(this, currentX, currentY, xSize, ySize, 7); currentX += xSize;
	eigth = factory.CreateNumberButton(this, currentX, currentY, xSize, ySize, 8); currentX += xSize;
	nine = factory.CreateNumberButton(this, currentX, currentY, xSize, ySize, 9); currentX += xSize;
	divide = factory.CreateDivideButton(this, currentX, currentY, xSize, ySize); currentX = 0; currentY += ySize;

	four = factory.CreateNumberButton(this, currentX, currentY, xSize, ySize, 4); currentX += xSize;
	five = factory.CreateNumberButton(this, currentX, currentY, xSize, ySize, 5); currentX += xSize;
	six = factory.CreateNumberButton(this, currentX, currentY, xSize, ySize, 6); currentX += xSize;
	multiply = factory.CreateMultiplyButton(this, currentX, currentY, xSize, ySize); currentX = 0; currentY += ySize;

	one = factory.CreateNumberButton(this, currentX, currentY, xSize, ySize, 1); currentX += xSize;
	two = factory.CreateNumberButton(this, currentX, currentY, xSize, ySize, 2); currentX += xSize;
	three = factory.CreateNumberButton(this, currentX, currentY, xSize, ySize, 3); currentX += xSize;
	minus = factory.CreateMinusButton(this, currentX, currentY, xSize, ySize); currentX = 0; currentY += ySize;

	//EXAMPLE FOR BIND three->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &Main::OnButtonNumClicked, this);

	zero = factory.CreateNumberButton(this, currentX, currentY, xSize, ySize, 0); currentX += xSize;
	dot = factory.CreateDotButton(this, currentX, currentY, xSize, ySize); currentX += xSize;
	equals = factory.CreateEqualsButton(this, currentX, currentY, xSize, ySize); currentX += xSize;
	plus = factory.CreatePlusButton(this, currentX, currentY, xSize, ySize); currentX = 0; currentY += ySize;

	decimal = factory.CreateDecimalButton(this, currentX, currentY, xSize, ySize); currentX += xSize;
	binary = factory.CreateBinaryButton(this, currentX, currentY, xSize, ySize); currentX += xSize;
	hex = factory.CreateHexButton(this, currentX, currentY, xSize, ySize); currentX += xSize;
}

bool nextMustBeNumber = true; //If next number must be number or not


void Main::OnButtonClicked(wxCommandEvent& evnt)
{
	Processor* processor = processor->GetInstance();
	int num = evnt.GetId();
	if (num == 42 && nextMustBeNumber == false) // Multiplication *
	{
		nextMustBeNumber = true;
		operations->AppendText((char)num);
		processor->AddOperationMultiplication();
	}
	else if (num == 43 && nextMustBeNumber == false) // Addition *
	{
		nextMustBeNumber = true;
		operations->AppendText((char)num);
		processor->AddOperationAddition();
	}
	else if (num == 45 && nextMustBeNumber == false) // Substraction *
	{
		nextMustBeNumber = true;
		operations->AppendText((char)num);
		processor->AddOperationSubstraction();
	}
	else if (num == 46 && nextMustBeNumber == false)
	{
		nextMustBeNumber = true;
		operations->AppendText((char)num);
	}
	else if (num == 47 && nextMustBeNumber == false) // Divition *
	{
		nextMustBeNumber = true;
		operations->AppendText((char)num);
		processor->AddOperationDivition();
	}
	else if (num == 61) //Equals
	{
		if (!nextMustBeNumber)
		{
			wxString operation = operations->GetValue();
			std::string str = std::string(operation.mb_str());
			double result = processor->Calculate(str);
			std::string answer;
			if (result == (int)result)
			{
				answer = std::to_string((int)result);
			}
			else
			{
				answer = std::to_string(result);
			}
			operations->SetLabel(answer);
			processor->Clear();
		}
	}
	else if (num == 20) //ON / OFF button
	{
		this->Destroy();
	}
	else if (num == 17) // Clear
	{
		operations->Clear();
		processor->Clear();
		nextMustBeNumber = true;
	}
	else if (num <= 57 && num >= 48)
	{
		nextMustBeNumber = false;
		wxButton* pButton = dynamic_cast<wxButton*>(evnt.GetEventObject());
		operations->AppendText(pButton->GetLabel());
	}
	else if (num == 30) //Decimal
	{
		operations->SetValue(processor->GetDecimal());
	}
	else if (num == 31) //Binary
	{
		long val;
		if (operations->GetValue().ToLong(&val))
		{
			processor->SetBaseNumber(val);
			operations->SetValue(processor->GetBinary());
		}
		else
		{
			operations->SetValue("Syntax Error");
		}
	}
	else if (num == 32) //HEX
	{
		long val;
		if (operations->GetValue().ToLong(&val))
		{
			processor->SetBaseNumber(val);
			operations->SetValue(processor->GetHexadecimal());
		}
		else
		{
			operations->SetValue("Syntax Error");
		}
	}
	else if (num == 18)  // NEGATIVE
	{
		double val;
		if (operations->GetValue().ToDouble(&val))
		{
			processor->SetBaseNumber(val);
			operations->SetValue(processor->GetNegative());
		}
		else
		{
			operations->SetValue("Syntax Error");
		}
	}
	else if (num == 37 && nextMustBeNumber == false) // MOD
	{
		nextMustBeNumber = true;
		operations->AppendText((char)num);
		processor->AddOperationMod();

	}
	evnt.Skip();
}



