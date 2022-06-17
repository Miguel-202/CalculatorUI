#include "ButtonFactory.h"
#include "Main.h"

 wxButton* ButtonFactory :: CreatePowerButton(wxWindow* parent, int currentX, int currentY, int xSize, int ySize)
{
	wxButton* _power = new wxButton(parent, 20, "ON / OFF", wxPoint(currentX, currentY), wxSize(xSize, ySize));
	_power->SetBackgroundColour(*wxRED);
	return _power;
}

 wxButton* ButtonFactory::CreateModButton(wxWindow* parent, int currentX, int currentY, int xSize, int ySize)
 {
	 wxButton* _mod = new wxButton(parent, 37, "MOD", wxPoint(currentX, currentY), wxSize(xSize, ySize));
	 _mod->SetBackgroundColour(*wxLIGHT_GREY);
	 return _mod;
 }
 wxButton* ButtonFactory::CreateNegativeButton(wxWindow* parent, int currentX, int currentY, int xSize, int ySize)
 {
	 wxButton* _neg = new wxButton(parent, 18, "NEGATIVE", wxPoint(currentX, currentY), wxSize(xSize, ySize));
	 _neg->SetBackgroundColour(*wxLIGHT_GREY);
	 return _neg;
 }
 wxButton* ButtonFactory::CreateClearButton(wxWindow* parent, int currentX, int currentY, int xSize, int ySize)
 {
	 wxButton* _clear = new wxButton(parent, 17, "CLEAR", wxPoint(currentX, currentY), wxSize(xSize, ySize));
	 _clear->SetBackgroundColour(*wxRED);
	 return _clear;
 }

 wxButton* ButtonFactory::CreateNumberButton(wxWindow* parent, int currentX, int currentY, int xSize, int ySize, int num)
 {
	 wxButton* _num = new wxButton(parent, 48+num, std::to_string(num), wxPoint(currentX, currentY), wxSize(xSize, ySize));
	 return _num;
 }
 wxButton* ButtonFactory::CreatePlusButton(wxWindow* parent, int currentX, int currentY, int xSize, int ySize)
 {
	 wxButton* plus = new wxButton(parent, 43, "+", wxPoint(currentX, currentY), wxSize(xSize, ySize));
	 plus->SetBackgroundColour(*wxLIGHT_GREY);
	 return plus;
 }
 wxButton* ButtonFactory::CreateMinusButton(wxWindow* parent, int currentX, int currentY, int xSize, int ySize)
 {
	 wxButton* minus = new wxButton(parent, 45, "-", wxPoint(currentX, currentY), wxSize(xSize, ySize));
	 minus->SetBackgroundColour(*wxLIGHT_GREY);
	 return minus;
 }
 wxButton* ButtonFactory::CreateDivideButton(wxWindow* parent, int currentX, int currentY, int xSize, int ySize)
 {
	 wxButton* divide = new wxButton(parent, 47, "/", wxPoint(currentX, currentY), wxSize(xSize, ySize));
	 divide->SetBackgroundColour(*wxLIGHT_GREY);
	 return divide;
 }
 wxButton* ButtonFactory::CreateMultiplyButton(wxWindow* parent, int currentX, int currentY, int xSize, int ySize)
 {
	 wxButton* multiply = new wxButton(parent, 42, "*", wxPoint(currentX, currentY), wxSize(xSize, ySize));
	 multiply->SetBackgroundColour(*wxLIGHT_GREY);
	 return multiply;
 }
 wxButton* ButtonFactory::CreateEqualsButton(wxWindow* parent, int currentX, int currentY, int xSize, int ySize)
 {
	 wxButton* equals = new wxButton(parent, 61, "=", wxPoint(currentX, currentY), wxSize(xSize, ySize));
	 equals->SetBackgroundColour(*wxRED);
	 return equals;
 }

 wxButton* ButtonFactory::CreateDotButton(wxWindow* parent, int currentX, int currentY, int xSize, int ySize)
 {
	 wxButton* dot = new wxButton(parent, 46, ".", wxPoint(currentX, currentY), wxSize(xSize, ySize));
	 return dot;
 }
 wxButton* ButtonFactory::CreateDecimalButton(wxWindow* parent, int currentX, int currentY, int xSize, int ySize)
 {
	 wxButton* decimal = new wxButton(parent, 30, "DECIMAL", wxPoint(currentX, currentY), wxSize(xSize, ySize));
	 decimal->SetBackgroundColour(*wxLIGHT_GREY);
	 return decimal;
 }
 wxButton* ButtonFactory::CreateBinaryButton(wxWindow* parent, int currentX, int currentY, int xSize, int ySize)
 {
	 wxButton* binary = new wxButton(parent, 31, "BINARY", wxPoint(currentX, currentY), wxSize(xSize, ySize));
	 binary->SetBackgroundColour(*wxLIGHT_GREY);
	 return binary;
 }
 wxButton* ButtonFactory::CreateHexButton(wxWindow* parent, int currentX, int currentY, int xSize, int ySize)
 {
	 wxButton* hex = new wxButton(parent, 32, "HEX", wxPoint(currentX, currentY), wxSize(xSize, ySize));
	 hex->SetBackgroundColour(*wxLIGHT_GREY);
	 return hex;
 }





