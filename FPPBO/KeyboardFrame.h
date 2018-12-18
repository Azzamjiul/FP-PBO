#pragma once
#include "wx\wx.h"

class KeyboardWindow;

class KeyboardFrame : public wxFrame
{
private:
	KeyboardWindow *window;
	void InitComponents();
public:
	KeyboardFrame(const wxString &title);
};