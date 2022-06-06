#include "Calculator.h"
wxIMPLEMENT_APP(Calculator);

Calculator::Calculator()
{

}
Calculator:: ~Calculator()
{

}

bool Calculator::OnInit()
{
	calc = new Main();
	calc->Show();
	return true;
}