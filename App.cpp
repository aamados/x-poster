#include "App.h"
#include <wx/wx.h>
#include "MainFrame.h"

// Lets wxWidges know which class represents the Application
wxIMPLEMENT_APP(App);

bool App::OnInit()
{
	MainFrame* mainFrame = new MainFrame("X-Poster");
	mainFrame->SetClientSize(800, 600);
	mainFrame->Center();
	mainFrame->Show();
	return true;
}