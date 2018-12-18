#include "KeyboardFrame.h"
#include "KeyboardWindow.h"

KeyboardFrame::KeyboardFrame(const wxString &title)
	: wxFrame(NULL, wxID_ANY, title)
{
	this->InitComponents();
}

void KeyboardFrame::InitComponents()
{
	this->window = new KeyboardWindow(this);
	this->SetInitialSize(wxSize(640, 480));
}