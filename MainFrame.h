#pragma once
#include <wx/frame.h>

// Adding ': public wxFrame' makes it such that MainFrame inherits wxFrame
class MainFrame : public wxFrame
{
public:
	// wxString is the string implementation for wxWidgets
	MainFrame(const wxString& title);

private:
	void OnButtonClicked(wxCommandEvent& evt);
	void OnSliderChanged(wxCommandEvent& evt);
	void OnTextChanged(wxCommandEvent& evt);
};

