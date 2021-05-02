#include "Cauculator.h"

class Calculator : public wxApp {
public:
	virtual bool OnInit ();

};

bool Calculator::OnInit () {
	MainFrame* frame = new MainFrame ();
	frame->Show ();

	return true;
}

wxIMPLEMENT_APP(Calculator);