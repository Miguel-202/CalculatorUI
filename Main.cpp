#include "Main.h"
wxBEGIN_EVENT_TABLE(Main, wxFrame)
EVT_BUTTON(wxID_ANY, OnButtonNumClicked)
wxEND_EVENT_TABLE();

double width = 375;
double height = 679;
Main::Main() : wxFrame(nullptr, wxID_ANY, "Calculator", wxPoint(600,100), wxSize(width,height))
{
	//GRID 4x6
	double xSize = (width-20) / 4;
	double ySize = (height-35) / 7;
	double currentX = 0;
	double currentY = 0;


	operations = new wxTextCtrl(this, 10040, "", wxPoint(currentX, currentY), wxSize(xSize * 4, ySize ), wxTE_READONLY); currentY += ySize ;
	//wxListBox* result = new wxListBox(this, 10041, wxPoint(currentX, currentY), wxSize(xSize * 4, ySize / 2)); currentY += ySize / 2;

	power = new wxButton(this, 10020, "ON / OFF", wxPoint(currentX, currentY), wxSize(xSize, ySize)); currentX += xSize;
	power->SetBackgroundColour(*wxRED);
	mod = new wxButton(this, 10037, "MOD", wxPoint(currentX, currentY), wxSize(xSize, ySize)); currentX += xSize;
	mod->SetBackgroundColour(*wxLIGHT_GREY);
	negative = new wxButton(this, 10018, "NEGATIVE", wxPoint(currentX, currentY), wxSize(xSize, ySize)); currentX += xSize;
	negative->SetBackgroundColour(*wxLIGHT_GREY);
	clear = new wxButton(this, 10017, "CLEAR", wxPoint(currentX, currentY), wxSize(xSize, ySize)); currentX = 0;
	clear->SetBackgroundColour(*wxRED);
	currentY += ySize;

	seven = new wxButton(this, 10055, "7", wxPoint(currentX, currentY), wxSize(xSize, ySize)); currentX += xSize;
	//seven->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &Main::OnButtonNumClicked, this);
	eigth = new wxButton(this, 10056, "8", wxPoint(currentX, currentY), wxSize(xSize, ySize)); currentX += xSize;
	//eigth->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &Main::OnButtonNumClicked, this);
	nine = new wxButton(this, 10057, "9", wxPoint(currentX, currentY), wxSize(xSize, ySize)); currentX += xSize;
	//nine->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &Main::OnButtonNumClicked, this);
	divide = new wxButton(this, 10047, "/", wxPoint(currentX, currentY), wxSize(xSize, ySize)); currentX = 0;
	divide->SetBackgroundColour(*wxLIGHT_GREY);
	currentY += ySize;

	four = new wxButton(this, 10052, "4", wxPoint(currentX, currentY), wxSize(xSize, ySize)); currentX += xSize;
	//four->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &Main::OnButtonNumClicked, this);
	five = new wxButton(this, 10053, "5", wxPoint(currentX, currentY), wxSize(xSize, ySize)); currentX += xSize;
	//five->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &Main::OnButtonNumClicked, this);
	six = new wxButton(this, 10054, "6", wxPoint(currentX, currentY), wxSize(xSize, ySize)); currentX += xSize;
	//six->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &Main::OnButtonNumClicked, this);
	multiply = new wxButton(this, 10042, "*", wxPoint(currentX, currentY), wxSize(xSize, ySize)); currentX = 0;
	multiply->SetBackgroundColour(*wxLIGHT_GREY);
	currentY += ySize;

	one = new wxButton(this, 10049, "1", wxPoint(currentX,currentY), wxSize(xSize,ySize)); currentX += xSize;
	//one->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &Main::OnButtonNumClicked, this);
	two = new wxButton(this, 10050, "2", wxPoint(currentX, currentY), wxSize(xSize, ySize)); currentX += xSize;
	//two->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &Main::OnButtonNumClicked, this);
	three = new wxButton(this, 10051, "3", wxPoint(currentX, currentY), wxSize(xSize, ySize)); currentX += xSize;
	//three->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &Main::OnButtonNumClicked, this);
	minus = new wxButton(this, 10045, "-", wxPoint(currentX, currentY), wxSize(xSize, ySize)); currentX = 0;
	minus->SetBackgroundColour(*wxLIGHT_GREY);
	currentY += ySize;

	zero = new wxButton(this, 10048, "0", wxPoint(currentX, currentY), wxSize(xSize, ySize)); currentX += xSize;
	//zero->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &Main::OnButtonNumClicked, this);
	dot = new wxButton(this, 10046, ".", wxPoint(currentX, currentY), wxSize(xSize, ySize)); currentX += xSize;
	//dot->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &Main::OnButtonNumClicked, this);
	equals = new wxButton(this, 10061, "=", wxPoint(currentX, currentY), wxSize(xSize, ySize)); currentX += xSize;
	equals->SetBackgroundColour(*wxRED);
	plus = new wxButton(this, 10043, "+", wxPoint(currentX, currentY), wxSize(xSize, ySize)); currentX = 0;
	plus->SetBackgroundColour(*wxLIGHT_GREY);
	currentY += ySize;

	decimal = new wxButton(this, 10030, "DECIMAL", wxPoint(currentX, currentY), wxSize(xSize, ySize)); currentX += xSize;
	decimal->SetBackgroundColour(*wxLIGHT_GREY);
	binary = new wxButton(this, 10031, "BIN", wxPoint(currentX, currentY), wxSize(xSize, ySize)); currentX += xSize;
	binary->SetBackgroundColour(*wxLIGHT_GREY);
	hex = new wxButton(this, 10032, "HEX", wxPoint(currentX, currentY), wxSize(xSize, ySize)); currentX += xSize;
	hex->SetBackgroundColour(*wxLIGHT_GREY);
}

Main:: ~Main()
{

}


bool nextMustBeNumber = false; //If next number must be number or not
void Main::OnButtonNumClicked(wxCommandEvent& evnt)
{
	int num = evnt.GetId() - 10000;
	if (num >= 48 && num <= 57) //Numbers 0 to 9
	{
		operations->AppendText((char)num);
		nextMustBeNumber = false;
	}
	else if (num >= 42 && num <= 47 && nextMustBeNumber == false) // Are the + / * - . symbols
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
	evnt.Skip();
}


