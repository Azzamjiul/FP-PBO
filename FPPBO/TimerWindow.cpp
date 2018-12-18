#include "TimerWindow.h"
#include "Box.h"
#define TIMER_ID 2000

BEGIN_EVENT_TABLE(TimerWindow, wxWindow)
	EVT_PAINT(TimerWindow::OnPaint)
	EVT_TIMER(TIMER_ID, TimerWindow::OnTimer)
END_EVENT_TABLE()

TimerWindow::TimerWindow(wxFrame *frame)
	: wxWindow(frame, wxID_ANY)
{
	SetBackgroundColour(wxColour(*wxWHITE));
	timer = new wxTimer(this, TIMER_ID);
	//memulai timer dengan interval 1000ms atau 1s.
	//timer->Start(1000);

	//memulai timer dengan interval 500ms atau 0,05s.
	timer->Start(50);

	box = new Box(10, 10, 50, 50);
}

TimerWindow::~TimerWindow()
{
	timer->Stop();
	delete timer;
	delete box;
}


void TimerWindow::OnPaint(wxPaintEvent &event)
{
	wxPaintDC pdc(this);
	this->box->Draw(pdc);
}

void TimerWindow::OnTimer(wxTimerEvent &event)
{
	static int counter = 0;
	wxMessageOutputDebug().Printf("wxTimer event %d.", counter++);

	if (box != nullptr)
	{
		box->Move(5, 2, GetClientSize().GetWidth(),GetClientSize().GetHeight());
		Refresh();
	}
}