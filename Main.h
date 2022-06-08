#pragma once
#include "wx/wx.h"
class Main : public wxFrame
{
public:
	Main();
	~Main();

public:
	wxTextCtrl* operations = nullptr;
	wxListBox* result = nullptr;
	
	wxButton* power = nullptr;
	wxButton* mod = nullptr;
	wxButton* negative = nullptr;
	wxButton* clear = nullptr;

	wxButton* divide = nullptr;
	wxButton* multiply = nullptr;
	wxButton* minus = nullptr;
	wxButton* plus = nullptr;
	wxButton* dot = nullptr;
	wxButton* equals = nullptr;
	wxButton* decimal = nullptr;
	wxButton* binary = nullptr;
	wxButton* hex = nullptr;

	wxButton* one = nullptr;
	wxButton* two = nullptr;
	wxButton* three = nullptr;
	wxButton* four = nullptr;
	wxButton* five = nullptr;
	wxButton* six = nullptr;
	wxButton* seven = nullptr;
	wxButton* eigth = nullptr;
	wxButton* nine = nullptr;
	wxButton* zero = nullptr;


	void OnButtonNumClicked(wxCommandEvent& evnt);

	wxDECLARE_EVENT_TABLE();

};

