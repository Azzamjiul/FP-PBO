#include "KeyboardWindow.h"
#include "KeyboardFrame.h"

BEGIN_EVENT_TABLE(KeyboardWindow, wxWindow)
EVT_KEY_DOWN(KeyboardWindow::OnKeyDown)
EVT_KEY_UP(KeyboardWindow::OnKeyUp)
EVT_CHAR(KeyboardWindow::OnChar)
END_EVENT_TABLE()

KeyboardWindow::KeyboardWindow(KeyboardFrame *parent)
	: wxWindow(parent, wxID_ANY)
{
	this->SetBackgroundColour(wxColour(*wxWHITE));
}

void KeyboardWindow::OnKeyDown(wxKeyEvent &event)
{
	wxMessageOutputDebug().Printf("Key down event fired. Keycode=%d.", event.GetKeyCode());
	if (event.GetKeyCode() == WXK_UP)
	{
		wxMessageBox(wxT("Key up is pressed."), wxT("Keyboard event"),	wxOK | wxICON_INFORMATION, this);
	}
	else if (event.GetKeyCode() == WXK_RIGHT)
	{
		wxMessageBox(wxT("Key right is pressed."), wxT("Keyboard event"),wxOK | wxICON_INFORMATION, this);
	}
	//untuk meneruskan event ke EVT_CHAR
	event.Skip();
}

void KeyboardWindow::OnKeyUp(wxKeyEvent &event)
{
	wxMessageOutputDebug().Printf("Key up event fired. Keycode=%d.", event.GetKeyCode());
}

void KeyboardWindow::OnChar(wxKeyEvent &event)
{
	wxMessageOutputDebug().Printf("Char event fired. Keycode=%d.", event.GetKeyCode());
	wxClientDC dc(this);
	dc.DrawText(wxString::FromAscii(event.GetKeyCode()), wxPoint(caretX,
		caretY));
	caretX += 10;
	lineCharacterCount++;
	if (lineCharacterCount == 55) { //55 karakter tiap baris
		lineCharacterCount = 0;
		caretY += 20; //ganti baris
		caretX = 10; //pindah ke paling kiri
	}
}