#pragma once
#include <wx\wx.h>
class TimerWindow;
class TimerFrame : public wxFrame
{
private:
	TimerWindow *window;
public:
	TimerFrame(const wxString &title);
};