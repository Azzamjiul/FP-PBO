#include "TimerFrame.h"
#include "TimerWindow.h"
TimerFrame::TimerFrame(const wxString &title)
	: wxFrame(NULL, wxID_ANY, title)
{
	window = new TimerWindow(this);
	SetInitialSize(wxSize(640, 480));
}