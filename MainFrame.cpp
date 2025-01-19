#include "MainFrame.h"
#include <wx/wx.h>

// IDs must be:
// 1. Must be positive
// 2. Cannot be 0 or 1
// 3. Cannot be from wxID_LOWEST (4999) to wxID_HIGHEST (5999)
enum IDs
{
	BUTTON_ID = 2,
	SLIDER_ID = 3,
	TEXT_ID = 4
};

// Link the button with BUTTON_ID to what was defined in
// OnButtonClicked in MainFrame.h
wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
	EVT_BUTTON(BUTTON_ID, MainFrame::OnButtonClicked)
	EVT_SLIDER(SLIDER_ID, MainFrame::OnSliderChanged)
	EVT_TEXT(TEXT_ID, MainFrame::OnTextChanged)
wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
	wxPanel* panel = new wxPanel(this);

	wxButton* button = new wxButton(panel, BUTTON_ID, "Button", wxPoint(300, 275), wxSize(200, 50));
	wxSlider* slider = new wxSlider(panel, SLIDER_ID, 0, 0, 100, wxPoint(300, 200), wxSize(200, -1));
	wxTextCtrl* txtCtrl = new wxTextCtrl(panel, TEXT_ID, "", wxPoint(300, 375), wxSize(200, -1));

	// Inherited from wxFrame
	CreateStatusBar();
}

void MainFrame::OnButtonClicked(wxCommandEvent& evt)
{
	wxLogStatus("Button Clicked");
}

void MainFrame::OnSliderChanged(wxCommandEvent& evt)
{
	wxString str = wxString::Format("Slider Value: %d", evt.GetInt());
	wxLogStatus(str);
}

void MainFrame::OnTextChanged(wxCommandEvent& evt)
{
	wxString str = wxString::Format("Text: %s", evt.GetString());
	wxLogStatus(str);
}

