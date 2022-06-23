#include "pch.h"
#include "ButtonFactoryTests.h"
int ButtonFactoryTests::GetIDButton(int button)
{
	wxWindow* win = new wxWindow();
	wxButton* butt = nullptr;
	if (button == 1) {
		butt = factory.CreateDecimalButton(win, 1, 1, 1, 1);
	}
	else if (button == 2) {
		butt = factory.CreateMultiplyButton(win, 1, 1, 1, 1);
	}
	else if (button == 3) {
		butt = factory.CreateDivideButton(win, 1, 1, 1, 1);
	}
	else if (button == 4) {
		butt = factory.CreateMinusButton(win, 1, 1, 1, 1);
	}
	else if (button == 5) {
		butt = factory.CreatePlusButton(win, 1, 1, 1, 1);
	}
	else if (button == 6) {
		butt = factory.CreateBinaryButton(win, 1, 1, 1, 1);
	}
	else
	{
		return 0;
	}
	return butt->GetId();
}
wxString ButtonFactoryTests::GetLabelDecimalButton()
{
	wxWindow* win = new wxWindow();
	wxButton* butt = factory.CreateDecimalButton(win, 1, 1, 1, 1);
	return butt->GetLabel();
}
wxColor ButtonFactoryTests::GetClearButtonColor()
{
	wxWindow* win = new wxWindow();
	wxButton* butt = factory.CreateClearButton(win, 1, 1, 1, 1);
	return butt->GetBackgroundColour();
}

wxColor ButtonFactoryTests::GetEqualsButtonColor()
{
	wxWindow* win = new wxWindow();
	wxButton* butt = factory.CreateEqualsButton(win, 1, 1, 1, 1);
	return butt->GetBackgroundColour();
}
wxColor ButtonFactoryTests::GetNegativeButtonColor()
{
	wxWindow* win = new wxWindow();
	wxButton* butt = factory.CreateNegativeButton(win, 1, 1, 1, 1);
	return butt->GetBackgroundColour();
}