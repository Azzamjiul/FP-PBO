#pragma once
#include "wx\wx.h"
#include "Mobil.h"
#include "Lintasan.h"

class Mobil;
class Lintasan;

class GameWindow : public wxWindow
{
public:
	GameWindow(wxWindow *parent);
	~GameWindow();
	void OnPaint(wxPaintEvent &event);
	void OnTimer(wxTimerEvent &event);
	void OnKeyDown(wxKeyEvent &event);
	void OnKeyUp(wxKeyEvent &event);
private:
	Mobil *Car1;
	Lintasan *lintasan, *lintasan2, *lintasan3;
	wxTimer *timer;
	DECLARE_EVENT_TABLE()
};