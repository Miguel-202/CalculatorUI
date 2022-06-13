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

};




