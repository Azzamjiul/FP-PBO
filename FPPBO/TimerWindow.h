#pragma once
#include <wx\wx.h>

class Box;

class TimerWindow : public wxWindow
{
public:
	TimerWindow(wxFrame *frame);
	~TimerWindow();
	void OnPaint(wxPaintEvent &event);
	void OnTimer(wxTimerEvent &event);
private:
	wxTimer *timer;
	Box *box;
	DECLARE_EVENT_TABLE()
};