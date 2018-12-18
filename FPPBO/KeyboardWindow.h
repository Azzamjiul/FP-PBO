#pragma once
#include "wx\wx.h"
#include "KeyboardFrame.h"

class KeyboardWindow : public wxWindow
{
public:
	KeyboardWindow(KeyboardFrame *parent);
	void OnKeyDown(wxKeyEvent &event);
	void OnKeyUp(wxKeyEvent &event);
	void OnChar(wxKeyEvent &event);
private:
	int caretX = 10;
	int caretY = 10;
	int lineCharacterCount = 0;
	DECLARE_EVENT_TABLE()
};