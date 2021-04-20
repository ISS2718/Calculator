#include <wx/wxprec.h>
#include <string.h>
#ifdef WX_PRECOMP
#include <wx/wx.h>
#endif

#define marginButtons 5
#define heightButtons 27
#define doubleHeightButtons (2 * heightButtons + marginButtons)
#define widthButtons 34
#define doubleWidthButtons (2 * widthButtons + marginButtons)
#define pointButtonsX (widthButtons + marginButtons)
#define pointButtonsY (heightButtons + marginButtons)

class Calculator : public wxApp {
public:
	virtual bool OnInit ();

};

class MainFrame : public wxFrame {
public:
	MainFrame ();

protected:
	wxMenuBar* m_mainMenuBar;
	wxMenu* m_menuEdit;
	wxMenu* m_menuHelp;

	wxStatusBar* m_mainStatusBar;

	wxBoxSizer* m_sizer;

	wxPanel* m_panelDisplay;
	wxPanel* m_panelButtons;
	wxPanel* m_panelSeparator;

	wxStaticText* m_botDisplay;
	wxStaticText* m_topDisplay;

	wxButton* m_memoryClearButton;
	wxButton* m_memoryRecallButton;
	wxButton* m_memoryStoreButton;
	wxButton* m_memoryAddButton;
	wxButton* m_memoryRemoveButton;

	wxButton* m_backspaceButton;
	wxButton* m_clearentryButton;
	wxButton* m_clearButton;
	wxButton* m_plusorminusButton;
	wxButton* m_squareButton;
	wxButton* m_divideButton;
	wxButton* m_modorpercentButton; // modulus or percentage
	wxButton* m_mutiplyButton;
	wxButton* m_reciprocalButton; // inverse
	wxButton* m_minusButton;
	wxButton* m_plusButton;
	wxButton* m_equalButton; // result
	wxButton* m_comaButton;
	wxButton* m_numbersButtons[10];


private:
	void OnClearDisplay (wxCommandEvent& event);
	void OnExit (wxCommandEvent& event);
	void OnAbout (wxCommandEvent& event);
};

bool Calculator::OnInit () {
	MainFrame* frame = new MainFrame ();
	frame->Show ();

	return true;
}

enum {
	ID_Clear = 101
};

MainFrame::MainFrame () : wxFrame (NULL, wxID_ANY, "Calculator", wxDefaultPosition, wxDefaultSize,
	wxSYSTEM_MENU | wxCAPTION | wxCLOSE_BOX | wxMINIMIZE_BOX | wxCLIP_CHILDREN) {

	this->SetBackgroundColour(wxColour(204, 222, 242));

	m_mainMenuBar = new wxMenuBar (0);
	m_menuEdit = new wxMenu ();
	m_menuHelp = new wxMenu ();

	m_menuEdit->Append (ID_Clear, "Clear \tCtrl+N");
	m_menuEdit->AppendSeparator ();
	m_menuEdit->Append (wxID_EXIT);

	m_menuHelp->Append (wxID_ABOUT);

	m_mainMenuBar->Append (m_menuEdit, "Edit");
	m_mainMenuBar->Append (m_menuHelp, "Help");

	this->SetMenuBar (m_mainMenuBar);

	m_panelDisplay = new wxPanel (this, wxID_ANY, wxDefaultPosition, wxSize (190, 50), wxBORDER_SIMPLE);
	m_panelDisplay->SetBackgroundColour(wxColor(222, 232, 244));

	m_topDisplay = new wxStaticText (m_panelDisplay, wxID_ANY, wxString("0"),wxPoint(0, 0), wxSize(187, 15), wxALIGN_RIGHT);
	
	m_botDisplay = new wxStaticText (m_panelDisplay, wxID_ANY, wxString("0"), wxPoint(0, 15), wxSize(185, 35), wxALIGN_RIGHT);
	m_botDisplay->SetBackgroundColour(wxColor(255, 255, 255));

	m_panelSeparator = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize (190, 6));

	m_panelButtons = new wxPanel (this, wxID_ANY, wxDefaultPosition, wxSize (190, 188));

	//---Create All Buttons
	m_memoryClearButton = new wxButton (
		m_panelButtons, 
		wxID_ANY, 
		wxString  ("MC"), 
		wxPoint (0 * pointButtonsX * pointButtonsX, 0 * pointButtonsY),
		wxSize (widthButtons, heightButtons), 
		0);
	m_memoryRecallButton = new wxButton (
		m_panelButtons, 
		wxID_ANY, 
		wxString ("MR"),
		wxPoint (1 * pointButtonsX, 0 * pointButtonsY),
		wxSize (widthButtons, heightButtons), 
		0);
	m_memoryStoreButton = new wxButton (
		m_panelButtons, 
		wxID_ANY,
		wxString ("MS"), 
		wxPoint (2 * pointButtonsX, 0 * pointButtonsY),
		wxSize (widthButtons, heightButtons), 
		0);
	m_memoryAddButton = new wxButton (
		m_panelButtons, 
		wxID_ANY, 
		wxString ("M+"), 
		wxPoint (3 * pointButtonsX, 0 * pointButtonsY),
		wxSize (widthButtons, heightButtons),
		0);
	m_memoryRemoveButton = new wxButton (
		m_panelButtons, 
		wxID_ANY, 
		wxString ("M-"), 
		wxPoint (4 * pointButtonsX, 0 * pointButtonsY),
		wxSize (widthButtons, heightButtons),
		0);

	m_backspaceButton = new wxButton (
		m_panelButtons, 
		wxID_ANY, wxString ("<-"), 
		wxPoint (0 * pointButtonsX, 1 * pointButtonsY),
		wxSize (widthButtons, heightButtons), 
		0);
	m_clearentryButton = new wxButton (
		m_panelButtons,
		wxID_ANY, 
		wxString ("CE"), 
		wxPoint (1 * pointButtonsX, 1 *pointButtonsY),
		wxSize (widthButtons, 1 * heightButtons),
		0);
	m_clearButton = new wxButton (
		m_panelButtons, 
		wxID_ANY, 
		wxString ("C"), 
		wxPoint (2 * pointButtonsX, 1 * pointButtonsY),
		wxSize (widthButtons, heightButtons),
		0);
	m_plusorminusButton = new wxButton (
		m_panelButtons,
		wxID_ANY,
		wxString ("±"), 
		wxPoint (3 * pointButtonsX, 1 * pointButtonsY),
		wxSize (widthButtons, heightButtons),
		0);
	m_squareButton = new wxButton (
		m_panelButtons,
		wxID_ANY,
		wxString ("V"), 
		wxPoint (4 * pointButtonsX, 1 * pointButtonsY),
		wxSize (widthButtons, heightButtons),
		0);

	m_numbersButtons[7] = new wxButton (
		m_panelButtons,
		wxID_ANY,
		wxString ("7"), 
		wxPoint (0 * pointButtonsX, 2 * pointButtonsY),
		wxSize (widthButtons, heightButtons),
		0);
	m_numbersButtons[8] = new wxButton (
		m_panelButtons,
		wxID_ANY,
		wxString ("8"), 
		wxPoint (1 * pointButtonsX, 2 * pointButtonsY),
		wxSize (widthButtons, heightButtons),
		0);
	m_numbersButtons[9] = new wxButton (
		m_panelButtons,
		wxID_ANY,
		wxString ("9"), 
		wxPoint (2 * pointButtonsX, 2 * pointButtonsY),
		wxSize (widthButtons, heightButtons),
		0);
	m_divideButton = new wxButton (
		m_panelButtons,
		wxID_ANY,
		wxString ("/"),
		wxPoint (3 * pointButtonsX, 2 * pointButtonsY),
		wxSize (widthButtons, heightButtons),
		0);
	m_modorpercentButton = new wxButton (
		m_panelButtons,
		wxID_ANY,
		wxString ("%"), 
		wxPoint (4 * pointButtonsX, 2 * pointButtonsY),
		wxSize (widthButtons, heightButtons),
		0);

	m_numbersButtons[4] = new wxButton (
		m_panelButtons,
		wxID_ANY,
		wxString ("4"), 
		wxPoint (0 * pointButtonsX, 3 * pointButtonsY),
		wxSize (widthButtons, heightButtons),
		0);
	m_numbersButtons[5] = new wxButton (
		m_panelButtons,
		wxID_ANY,
		wxString ("5"), 
		wxPoint (1 * pointButtonsX, 3 * pointButtonsY),
		wxSize (widthButtons, heightButtons),
		0);
	m_numbersButtons[6] = new wxButton (
		m_panelButtons,
		wxID_ANY,
		wxString ("6"), 
		wxPoint (2 * pointButtonsX, 3 * pointButtonsY),
		wxSize (widthButtons, heightButtons),
		0);
	m_mutiplyButton = new wxButton (
		m_panelButtons,
		wxID_ANY,
		wxString ("*"), 
		wxPoint (3 * pointButtonsX, 3 * pointButtonsY),
		wxSize (widthButtons, heightButtons),
		0);
	m_reciprocalButton = new wxButton (
		m_panelButtons,
		wxID_ANY, wxString ("1/x"), 
		wxPoint (4 * pointButtonsX, 3 * pointButtonsY),
		wxSize (widthButtons, heightButtons),
		0);
	m_numbersButtons[1] = new wxButton (
		m_panelButtons,
		wxID_ANY,
		wxString ("1"), 
		wxPoint (0 * pointButtonsX, 4 * pointButtonsY),
		wxSize (widthButtons, heightButtons),
		0);
	m_numbersButtons[2] = new wxButton (
		m_panelButtons,
		wxID_ANY,
		wxString ("2"), 
		wxPoint (1 * pointButtonsX, 4 * pointButtonsY),
		wxSize (widthButtons, heightButtons),
		0);
	m_numbersButtons[3] = new wxButton (
		m_panelButtons,
		wxID_ANY,
		wxString ("3"),
		wxPoint (2 * pointButtonsX, 4 * pointButtonsY),
		wxSize (widthButtons, heightButtons),
		0);
	m_minusButton = new wxButton (
		m_panelButtons,
		wxID_ANY,
		wxString ("-"), 
		wxPoint (3 * pointButtonsX, 4 * pointButtonsY),
		wxSize (widthButtons, heightButtons),
		0);
	m_equalButton = new wxButton (
		m_panelButtons,
		wxID_ANY,
		wxString ("="), 
		wxPoint (4 * pointButtonsX, 4 * pointButtonsY),
		wxSize (widthButtons, doubleHeightButtons),
		0);
	m_numbersButtons[0] = new wxButton (
		m_panelButtons,
		wxID_ANY,
		wxString ("0"), 
		wxPoint (0 * pointButtonsX, 5 * pointButtonsY),
		wxSize (doubleWidthButtons, heightButtons),
		0);
	m_comaButton = new wxButton (
		m_panelButtons,
		wxID_ANY,
		wxString ("."), 
		wxPoint (2 * pointButtonsX, 5 * pointButtonsY),
		wxSize (widthButtons, heightButtons),
		0);
	m_plusButton = new wxButton (
		m_panelButtons,
		wxID_ANY,
		wxString ("+"), 
		wxPoint (3 * pointButtonsX, 5 * pointButtonsY),
		wxSize (widthButtons, heightButtons),
		0);
	//---

	m_sizer = new wxBoxSizer (wxVERTICAL);
	m_sizer->Add (m_panelDisplay, 0, wxTOP| wxRIGHT | wxLEFT, 10);
	m_sizer->Add(m_panelSeparator, 0);
	m_sizer->Add (m_panelButtons, 0, wxBOTTOM | wxRIGHT | wxLEFT, 10);

	this->SetSizerAndFit (m_sizer);

	this->Centre (wxBOTH);

	Bind (wxEVT_MENU, &MainFrame::OnClearDisplay, this, ID_Clear);
	Bind (wxEVT_MENU, &MainFrame::OnExit, this, wxID_EXIT);
	Bind (wxEVT_MENU, &MainFrame::OnAbout, this, wxID_ABOUT);

}

wxIMPLEMENT_APP (Calculator);

void MainFrame::OnExit (wxCommandEvent& event) {
	Close (true);
}

void MainFrame::OnClearDisplay (wxCommandEvent& event) {
	wxMessageBox ("Test... Clear Button", "Clear...", wxOK | wxICON_INFORMATION);
}

void MainFrame::OnAbout (wxCommandEvent& event) {
	wxMessageBox ("This Calculator made in C/C++ by Isaac Soares", "About Calculator", wxOK | wxICON_INFORMATION);
}