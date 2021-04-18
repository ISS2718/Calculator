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
		wxButton* m_plussButton;
		wxButton* m_minusButton;
		wxButton* m_equalButton; // result
		wxButton* m_comaButton;
		wxButton* m_numbers[9];
	

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
	wxSYSTEM_MENU | wxCAPTION | wxCLOSE_BOX | wxCLIP_CHILDREN) {

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