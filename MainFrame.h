#pragma once
#include <wx/frame.h>

// Adding ': public wxFrame' makes it such that MainFrame inherits wxFrame
class MainFrame : public wxFrame
{
public:
	// wxString is the string implementation for wxWidgets
	MainFrame(const wxString& title);

private:
	void OnAnyButtonClicked(wxCommandEvent& evt);
	void OnButton1Clicked(wxCommandEvent& evt);
	void OnButton2Clicked(wxCommandEvent& evt);
	void OnClose(wxCloseEvent& evt);
};

