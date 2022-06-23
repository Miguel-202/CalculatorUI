#pragma once

#include "..\ButtonFactory.h"
class ButtonFactoryTests
{
private:
	ButtonFactory factory;
public:
	int GetIDButton(int button);
	wxString GetLabelDecimalButton();
	wxColor GetClearButtonColor();

	wxColor GetEqualsButtonColor();
	wxColor GetNegativeButtonColor();
};

