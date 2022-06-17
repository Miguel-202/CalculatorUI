#include "Main.h"
#include "ButtonFactory.h"
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
	//wxListBox* result = new wxListBox(this, 10041, wxPoint(currentX, currentY), wxSize(xSize * 4, ySize / 2)); currentY += ySize / 2;
	power = factory.CreatePowerButton(this, currentX, currentY, xSize, ySize); currentX += xSize;
	mod = factory.CreateModButton(this, currentX, currentY, xSize, ySize); currentX += xSize;
	negative = factory.CreateNegativeButton(this, currentX, currentY, xSize, ySize); currentX += xSize;
	clear = factory.CreateClearButton(this, currentX, currentY, xSize, ySize); currentX = 0; currentY += ySize;

	seven = factory.CreateNumberButton(this, currentX, currentY, xSize, ySize, 7); currentX += xSize;
	eigth = factory.CreateNumberButton(this, currentX, currentY, xSize, ySize, 8); currentX += xSize;
	nine = factory.CreateNumberButton(this, currentX, currentY, xSize, ySize, 9); currentX += xSize;
	divide = new wxButton(this, 47, "/", wxPoint(currentX, currentY), wxSize(xSize, ySize)); currentX = 0;
	divide->SetBackgroundColour(*wxLIGHT_GREY);
	currentY += ySize;

	four = factory.CreateNumberButton(this, currentX, currentY, xSize, ySize, 4); currentX += xSize;
	five = factory.CreateNumberButton(this, currentX, currentY, xSize, ySize, 3); currentX += xSize;
	six = factory.CreateNumberButton(this, currentX, currentY, xSize, ySize, 2); currentX += xSize;
	multiply = new wxButton(this, 42, "*", wxPoint(currentX, currentY), wxSize(xSize, ySize)); currentX = 0;
	multiply->SetBackgroundColour(*wxLIGHT_GREY);
	currentY += ySize;

	one = factory.CreateNumberButton(this, currentX, currentY, xSize, ySize, 1); currentX += xSize;
	two = factory.CreateNumberButton(this, currentX, currentY, xSize, ySize, 2); currentX += xSize;
	three = factory.CreateNumberButton(this, currentX, currentY, xSize, ySize, 3); currentX += xSize;
	//three->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &Main::OnButtonNumClicked, this);
	minus = new wxButton(this, 45, "-", wxPoint(currentX, currentY), wxSize(xSize, ySize)); currentX = 0;
	minus->SetBackgroundColour(*wxLIGHT_GREY);
	currentY += ySize;

	zero = factory.CreateNumberButton(this, currentX, currentY, xSize, ySize, 0); currentX += xSize;
	dot = new wxButton(this, 46, ".", wxPoint(currentX, currentY), wxSize(xSize, ySize)); currentX += xSize;
	equals = new wxButton(this, 61, "=", wxPoint(currentX, currentY), wxSize(xSize, ySize)); currentX += xSize;
	equals->SetBackgroundColour(*wxRED);
	plus = new wxButton(this, 43, "+", wxPoint(currentX, currentY), wxSize(xSize, ySize)); currentX = 0;
	plus->SetBackgroundColour(*wxLIGHT_GREY);
	currentY += ySize;

	decimal = new wxButton(this, 30, "DECIMAL", wxPoint(currentX, currentY), wxSize(xSize, ySize)); currentX += xSize;
	decimal->SetBackgroundColour(*wxLIGHT_GREY);
	binary = new wxButton(this, 31, "BIN", wxPoint(currentX, currentY), wxSize(xSize, ySize)); currentX += xSize;
	binary->SetBackgroundColour(*wxLIGHT_GREY);
	hex = new wxButton(this, 32, "HEX", wxPoint(currentX, currentY), wxSize(xSize, ySize)); currentX += xSize;
	hex->SetBackgroundColour(*wxLIGHT_GREY);
}

bool nextMustBeNumber = false; //If next number must be number or not

void Main::OnButtonClicked(wxCommandEvent& evnt)
{
	int num = evnt.GetId();
	if (num >= 42 && num <= 47 && nextMustBeNumber == false) // Are the + / * - . symbols
	{
		nextMustBeNumber = true;
		int val = wxAtoi(operations->GetValue());
		operations->AppendText((char)num);
	}
	else if (num == 61) //Equals
	{
		wxString operation = operations->GetValue();

	}
	else if (num == 20) //ON / OFF button
	{
		this->Destroy();
	}
	else if (num == 17) // Clear
	{
		operations->Clear();
	}
	else if (num <= 57 && num >= 48)
	{
		nextMustBeNumber = false;
		wxButton* pButton = dynamic_cast<wxButton*>(evnt.GetEventObject());
		operations->AppendText(pButton->GetLabel());
	}
	evnt.Skip();
}



