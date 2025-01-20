#include "MainFrame.h"
#include <wx/wx.h>

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
	wxPanel* panel = new wxPanel(this);
	wxButton* button = new wxButton(panel, wxID_ANY, "Button", wxPoint(300, 250), wxSize(200, 100));

	// A full list of mouse events can be found on https://docs.wxwidgets.org/3.0/classwx_mouse_event.html
	panel->Bind(wxEVT_MOTION, &MainFrame::OnMouseEvent, this);

	// We have to explicity call this event on the button. If we don't do this
	// OnMouseEvent will not be called when moving your mouse on the button.
	// This is because wxMouseEvent is not a wxCommandEvent, thus will not have
	// Event Propagation.
	button->Bind(wxEVT_MOTION, &MainFrame::OnMouseEvent, this);

	// Inherited from wxFrame
	wxStatusBar* bar = CreateStatusBar();

	// Eabling SetDoubleBuffered to true will prevent the flickering from happening.
	// This flickering most likely happens because wxEVT_MOTION happens to quickly.
	bar->SetDoubleBuffered(true);
}

void MainFrame::OnMouseEvent(wxMouseEvent& evt)
{
	// Using evt.GetPosition() will return the position of the mouse
	// relative to the object your mouse is in.
	// Calling wxGetMousePosition() instead will provide the mouse position
	// relative to the entire screen (including outisde of the frame).
	wxPoint mousePos = wxGetMousePosition();

	// Calling ScreenToClient() conver the screen coordinates
	// to frame coordinates.
	mousePos = this->ScreenToClient(mousePos);

	wxString message = wxString::Format("Moust Event Detected! (x=%d) (y=%d)", mousePos.x, mousePos.y);
	wxLogStatus(message);
}