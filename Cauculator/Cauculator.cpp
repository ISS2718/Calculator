#include <wx/wxprec.h>
#include <string.h>
#include "ALL_IDs.h"
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

char m_numberTopDisplay[50] = "\n";
char m_numberBottomDisplay[17] = "0";

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

	wxPanel* m_panelButtons;
	wxPanel* m_panelDisplay;
	wxPanel* m_panelSeparator;

	wxStaticText* m_bottomDisplay;
	wxStaticText* m_topDisplay;

	wxButton* m_memoryClearButton;
	wxButton* m_memoryRecallButton;
	wxButton* m_memoryStoreButton;
	wxButton* m_memoryAddButton;
	wxButton* m_memoryRemoveButton;

	wxButton* m_backspaceButton;
	wxButton* m_clearEntryButton;
	wxButton* m_clearButton;
	wxButton* m_plusOrMinusButton;
	wxButton* m_squareButton;
	wxButton* m_divideButton;
	wxButton* m_modOrPercentButton; // modulus or percentage
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

	void OnClickEqual(wxCommandEvent& event);
	void OnClickPlus(wxCommandEvent& event);
	void OnClickMinus(wxCommandEvent& event);
	void OnClickDivide(wxCommandEvent& event);
	void OnClickMultiply(wxCommandEvent& event);
	void OnClickComa(wxCommandEvent& event);

	void OnClickZero(wxCommandEvent& event);
	void OnClickOne(wxCommandEvent& event);
	void OnClickTwo(wxCommandEvent& event);
	void OnClickThree(wxCommandEvent& event);
	void OnClickFour(wxCommandEvent& event);
	void OnClickFive(wxCommandEvent& event);
	void OnClickSix(wxCommandEvent& event);
	void OnClickSeven(wxCommandEvent& event);
	void OnClickEight(wxCommandEvent& event);
	void OnClickNine(wxCommandEvent& event);
};

bool Calculator::OnInit () {
	MainFrame* frame = new MainFrame ();
	frame->Show ();

	return true;
}

MainFrame::MainFrame () : wxFrame (NULL, wxID_ANY, "Calculator", wxDefaultPosition, wxDefaultSize,
	wxSYSTEM_MENU | wxCAPTION | wxCLOSE_BOX | wxMINIMIZE_BOX | wxCLIP_CHILDREN) {
	
	wxFont topFont(7, wxFONTFAMILY_ROMAN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, FALSE);

	this->SetBackgroundColour(wxColour(204, 222, 242));

	m_mainMenuBar = new wxMenuBar (0);
	m_menuEdit = new wxMenu ();
	m_menuHelp = new wxMenu ();

	m_menuEdit->Append (ID_mClear, "Clear \tCtrl+N");
	m_menuEdit->AppendSeparator ();
	m_menuEdit->Append (wxID_EXIT);

	m_menuHelp->Append (wxID_ABOUT);

	m_mainMenuBar->Append (m_menuEdit, "Edit");
	m_mainMenuBar->Append (m_menuHelp, "Help");

	this->SetMenuBar (m_mainMenuBar);

	m_panelDisplay = new wxPanel (this, wxID_ANY, wxDefaultPosition, wxSize (190, 50), wxBORDER_SIMPLE);
	m_panelDisplay->SetBackgroundColour(wxColor(222, 232, 244));

	m_topDisplay = new wxStaticText (m_panelDisplay, wxID_ANY, m_numberTopDisplay, wxPoint(0, -10), wxSize(187, 15), wxALIGN_RIGHT);
	m_topDisplay->SetFont(topFont);

	m_bottomDisplay = new wxStaticText (m_panelDisplay, wxID_ANY, m_numberBottomDisplay, wxPoint(0, 15), wxSize(185, 35), wxALIGN_RIGHT);
	m_bottomDisplay->SetBackgroundColour(wxColor(255, 255, 255));

	m_panelSeparator = new wxPanel (this, wxID_ANY, wxDefaultPosition, wxSize (190, 6));
	
	m_panelButtons = new wxPanel (this, wxID_ANY, wxDefaultPosition, wxSize(190, 188));
//---Create All Buttons
	m_memoryClearButton = new wxButton(
		m_panelButtons,
		ID_bClear,
		wxString("MC"),
		wxPoint(0 * pointButtonsX * pointButtonsX, 0 * pointButtonsY),
		wxSize(widthButtons, heightButtons),
		0);
	m_memoryRecallButton = new wxButton(
		m_panelButtons,
		ID_bMemoryRecall,
		wxString("MR"),
		wxPoint(1 * pointButtonsX, 0 * pointButtonsY),
		wxSize(widthButtons, heightButtons),
		0);
	m_memoryStoreButton = new wxButton(
		m_panelButtons,
		ID_bMemoryStore,
		wxString("MS"),
		wxPoint(2 * pointButtonsX, 0 * pointButtonsY),
		wxSize(widthButtons, heightButtons),
		0);
	m_memoryAddButton = new wxButton(
		m_panelButtons,
		ID_bMemoryAdd,
		wxString("M+"),
		wxPoint(3 * pointButtonsX, 0 * pointButtonsY),
		wxSize(widthButtons, heightButtons),
		0);
	m_memoryRemoveButton = new wxButton(
		m_panelButtons,
		ID_bMemoryRemove,
		wxString("M-"),
		wxPoint(4 * pointButtonsX, 0 * pointButtonsY),
		wxSize(widthButtons, heightButtons),
		0);

	m_backspaceButton = new wxButton(
		m_panelButtons,
		ID_bBackspace, wxString("<-"),
		wxPoint(0 * pointButtonsX, 1 * pointButtonsY),
		wxSize(widthButtons, heightButtons),
		0);
	m_clearEntryButton = new wxButton(
		m_panelButtons,
		ID_bClearEntry,
		wxString("CE"),
		wxPoint(1 * pointButtonsX, 1 * pointButtonsY),
		wxSize(widthButtons, 1 * heightButtons),
		0);
	m_clearButton = new wxButton(
		m_panelButtons,
		ID_bClear,
		wxString("C"),
		wxPoint(2 * pointButtonsX, 1 * pointButtonsY),
		wxSize(widthButtons, heightButtons),
		0);
	m_plusOrMinusButton = new wxButton(
		m_panelButtons,
		ID_bPlusOrMinus,
		wxString("±"),
		wxPoint(3 * pointButtonsX, 1 * pointButtonsY),
		wxSize(widthButtons, heightButtons),
		0);
	m_squareButton = new wxButton(
		m_panelButtons,
		ID_bSquare,
		wxString("V"),
		wxPoint(4 * pointButtonsX, 1 * pointButtonsY),
		wxSize(widthButtons, heightButtons),
		0);

	m_numbersButtons[7] = new wxButton(
		m_panelButtons,
		ID_bSeven,
		wxString("7"),
		wxPoint(0 * pointButtonsX, 2 * pointButtonsY),
		wxSize(widthButtons, heightButtons),
		0);
	m_numbersButtons[8] = new wxButton(
		m_panelButtons,
		ID_bEight,
		wxString("8"),
		wxPoint(1 * pointButtonsX, 2 * pointButtonsY),
		wxSize(widthButtons, heightButtons),
		0);
	m_numbersButtons[9] = new wxButton(
		m_panelButtons,
		ID_bNine,
		wxString("9"),
		wxPoint(2 * pointButtonsX, 2 * pointButtonsY),
		wxSize(widthButtons, heightButtons),
		0);
	m_divideButton = new wxButton(
		m_panelButtons,
		ID_bDivide,
		wxString("/"),
		wxPoint(3 * pointButtonsX, 2 * pointButtonsY),
		wxSize(widthButtons, heightButtons),
		0);
	m_modOrPercentButton = new wxButton(
		m_panelButtons,
		ID_bModOrPercent,
		wxString("%"),
		wxPoint(4 * pointButtonsX, 2 * pointButtonsY),
		wxSize(widthButtons, heightButtons),
		0);

	m_numbersButtons[4] = new wxButton(
		m_panelButtons,
		ID_bFour,
		wxString("4"),
		wxPoint(0 * pointButtonsX, 3 * pointButtonsY),
		wxSize(widthButtons, heightButtons),
		0);
	m_numbersButtons[5] = new wxButton(
		m_panelButtons,
		ID_bFive,
		wxString("5"),
		wxPoint(1 * pointButtonsX, 3 * pointButtonsY),
		wxSize(widthButtons, heightButtons),
		0);
	m_numbersButtons[6] = new wxButton(
		m_panelButtons,
		ID_bSix,
		wxString("6"),
		wxPoint(2 * pointButtonsX, 3 * pointButtonsY),
		wxSize(widthButtons, heightButtons),
		0);
	m_mutiplyButton = new wxButton(
		m_panelButtons,
		ID_bMultiply,
		wxString("*"),
		wxPoint(3 * pointButtonsX, 3 * pointButtonsY),
		wxSize(widthButtons, heightButtons),
		0);
	m_reciprocalButton = new wxButton(
		m_panelButtons,
		ID_bReciprocal, wxString("1/x"),
		wxPoint(4 * pointButtonsX, 3 * pointButtonsY),
		wxSize(widthButtons, heightButtons),
		0);
	m_numbersButtons[1] = new wxButton(
		m_panelButtons,
		ID_bOne,
		wxString("1"),
		wxPoint(0 * pointButtonsX, 4 * pointButtonsY),
		wxSize(widthButtons, heightButtons),
		0);
	m_numbersButtons[2] = new wxButton(
		m_panelButtons,
		ID_bTwo,
		wxString("2"),
		wxPoint(1 * pointButtonsX, 4 * pointButtonsY),
		wxSize(widthButtons, heightButtons),
		0);
	m_numbersButtons[3] = new wxButton(
		m_panelButtons,
		ID_bThree,
		wxString("3"),
		wxPoint(2 * pointButtonsX, 4 * pointButtonsY),
		wxSize(widthButtons, heightButtons),
		0);
	m_minusButton = new wxButton(
		m_panelButtons,
		ID_bMinus,
		wxString("-"),
		wxPoint(3 * pointButtonsX, 4 * pointButtonsY),
		wxSize(widthButtons, heightButtons),
		0);
	m_equalButton = new wxButton(
		m_panelButtons,
		ID_bEqual,
		wxString("="),
		wxPoint(4 * pointButtonsX, 4 * pointButtonsY),
		wxSize(widthButtons, doubleHeightButtons),
		0);
	m_numbersButtons[0] = new wxButton(
		m_panelButtons,
		ID_bZero,
		wxString("0"),
		wxPoint(0 * pointButtonsX, 5 * pointButtonsY),
		wxSize(doubleWidthButtons, heightButtons),
		0);
	m_comaButton = new wxButton(
		m_panelButtons,
		ID_bComa,
		wxString("."),
		wxPoint(2 * pointButtonsX, 5 * pointButtonsY),
		wxSize(widthButtons, heightButtons),
		0);
	m_plusButton = new wxButton(
		m_panelButtons,
		ID_bPlus,
		wxString("+"),
		wxPoint(3 * pointButtonsX, 5 * pointButtonsY),
		wxSize(widthButtons, heightButtons),
		0);

	m_sizer = new wxBoxSizer (wxVERTICAL);
	m_sizer->Add (m_panelDisplay, 0, wxTOP| wxRIGHT | wxLEFT, 10);
	m_sizer->Add(m_panelSeparator, 0);
	m_sizer->Add (m_panelButtons, 0, wxBOTTOM | wxRIGHT | wxLEFT, 10);
//---
	this->SetSizerAndFit (m_sizer);

	this->Centre (wxBOTH);

	Bind (wxEVT_MENU, &MainFrame::OnClearDisplay, this, ID_mClear);
	Bind (wxEVT_MENU, &MainFrame::OnExit, this, wxID_EXIT);
	Bind (wxEVT_MENU, &MainFrame::OnAbout, this, wxID_ABOUT);

	Bind(wxEVT_BUTTON, &MainFrame::OnClickDivide, this, ID_bDivide);
	Bind(wxEVT_BUTTON, &MainFrame::OnClickMultiply, this, ID_bMultiply);
	Bind(wxEVT_BUTTON, &MainFrame::OnClickMinus, this, ID_bMinus);
	Bind(wxEVT_BUTTON, &MainFrame::OnClickPlus, this, ID_bPlus);
	Bind(wxEVT_BUTTON, &MainFrame::OnClickEqual, this, ID_bEqual);
	Bind(wxEVT_BUTTON, &MainFrame::OnClickComa, this, ID_bComa);

	Bind(wxEVT_BUTTON, &MainFrame::OnClickZero, this, ID_bZero);
	Bind(wxEVT_BUTTON, &MainFrame::OnClickOne, this, ID_bOne);
	Bind(wxEVT_BUTTON, &MainFrame::OnClickTwo, this, ID_bTwo);
	Bind(wxEVT_BUTTON, &MainFrame::OnClickThree, this, ID_bThree);
	Bind(wxEVT_BUTTON, &MainFrame::OnClickFour, this, ID_bFour);
	Bind(wxEVT_BUTTON, &MainFrame::OnClickFive, this, ID_bFive);
	Bind(wxEVT_BUTTON, &MainFrame::OnClickSix, this, ID_bSix);
	Bind(wxEVT_BUTTON, &MainFrame::OnClickSeven, this, ID_bSeven);
	Bind(wxEVT_BUTTON, &MainFrame::OnClickEight, this, ID_bEight);
	Bind(wxEVT_BUTTON, &MainFrame::OnClickNine, this, ID_bNine);
	
	/*
	Bind(wxEVT_BUTTON, &MainFrame::OnClickMemoryClear, this, ID_bMemoryClear);
	Bind(wxEVT_BUTTON, &MainFrame::OnClickMemoryRecall, this, ID_bMemoryRecall);
	Bind(wxEVT_BUTTON, &MainFrame::OnClickMermoryStore, this, ID_bMemoryStore);
	Bind(wxEVT_BUTTON, &MainFrame::OnClickMemoryAdd, this, ID_bMemoryAdd);
	Bind(wxEVT_BUTTON, &MainFrame::OnClickMemoryRemove, this, ID_bMemoryRemove);

	Bind(wxEVT_BUTTON, &MainFrame::OnClickBackspace, this, ID_bBackspace);
	Bind(wxEVT_BUTTON, &MainFrame::OnClickClearEntry, this, ID_bClearEntry);
	Bind(wxEVT_BUTTON, &MainFrame::OnClickClear, this, ID_bClear);
	Bind(wxEVT_BUTTON, &MainFrame::OnClickPlusOrMinus, this, ID_bPlusOrMinus);
	Bind(wxEVT_BUTTON, &MainFrame::OnClickSquare, this, ID_bSquare);
	Bind(wxEVT_BUTTON, &MainFrame::OnClickREciprocal, this, ID_bReciprocal);
	Bind(wxEVT_BUTTON, &MainFrame::OnClickModOrPercent, this, ID_bModOrPercent);
	*/
}

wxIMPLEMENT_APP (Calculator);

void MainFrame::OnExit (wxCommandEvent& event) {
	Close (true);
}
void MainFrame::OnClearDisplay (wxCommandEvent& event) {
	strcpy(m_numberBottomDisplay, "0");
	strcpy(m_numberTopDisplay, "\n");
	m_bottomDisplay->SetLabelText(m_numberBottomDisplay);
	m_topDisplay->SetLabelText(m_numberTopDisplay);
}
void MainFrame::OnAbout (wxCommandEvent& event) {
	wxMessageBox ("This Calculator made in C/C++ by Isaac Soares", "About Calculator", wxOK | wxICON_INFORMATION);
}




void MainFrame::OnClickPlus (wxCommandEvent& event) {
	//TODO:Find out how many characters fit int topDisplay
	//TODO:Limit a topDisplay and bottomDisplay 

	if (m_numberBottomDisplay[0] != '0') {
		if (m_numberTopDisplay == "\n") {
			strcpy(m_numberTopDisplay, m_numberBottomDisplay);
			strcat(m_numberTopDisplay, " +");
		}
		else {
			strcat(m_numberTopDisplay, " ");
			strcat(m_numberTopDisplay, m_numberBottomDisplay);
			strcat(m_numberTopDisplay, " +");
		}
	}
	m_bottomDisplay->SetLabelText(m_numberBottomDisplay);
	m_topDisplay->SetLabelText(m_numberTopDisplay);
	strcpy(m_numberBottomDisplay, "0");
}
void MainFrame::OnClickMinus (wxCommandEvent& event) {
	//TODO:Find out how many characters fit int topDisplay
	//TODO:Limit a topDisplay and bottomDisplay 

	if (m_numberBottomDisplay[0] != '0') {
		if (m_numberTopDisplay == "\n") {
			strcpy(m_numberTopDisplay, m_numberBottomDisplay);
			strcat(m_numberTopDisplay, " -");
		}
		else {
			strcat(m_numberTopDisplay, " ");
			strcat(m_numberTopDisplay, m_numberBottomDisplay);
			strcat(m_numberTopDisplay, " -");
		}
	}
	m_bottomDisplay->SetLabelText(m_numberBottomDisplay);
	m_topDisplay->SetLabelText(m_numberTopDisplay);
	strcpy(m_numberBottomDisplay, "0");
}
void MainFrame::OnClickDivide (wxCommandEvent& event) {
	//TODO:Find out how many characters fit int topDisplay
	//TODO:Limit a topDisplay and bottomDisplay 

	if (m_numberBottomDisplay[0] != '0') {
		if (m_numberTopDisplay == "\n") {
			strcpy(m_numberTopDisplay, m_numberBottomDisplay);
			strcat(m_numberTopDisplay, " /");
		}
		else {
			strcat(m_numberTopDisplay, " ");
			strcat(m_numberTopDisplay, m_numberBottomDisplay);
			strcat(m_numberTopDisplay, " /");
		}
	}
	m_bottomDisplay->SetLabelText(m_numberBottomDisplay);
	m_topDisplay->SetLabelText(m_numberTopDisplay);
	strcpy(m_numberBottomDisplay, "0");
}
void MainFrame::OnClickMultiply (wxCommandEvent& event) {
	//TODO:Find out how many characters fit int topDisplay
	//TODO:Limit a topDisplay and bottomDisplay 

	if (m_numberBottomDisplay[0] != '0') {
		if (m_numberTopDisplay == "\n") {
			strcpy(m_numberTopDisplay, m_numberBottomDisplay);
			strcat(m_numberTopDisplay, " *");
		}
		else {
			strcat(m_numberTopDisplay, " ");
			strcat(m_numberTopDisplay, m_numberBottomDisplay);
			strcat(m_numberTopDisplay, " *");
		}
	}
	m_bottomDisplay->SetLabelText(m_numberBottomDisplay);
	m_topDisplay->SetLabelText(m_numberTopDisplay);
	strcpy(m_numberBottomDisplay, "0");
}
void MainFrame::OnClickEqual(wxCommandEvent& event) {

}


void MainFrame::OnClickComa (wxCommandEvent& event) {
	short int flag = 0;
	
	for (short int i = 0; i < 18; i++) {
		if (m_numberBottomDisplay[i] == '.') {
			flag = 1;
		}
	}
	if (flag == 0) {
		strcat(m_numberBottomDisplay, ".");
		m_bottomDisplay->SetLabelText(m_numberBottomDisplay);
	}
}
void MainFrame::OnClickZero (wxCommandEvent& event) {
	if (m_numberBottomDisplay[0] != '0') {
		strcat (m_numberBottomDisplay, "0");
	}
	m_bottomDisplay->SetLabelText(m_numberBottomDisplay);
}
void MainFrame::OnClickOne (wxCommandEvent& event) {
	if (m_numberBottomDisplay[0] != '0') {
		strcat (m_numberBottomDisplay, "1");
	}
	else {
		strcpy (m_numberBottomDisplay, "1");
	}
	m_bottomDisplay->SetLabelText(m_numberBottomDisplay);
}
void MainFrame::OnClickTwo (wxCommandEvent& event) {
	if (m_numberBottomDisplay[0] != '0') {
		strcat (m_numberBottomDisplay, "2");
	}
	else {
		strcpy (m_numberBottomDisplay, "2");
	}
	m_bottomDisplay->SetLabelText(m_numberBottomDisplay);
	
}
void MainFrame::OnClickThree (wxCommandEvent& event) {
	if (m_numberBottomDisplay[0] != '0') {
		strcat (m_numberBottomDisplay, "3");
	}
	else {
		strcpy (m_numberBottomDisplay, "3");
	}
	m_bottomDisplay->SetLabelText(m_numberBottomDisplay);
	
}
void MainFrame::OnClickFour (wxCommandEvent& event) {
	if (m_numberBottomDisplay[0] != '0') {
		strcat (m_numberBottomDisplay, "4");
	}
	else {
		strcpy (m_numberBottomDisplay, "4");
	}
	m_bottomDisplay->SetLabelText(m_numberBottomDisplay);
}
void MainFrame::OnClickFive (wxCommandEvent& event) {
	if (m_numberBottomDisplay[0] != '0') {
		strcat (m_numberBottomDisplay, "5");
	}
	else {
		strcpy (m_numberBottomDisplay, "5");
	}
	m_bottomDisplay->SetLabelText(m_numberBottomDisplay);
}
void MainFrame::OnClickSix (wxCommandEvent& event) {
	if (m_numberBottomDisplay[0] != '0') {
		strcat (m_numberBottomDisplay, "6");
	}
	else {
		strcpy (m_numberBottomDisplay, "6");
	}
	m_bottomDisplay->SetLabelText(m_numberBottomDisplay);
}
void MainFrame::OnClickSeven (wxCommandEvent& event) {
	if (m_numberBottomDisplay[0] != '0') {
		strcat (m_numberBottomDisplay, "7");
	}
	else {
		strcpy (m_numberBottomDisplay, "7");
	}
	m_bottomDisplay->SetLabelText(m_numberBottomDisplay);
}
void MainFrame::OnClickEight (wxCommandEvent& event) {
	if (m_numberBottomDisplay[0] != '0') {
		strcat (m_numberBottomDisplay, "8");
	}
	else {
		strcpy (m_numberBottomDisplay, "8");
	}
	m_bottomDisplay->SetLabelText(m_numberBottomDisplay);
}
void MainFrame::OnClickNine (wxCommandEvent& event) {
	if (m_numberBottomDisplay[0] != '0') {
		strcat (m_numberBottomDisplay, "9");
	}
	else {
		strcpy (m_numberBottomDisplay, "9");
	}
	m_bottomDisplay->SetLabelText(m_numberBottomDisplay);
}