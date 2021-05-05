#pragma once

#ifndef MainFrame
#define Mainframe

#include "framework.h"

using namespace std;

class MainFrame : public wxFrame{
public:
	MainFrame();
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

	char m_numberTopDisplay[50] = "\0";
	char m_numberBottomDisplay[17] = "0";
	double m_result = 0;
	bool m_equalClicked = 0;
	bool m_lastOpIsSqrRecp = 0;
	stack<double> m_values;
	stack<double> m_sum;
	stack<char> m_operators;
	double m_memoryStore = 0;
private:
	double Operations(const double FirstNumber, const double SecondNumber, const char operation);
	void SendToTopDisplays(const char Operator);
	void ShowResult(double number);

	void OnClearDisplay(wxCommandEvent& event);
	void OnExit(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);

	void OnClickClearEntry(wxCommandEvent& event);
	void OnClickBackspace(wxCommandEvent& event);

	void OnClickMemoryStore(wxCommandEvent& event);
	void OnClickMemoryClear(wxCommandEvent& event);
	void OnClickMemoryRecall(wxCommandEvent& event);
	void OnClickMemoryAdd(wxCommandEvent& event);
	void OnClickMemoryRemove(wxCommandEvent& event);

	void OnClickEqual(wxCommandEvent& event);
	void OnClickPlus(wxCommandEvent& event);
	void OnClickMinus(wxCommandEvent& event);
	void OnClickDivide(wxCommandEvent& event);
	void OnClickMultiply(wxCommandEvent& event);
	
	void OnClickModOrPercent(wxCommandEvent& event);
	void OnClickSquare(wxCommandEvent& event);
	void OnClickReciprocal(wxCommandEvent& event);

	void OnClickPlusOrMinus(wxCommandEvent& event);

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
	void OnClickComa(wxCommandEvent& event);
};

#endif MainFrame