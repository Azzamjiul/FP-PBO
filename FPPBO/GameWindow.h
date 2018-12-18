#pragma once
#include "wx/wx.h"

class GameWindow : public wxWindow
{
public:
	GameWindow(wxFrame *gameWindow);
	~GameWindow();
	void OnPaint(wxPaintEvent &event);

private:
	wxBitmap *GameBitmap = nullptr;
	DECLARE_EVENT_TABLE()
	void LoadGameBitmap();
};

