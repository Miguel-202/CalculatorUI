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






