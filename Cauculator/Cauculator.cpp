#include <wx/wxprec.h>
#include <string.h>
#ifdef WX_PRECOMP
	#include <wx/wx.h>
#endif

class Calculator : public wxApp {
	public:
		virtual bool OnInit();

};

class MainFrame : public wxFrame {
	public:
		MainFrame();

	protected:
		wxMenuBar* m_mainMenuBar;
		wxMenu* m_menuEdit;
		wxMenu* m_menuHelp;

		wxStatusBar* m_mainStatusBar;

		wxBoxSizer* m_sizer;
		wxPanel* m_panelDisplay;
		wxPanel* m_panelButtons;

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
		void OnClearDisplay(wxCommandEvent& event);
		void OnExit(wxCommandEvent& event);
		void OnAbout(wxCommandEvent& event);
};

bool Calculator::OnInit() {
	MainFrame* frame = new MainFrame();
	frame->Show();

	return true;
}

enum {
	ID_Clear = 1
};

MainFrame::MainFrame() : wxFrame(NULL, wxID_ANY, "Calculator", wxDefaultPosition, wxDefaultSize, 
	wxSYSTEM_MENU | wxCAPTION | wxCLOSE_BOX | wxMINIMIZE_BOX | wxCLIP_CHILDREN) {

	m_mainMenuBar = new wxMenuBar(0);
	m_menuEdit = new wxMenu();
	m_menuHelp = new wxMenu();

	m_menuEdit->Append(ID_Clear,"Clear \tCtrl+N");
	m_menuEdit->AppendSeparator();
	m_menuEdit->Append(wxID_EXIT);

	m_menuHelp->Append(wxID_ABOUT);

	m_mainMenuBar->Append(m_menuEdit, "Edit");
	m_mainMenuBar->Append(m_menuHelp, "Help");

	this->SetMenuBar(m_mainMenuBar);
	
	m_panelDisplay = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(198, 45));
	m_panelDisplay->SetBackgroundColour(wxColour(229, 239, 242));

	m_panelButtons = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(198, 195));
	m_panelButtons->SetBackgroundColour(wxColour(229, 239, 242));

	const int initX = 3, initY = 5;
	//---Create All Buttons
	m_backspaceButton = new wxButton(m_panelButtons, wxID_ANY, wxString("<-"), wxPoint(initX, initY), wxSize(34, 29), 0);
	m_clearentryButton = new wxButton(m_panelButtons, wxID_ANY, wxString("CE"), wxPoint(initX + 39, initY), wxSize(34, 29), 0);
	m_clearButton = new wxButton(m_panelButtons, wxID_ANY, wxString("C"), wxPoint(initX + 78, initY), wxSize(34, 29), 0);
	m_plusorminusButton = new wxButton(m_panelButtons, wxID_ANY, wxString("±"), wxPoint(initX + 117, initY), wxSize(34, 29), 0);
	m_squareButton = new wxButton(m_panelButtons, wxID_ANY, wxString("V"), wxPoint(initX + 156, initY), wxSize(34, 29), 0);
	
	m_numbersButtons[7] = new wxButton(m_panelButtons, wxID_ANY, wxString("7"), wxPoint(initX , initY + 34), wxSize(34, 29), 0);
	m_numbersButtons[8] = new wxButton(m_panelButtons, wxID_ANY, wxString("8"), wxPoint(initX + 39, initY + 34), wxSize(34, 29), 0);
	m_numbersButtons[9] = new wxButton(m_panelButtons, wxID_ANY, wxString("9"), wxPoint(initX + 78, initY + 35), wxSize(34, 29), 0);
	m_divideButton = new wxButton(m_panelButtons, wxID_ANY, wxString("/"), wxPoint(initX + 117, initY + 34), wxSize(34, 29), 0);
	m_modorpercentButton = new wxButton(m_panelButtons, wxID_ANY, wxString("%"), wxPoint(initX + 156, initY + 34), wxSize(34, 29), 0);

	m_numbersButtons[4] = new wxButton(m_panelButtons, wxID_ANY, wxString("4"), wxPoint(initX, initY + 68), wxSize(34, 29), 0);
	m_numbersButtons[5] = new wxButton(m_panelButtons, wxID_ANY, wxString("5"), wxPoint(initX + 39, initY + 68), wxSize(34, 29), 0);
	m_numbersButtons[6] = new wxButton(m_panelButtons, wxID_ANY, wxString("6"), wxPoint(initX + 78, initY + 68), wxSize(34, 29), 0);
	m_mutiplyButton = new wxButton(m_panelButtons, wxID_ANY, wxString("*"), wxPoint(initX + 117, initY + 68), wxSize(34, 29), 0);
	m_reciprocalButton = new wxButton(m_panelButtons, wxID_ANY, wxString("1/x"), wxPoint(initX + 156, initY + 68), wxSize(34, 29), 0);

	m_numbersButtons[1] = new wxButton(m_panelButtons, wxID_ANY, wxString("1"), wxPoint(initX, initY + 102), wxSize(34, 29), 0);
	m_numbersButtons[2] = new wxButton(m_panelButtons, wxID_ANY, wxString("2"), wxPoint(initX + 39, initY + 102), wxSize(34, 29), 0);
	m_numbersButtons[3] = new wxButton(m_panelButtons, wxID_ANY, wxString("3"), wxPoint(initX + 78, initY + 102), wxSize(34, 29), 0);
	m_minusButton = new wxButton(m_panelButtons, wxID_ANY, wxString("-"), wxPoint(initX + 117, initY + 102), wxSize(34, 29), 0);
	m_equalButton = new wxButton(m_panelButtons, wxID_ANY, wxString("="), wxPoint(initX + 156, initY + 102), wxSize(34, 63), 0);

	m_numbersButtons[0] = new wxButton(m_panelButtons, wxID_ANY, wxString("0"), wxPoint(initX, initY + 136), wxSize(73, 29), 0);
	m_comaButton = new wxButton(m_panelButtons, wxID_ANY, wxString("."), wxPoint(initX + 78, initY + 136), wxSize(34, 29), 0);
	m_plusButton = new wxButton(m_panelButtons, wxID_ANY, wxString("+"), wxPoint(initX + 117, initY + 136), wxSize(34, 29), 0);
	//---

	m_sizer = new wxBoxSizer(wxVERTICAL);
	m_sizer->Add(m_panelDisplay, 0, wxALL, 10);
	m_sizer->Add(m_panelButtons, 0, wxBOTTOM | wxRIGHT | wxLEFT, 10);
	
	this->SetSizerAndFit(m_sizer);

	this->Centre(wxBOTH);

	Bind(wxEVT_MENU, &MainFrame::OnClearDisplay, this, ID_Clear);
	Bind(wxEVT_MENU, &MainFrame::OnExit, this, wxID_EXIT);
	Bind(wxEVT_MENU, &MainFrame::OnAbout, this, wxID_ABOUT);

}

wxIMPLEMENT_APP(Calculator);

void MainFrame::OnExit(wxCommandEvent& event) {
	Close(true);
}

void MainFrame::OnClearDisplay(wxCommandEvent& event) {
	wxMessageBox("Test... Clear Button", "Clear...", wxOK | wxICON_INFORMATION);
}

void MainFrame::OnAbout(wxCommandEvent& event) {
	wxMessageBox("This Calculator made in C/C++ by Isaac Soares", "About Calculator", wxOK | wxICON_INFORMATION);
}