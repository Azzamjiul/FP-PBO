#pragma once
#include "wx/wx.h"
#include "MainFrame.h"
#include "wx/dcbuffer.h"

class HomeWindow : public wxWindow
{
public:
	HomeWindow(MainFrame *parent);
	~HomeWindow();

	void OnStartButtonClick(wxCommandEvent& event);
	void OnPaint(wxPaintEvent &event);

private:
	wxBitmap *HomeBitmap = nullptr;
	MainFrame *mainFrame;
	DECLARE_EVENT_TABLE()
	void LoadHomeBitmap();
};