#pragma once
#include "wx\wx.h"
#include "Mobil.h"
#include "Lintasan.h"
#include "Pemain.h"
#include "Musuh.h"

class Mobil;
class Pemain;
class Musuh;
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
	void Tubrukan();
	long long int highscore;
private:
	Pemain *player;
	Musuh *musuh1, *musuh2, *musuh3, *musuh4;
	Lintasan *lintasan, *lintasan2, *lintasan3;
	wxTimer *timer;
	DECLARE_EVENT_TABLE()
};