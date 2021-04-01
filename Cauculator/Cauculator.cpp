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


	private:

};

