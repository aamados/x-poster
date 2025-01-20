#include "MainFrame.h"
#include <wx/wx.h>

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
	wxPanel* panel = new wxPanel(this);

	wxButton* button1 = new wxButton(panel, wxID_ANY, "Button", wxPoint(300, 275), wxSize(200, 50));
	wxButton* button2 = new wxButton(panel, wxID_ANY, "Button", wxPoint(300, 350), wxSize(200, 50));

	// Bind() comes from the wxEVTHandler, which every control inherits
	// Call Bind() on MainFrame
	this->Bind(wxEVT_BUTTON, &MainFrame::OnAnyButtonClicked, this);

	this->Bind(wxEVT_CLOSE_WINDOW, &MainFrame::OnClose, this);

	// Button-Specific events
	button1->Bind(wxEVT_BUTTON, &MainFrame::OnButton1Clicked, this);
	button2->Bind(wxEVT_BUTTON, &MainFrame::OnButton2Clicked, this);

	// Inherited from wxFrame
	CreateStatusBar();
}

// evt.Skip() is called here. If it isn't, MainFrame will not close because the actual closing
// of the frame is from the parent class, wxFrame.
// Simply, because the child had its event called, the parent will not do so unless Skip() is called.
void MainFrame::OnClose(wxCloseEvent& evt)
{
	wxLogMessage("Frame Closed");
	evt.Skip();
}

// Since we bind the event to MainFrame, this event is invoked when ANY button is pressed.
// This may be useful for playing a sound when ANY button is clicked for example.
void MainFrame::OnAnyButtonClicked(wxCommandEvent& evt)
{
	// Displays a message in a box instead of in a status bar
	wxLogMessage("Button Clicked");
}

// Calling evt.Skip() tells wxWidgets that Event Propagation should continue.
// In other words, we will see the specific button event called AND OnAnyButtonClicked() called.
void MainFrame::OnButton1Clicked(wxCommandEvent& evt)
{
	wxLogStatus("Button 1 Clicked");
	evt.Skip();
}

void MainFrame::OnButton2Clicked(wxCommandEvent& evt)
{
	wxLogStatus("Button 2 Clicked");
	evt.Skip();
}