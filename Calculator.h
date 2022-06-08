#pragma once

#include "Main.h"

class Calculator : public wxApp
{
public:
	Calculator();
	~Calculator();

private:
	Main* calc = nullptr;

public:
	virtual bool OnInit();
};

