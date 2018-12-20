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
	
	player = new Pemain(552, 675);
	lintasan = new Lintasan(424,0);
	lintasan2 = new Lintasan(424, 512);
	lintasan3 = new Lintasan(424, -512);
	int xrand = rand() % 450 + lintasan->getX();
	musuh1 = new Musuh(xrand, 0);
	xrand = rand() % 430 + lintasan->getX();
	musuh2 = new Musuh(xrand, 0);
	xrand = rand() % 410 + lintasan->getX();
	musuh3 = new Musuh(xrand, 0);
	xrand = rand() % 400 + lintasan->getX();
	musuh4 = new Musuh(xrand, 0);
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
	player->Draw(pdc);
	musuh1->Draw(pdc);
	musuh2->Draw(pdc);
	musuh3->Draw(pdc);
	musuh4->Draw(pdc);
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

	//musuh1
	musuh1->Move(0, 40);
	musuh2->Move(0, 40);
	musuh3->Move(0, 40);
	musuh4->Move(0, 40);

	//tubrukan1
	if (player->getX() >= musuh1->getX() 
		&& player->getX() <= musuh1->getX() + 50
		&& player->getY() >= musuh1->getY() 
		&& player->getY() <= musuh1->getY() + 150
		) {
		wxMessageBox(wxT("Mobil Menubruk. 1 kanan"), wxT("Keyboard event"), wxOK | wxICON_INFORMATION, this);
	}

	if (player->getX() <= musuh1->getX()
		&& player->getX() + 50 >= musuh1->getX()
		&& player->getY() >= musuh1->getY()
		&& player->getY() <= musuh1->getY() + 150
		) {
		wxMessageBox(wxT("Mobil Menubruk 1 kiri."), wxT("Keyboard event"), wxOK | wxICON_INFORMATION, this);
	}

	//tubrukan2
	if (player->getX() >= musuh2->getX()
		&& player->getX() <= musuh2->getX() + 50
		&& player->getY() >= musuh2->getY()
		&& player->getY() <= musuh2->getY() + 150
		) {
		wxMessageBox(wxT("Mobil Menubruk. 2 kanan"), wxT("Keyboard event"), wxOK | wxICON_INFORMATION, this);
	}

	if (player->getX() <= musuh2->getX()
		&& player->getX() + 50 >= musuh2->getX()
		&& player->getY() >= musuh2->getY()
		&& player->getY() <= musuh2->getY() + 150
		) {
		wxMessageBox(wxT("Mobil Menubruk. 2 kiri"), wxT("Keyboard event"), wxOK | wxICON_INFORMATION, this);
	}

	//tubrukan3
	if (player->getX() >= musuh3->getX()
		&& player->getX() <= musuh3->getX() + 50
		&& player->getY() >= musuh3->getY()
		&& player->getY() <= musuh3->getY() + 150
		) {
		wxMessageBox(wxT("Mobil Menubruk. 3 kanan"), wxT("Keyboard event"), wxOK | wxICON_INFORMATION, this);
	}

	if (player->getX() <= musuh3->getX()
		&& player->getX() + 50 >= musuh3->getX()
		&& player->getY() >= musuh3->getY()
		&& player->getY() <= musuh3->getY() + 150
		) {
		wxMessageBox(wxT("Mobil Menubruk. 3 kiri"), wxT("Keyboard event"), wxOK | wxICON_INFORMATION, this);
	}

	//tubrukan4
	if (player->getX() >= musuh4->getX()
		&& player->getX() <= musuh4->getX() + 50
		&& player->getY() >= musuh4->getY()
		&& player->getY() <= musuh4->getY() + 150
		) {
		wxMessageBox(wxT("Mobil Menubruk 4 kanan."), wxT("Keyboard event"), wxOK | wxICON_INFORMATION, this);
	}

	if (player->getX() <= musuh4->getX()
		&& player->getX() + 50 >= musuh4->getX()
		&& player->getY() >= musuh4->getY()
		&& player->getY() <= musuh4->getY() + 150
		) {
		wxMessageBox(wxT("Mobil Menubruk 4 kiri"), wxT("Keyboard event"), wxOK | wxICON_INFORMATION, this);
	}


	//ulang musuh
	int xrand = rand() % 450 + lintasan->getX();
	if (musuh1->getY() > GetClientSize().GetHeight()) { musuh1->change(xrand, 0); }
	xrand += rand() % 70;
	if (musuh2->getY() > GetClientSize().GetHeight()) { musuh2->change(xrand, 0); }
	xrand += rand() % 70;
	if (musuh3->getY() > GetClientSize().GetHeight()) { musuh3->change(xrand, 0); }
	xrand += rand() % 70;
	if (musuh4->getY() > GetClientSize().GetHeight()) { musuh4->change(xrand, 0); }

	//tubrukan
	if (player->getX() >= musuh1->getX() &&
		player->getX() <= musuh1->getX() + 50 && 
		player->getY() >= musuh1->getY() && 
		player->getY() <= musuh1->getY() + 150) {
		wxMessageBox(wxT("Mobil Menubruk."), wxT("Keyboard event"), wxOK | wxICON_INFORMATION, this);

	}

	Refresh();
}

void GameWindow::OnKeyDown(wxKeyEvent & event)
{
	wxMessageOutputDebug().Printf("Key down event fired. Keycode=%d.",event.GetKeyCode());

	if (event.GetKeyCode() == WXK_UP)
	{
		//wxMessageBox(wxT("Key up is pressed."), wxT("Keyboard event"),	wxOK | wxICON_INFORMATION, this);
		if (player->getY() > 0) {
			player->Move(0, -20);
		}
	}
	else if (event.GetKeyCode() == WXK_RIGHT)
	{
		//wxMessageBox(wxT("Key right is pressed."), wxT("Keyboard event"),wxOK | wxICON_INFORMATION, this);
		if (player->getX() < lintasan->getX() + 512 - 70) {
			player->Move(20,0);
		}
		
	}
	else if (event.GetKeyCode() == WXK_DOWN)
	{
		//wxMessageBox(wxT("Key down is pressed."), wxT("Keyboard event"), wxOK | wxICON_INFORMATION, this);
		if (player->getY() + 100 < 768) {
			player->Move(0, 20);
		}
		
	}
	else if (event.GetKeyCode() == WXK_LEFT)
	{
		//wxMessageBox(wxT("Key left is pressed."), wxT("Keyboard event"), wxOK | wxICON_INFORMATION, this);
		if (player->getX() > 434) {
			player->Move(-20, 0);
		}
		
	}
}

void GameWindow::OnKeyUp(wxKeyEvent & event)
{
	wxMessageOutputDebug().Printf("Key up event fired. Keycode=%d.",event.GetKeyCode());
}
