#include "MainFrame.h"
#include "HomeWindow.h"
#include "GameWindow.h"

void MainFrame::fitWindowSize()
{
	this->boxSizer->Fit(this);
	this->boxSizer->SetSizeHints(this);
	this->SetSize(wxSize(640, 480));
	this->Layout();
}

MainFrame::MainFrame(const wxString & title)
	: wxFrame(NULL, wxID_ANY, title)
{
	this->InitComponents();
}

void MainFrame::InitComponents()
{
	boxSizer = new wxBoxSizer(wxVERTICAL);

	this->homeWindow = new HomeWindow(this);
	this->homeWindow->Show(false);
	this->boxSizer->Add(homeWindow, 1, wxEXPAND, 0);

	this->gameWindow = new GameWindow(this);
	this->gameWindow->Show(false);
	this->boxSizer->Add(gameWindow, 1, wxEXPAND, 0);

	SetSizer(boxSizer);

	//tambahan jiul
	XMainFrame = this->GetSize().GetX();
	YMainFrame = this->GetSize().GetY();
	//this->SetInitialSize(wxSize(1000, 500));

	ShowHomeWindow();
}

void MainFrame::ShowHomeWindow()
{
	this->homeWindow->Show(true);
	this->gameWindow->Show(false);
	fitWindowSize();
}

void MainFrame::ShowGameWindow()
{
	this->homeWindow->Show(false);
	this->gameWindow->Show(true);
	fitWindowSize();
}
