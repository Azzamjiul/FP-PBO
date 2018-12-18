#include "GameWindow.h"
#include <wx/stdpaths.h>
#include <wx/filename.h>

BEGIN_EVENT_TABLE(GameWindow, wxWindow)
	EVT_PAINT(GameWindow::OnPaint)
END_EVENT_TABLE()


GameWindow::GameWindow(wxFrame * gameWindow)
	:wxWindow(gameWindow, wxID_ANY)
{
	this->SetBackgroundColour(wxColour(*wxWHITE));

	//load JPEGHandler untuk membaca file JPEG.
	wxImageHandler *jpegLoader = new wxJPEGHandler();
	wxImage::AddHandler(jpegLoader);

	//load image
	this->LoadGameBitmap();
}

GameWindow::~GameWindow()
{
	delete GameBitmap;
}

void GameWindow::OnPaint(wxPaintEvent & event)
{
	wxPaintDC pdc(this);

	if (GameBitmap != nullptr)
	{
		pdc.DrawBitmap(*GameBitmap, wxPoint(150, 100), true);
	}
}

void GameWindow::LoadGameBitmap()
{
	//jika menggunakan relative path
	//letakkan file potato.jpg pada folder Debug
	wxStandardPaths &stdPaths = wxStandardPaths::Get();
	wxString fileLocation = stdPaths.GetExecutablePath();
	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\main_menu.jpg");
	wxMessageOutputDebug().Printf("Relative path of image is at %s", fileLocation);
	wxImage image(fileLocation, wxBITMAP_TYPE_JPEG);

	GameBitmap = new wxBitmap(image);
}
