#include "Main.h"
double width = 375;
double height = 679;
Main::Main() : wxFrame(nullptr, wxID_ANY, "Calculator", wxPoint(600,100), wxSize(width,height))
{
	//GRID 4x6
	double xSize = (width-20) / 4;
	double ySize = (height-35) / 7;
	double currentX = 0;
	double currentY = 0;


	wxTextCtrl* operations = new wxTextCtrl(this, 10040, "", wxPoint(currentX, currentY), wxSize(xSize * 4, ySize / 2)); currentY += ySize / 2;
	wxListBox* result = new wxListBox(this, 10041, wxPoint(currentX, currentY), wxSize(xSize * 4, ySize / 2)); currentY += ySize / 2;

	wxButton* power = new wxButton(this, 10020, "ON / OFF", wxPoint(currentX, currentY), wxSize(xSize, ySize)); currentX += xSize;
	wxButton* mod = new wxButton(this, 10019, "MOD", wxPoint(currentX, currentY), wxSize(xSize, ySize)); currentX += xSize;
	wxButton* negative = new wxButton(this, 10018, "NEGATIVE", wxPoint(currentX, currentY), wxSize(xSize, ySize)); currentX += xSize;
	wxButton* clear = new wxButton(this, 10017, "CLEAR", wxPoint(currentX, currentY), wxSize(xSize, ySize)); currentX = 0;
	currentY += ySize;

	wxButton* seven = new wxButton(this, 10007, "7", wxPoint(currentX, currentY), wxSize(xSize, ySize)); currentX += xSize;
	wxButton* eigth = new wxButton(this, 10008, "8", wxPoint(currentX, currentY), wxSize(xSize, ySize)); currentX += xSize;
	wxButton* nine = new wxButton(this, 10009, "9", wxPoint(currentX, currentY), wxSize(xSize, ySize)); currentX += xSize;
	wxButton* divide = new wxButton(this, 10016, "/", wxPoint(currentX, currentY), wxSize(xSize, ySize)); currentX = 0;
	currentY += ySize;

	wxButton* four = new wxButton(this, 10004, "4", wxPoint(currentX, currentY), wxSize(xSize, ySize)); currentX += xSize;
	wxButton* five = new wxButton(this, 10005, "5", wxPoint(currentX, currentY), wxSize(xSize, ySize)); currentX += xSize;
	wxButton* six = new wxButton(this, 10006, "6", wxPoint(currentX, currentY), wxSize(xSize, ySize)); currentX += xSize;
	wxButton* multiply = new wxButton(this, 10015, "X", wxPoint(currentX, currentY), wxSize(xSize, ySize)); currentX = 0;
	currentY += ySize;

	wxButton* one = new wxButton(this, 10001, "1", wxPoint(currentX,currentY), wxSize(xSize,ySize)); currentX += xSize;
	wxButton* two = new wxButton(this, 10002, "2", wxPoint(currentX, currentY), wxSize(xSize, ySize)); currentX += xSize;
	wxButton* three = new wxButton(this, 10003, "3", wxPoint(currentX, currentY), wxSize(xSize, ySize)); currentX += xSize;
	wxButton* minus = new wxButton(this, 10014, "-", wxPoint(currentX, currentY), wxSize(xSize, ySize)); currentX = 0;
	currentY += ySize;

	wxButton* zero = new wxButton(this, 10010, "0", wxPoint(currentX, currentY), wxSize(xSize, ySize)); currentX += xSize;
	wxButton* dot = new wxButton(this, 10011, ".", wxPoint(currentX, currentY), wxSize(xSize, ySize)); currentX += xSize;
	wxButton* equals = new wxButton(this, 10012, "=", wxPoint(currentX, currentY), wxSize(xSize, ySize)); currentX += xSize;
	wxButton* plus = new wxButton(this, 10013, "+", wxPoint(currentX, currentY), wxSize(xSize, ySize)); currentX = 0;
	currentY += ySize;

	wxButton* decimal = new wxButton(this, 10030, "DECIMAL", wxPoint(currentX, currentY), wxSize(xSize, ySize)); currentX += xSize;
	wxButton* binary = new wxButton(this, 10031, "BIN", wxPoint(currentX, currentY), wxSize(xSize, ySize)); currentX += xSize;
	wxButton* hex = new wxButton(this, 10032, "HEX", wxPoint(currentX, currentY), wxSize(xSize, ySize)); currentX += xSize;
}

Main:: ~Main()
{

}
