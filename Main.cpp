#include "Main.h"
#include "ButtonFactory.h"
#include "Processor.h"
wxBEGIN_EVENT_TABLE(Main, wxFrame)
EVT_BUTTON(wxID_ANY, OnButtonClicked)
wxEND_EVENT_TABLE();

double width = 375;
double height = 679;
Main::Main() : wxFrame(nullptr, wxID_ANY, "Calculator", wxPoint(600,100), wxSize(width,height))
{
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
	five = factory.CreateNumberButton(this, currentX, currentY, xSize, ySize, 3); currentX += xSize;
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
Processor* processor =  processor->GetInstance();

void Main::OnButtonClicked(wxCommandEvent& evnt)
{
	int num = evnt.GetId();
	if (num >= 42 && num <= 47 && nextMustBeNumber == false) // Are the + / * - . symbols
	{
		nextMustBeNumber = true;
		operations->AppendText((char)num);
		processor->AddOperation('+');
	}
	else if (num == 61) //Equals
	{
		if (!nextMustBeNumber)
		{
			wxString operation = operations->GetValue();
			std::string str = std::string(operation.mb_str());
			double result = processor->Calculate(str);
			std::string answer = std::to_string(result);
			operations->SetLabel(answer);
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
	}
	else if (num <= 57 && num >= 48)
	{
		nextMustBeNumber = false;
		wxButton* pButton = dynamic_cast<wxButton*>(evnt.GetEventObject());
		operations->AppendText(pButton->GetLabel());
	}
	else if (num == 30) //Decimal
	{

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
	evnt.Skip();
}



