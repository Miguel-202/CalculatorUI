#pragma once
#include "wx/wx.h"
class ButtonFactory
{
public:
	wxButton* CreatePowerButton(wxWindow* parent, int currentX, int currentY, int xSize, int ySize);
	wxButton* CreateModButton(wxWindow* parent, int currentX, int currentY, int xSize, int ySize);
	wxButton* CreateNegativeButton(wxWindow* parent, int currentX, int currentY, int xSize, int ySize);
	wxButton* CreateClearButton(wxWindow* parent, int currentX, int currentY, int xSize, int ySize);

	wxButton* CreateNumberButton(wxWindow* parent, int currentX, int currentY, int xSize, int ySize, int num);

	wxButton* CreatePlusButton(wxWindow* parent, int currentX, int currentY, int xSize, int ySize);
	wxButton* CreateMinusButton(wxWindow* parent, int currentX, int currentY, int xSize, int ySize);
	wxButton* CreateDivideButton(wxWindow* parent, int currentX, int currentY, int xSize, int ySize);
	wxButton* CreateMultiplyButton(wxWindow* parent, int currentX, int currentY, int xSize, int ySize);
	wxButton* CreateEqualsButton(wxWindow* parent, int currentX, int currentY, int xSize, int ySize);

	wxButton* CreateDotButton(wxWindow* parent, int currentX, int currentY, int xSize, int ySize);
	wxButton* CreateDecimalButton(wxWindow* parent, int currentX, int currentY, int xSize, int ySize);
	wxButton* CreateBinaryButton(wxWindow* parent, int currentX, int currentY, int xSize, int ySize);
	wxButton* CreateHexButton(wxWindow* parent, int currentX, int currentY, int xSize, int ySize);

};




