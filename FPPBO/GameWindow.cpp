#include "GameWindow.h"
#include <wx/stdpaths.h>
#include <wx/filename.h>
#include "wx/dcbuffer.h"

BEGIN_EVENT_TABLE(GameWindow, wxWindow)
	EVT_PAINT(GameWindow::OnPaint)
	EVT_TIMER(1000, GameWindow::OnTimer)
	EVT_KEY_DOWN(GameWindow::OnKeyDown)
	EVT_KEY_UP(GameWindow::OnKeyUp)
END_EVENT_TABLE()

GameWindow::GameWindow(wxWindow *parent)
	: wxWindow(parent, wxID_ANY)
{
	this->SetBackgroundColour(wxColour(*wxWHITE));
	timer = new wxTimer(this, 1000);
	timer->Start(50);
	
	mobil = new Mobil(552, 510);
	musuh1 = new Mobil(rand(), -20);
	lintasan = new Lintasan(424,0);
	lintasan2 = new Lintasan(424, 512);
	lintasan3 = new Lintasan(424, -512);

}

GameWindow::~GameWindow()
{
	timer->Stop();
	delete timer;
}

/*
void GameWindow::loadCar1()
{
	Car1 = nullptr;
	//jika menggunakan relative path
	//letakkan file potato.jpg pada folder Debug
	wxStandardPaths &stdPaths = wxStandardPaths::Get();
	wxString fileLocation = stdPaths.GetExecutablePath();
	fileLocation = wxFileName(fileLocation).GetPath() +	wxT("\\Car1.png");
	wxMessageOutputDebug().Printf("Relative path of image is at %s",fileLocation);
	wxImage image(fileLocation, wxBITMAP_TYPE_PNG);
	Car1 = new wxBitmap(image);
}

void GameWindow::loadRoad()
{
	Road = nullptr;
	//jika menggunakan relative path
	//letakkan file potato.jpg pada folder Debug
	wxStandardPaths &stdPaths = wxStandardPaths::Get();
	wxString fileLocation = stdPaths.GetExecutablePath();
	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\road.png");
	wxMessageOutputDebug().Printf("Relative path of image is at %s", fileLocation);
	wxImage image(fileLocation, wxBITMAP_TYPE_PNG);
	Road = new wxBitmap(image);
}
*/

void GameWindow::OnPaint(wxPaintEvent &event)
{
	wxBufferedPaintDC pdc(this); //template
	lintasan3->Draw(pdc);
	lintasan->Draw(pdc);
	lintasan2->Draw(pdc);
	mobil->Draw(pdc);
	musuh1->Draw(pdc);
}

void GameWindow::OnTimer(wxTimerEvent & event)
{
	double static time;
	wxMessageOutputDebug().Printf("program ini berjalan selama %f", time++);

	//lintasan
	lintasan3->Move(0, 10);
	lintasan->Move(0, 10);
	lintasan2->Move(0, 10);
	if (lintasan3->getY() > GetClientSize().GetHeight()) {lintasan3->Move(0,-1536);}
	if (lintasan->getY() > GetClientSize().GetHeight())  {lintasan->Move(0,-1536);}
	if (lintasan2->getY() > GetClientSize().GetHeight()) {lintasan2->Move(0,-1536);}

	//musuh
	musuh1->Move(0, 30);
	if (musuh1->getY() > GetClientSize().GetHeight()) { musuh1->Move(0, -1536); }

	Refresh();

}

void GameWindow::OnKeyDown(wxKeyEvent & event)
{
	wxMessageOutputDebug().Printf("Key down event fired. Keycode=%d.",event.GetKeyCode());

	if (event.GetKeyCode() == WXK_UP)
	{
		//wxMessageBox(wxT("Key up is pressed."), wxT("Keyboard event"),	wxOK | wxICON_INFORMATION, this);
		if (mobil->getY() > 0) {
			mobil->Up();
		}
	}
	else if (event.GetKeyCode() == WXK_RIGHT)
	{
		//wxMessageBox(wxT("Key right is pressed."), wxT("Keyboard event"),wxOK | wxICON_INFORMATION, this);
		if (mobil->getX() < 424 + 350) {
			mobil->Right();
		}
		
	}
	else if (event.GetKeyCode() == WXK_DOWN)
	{
		//wxMessageBox(wxT("Key down is pressed."), wxT("Keyboard event"), wxOK | wxICON_INFORMATION, this);
		if (mobil->getY() + 300 < 768) {
			mobil->Bottom();
		}
		
	}
	else if (event.GetKeyCode() == WXK_LEFT)
	{
		//wxMessageBox(wxT("Key left is pressed."), wxT("Keyboard event"), wxOK | wxICON_INFORMATION, this);
		if (mobil->getX() > 434) {
			mobil->Left();
		}
		
	}
}

void GameWindow::OnKeyUp(wxKeyEvent & event)
{
	wxMessageOutputDebug().Printf("Key up event fired. Keycode=%d.",event.GetKeyCode());
}
