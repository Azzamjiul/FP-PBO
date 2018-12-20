#include "HomeWindow.h"
#include <wx/stdpaths.h>
#include <wx/filename.h>

BEGIN_EVENT_TABLE(HomeWindow, wxWindow)
	EVT_BUTTON(1001, HomeWindow::OnStartButtonClick)
	EVT_PAINT(HomeWindow::OnPaint)
END_EVENT_TABLE()

HomeWindow::HomeWindow(MainFrame * parent)
	: wxWindow(parent, wxID_ANY), mainFrame(parent)
{
	this->SetBackgroundColour(wxColour(*wxWHITE));

	//menambahkan button
	wxButton* StartButton = new wxButton(this, 1001, wxT("Start!"), wxPoint(100, 100), wxDefaultSize);

	//load JPEGHandler untuk membaca file JPEG.
	wxImageHandler *jpegLoader = new wxJPEGHandler();
	wxImage::AddHandler(jpegLoader);

	//load image
	this->LoadHomeBitmap();
}

HomeWindow::~HomeWindow()
{
	delete HomeBitmap;
}

void HomeWindow::OnStartButtonClick(wxCommandEvent & event)
{
	mainFrame->ShowGameWindow();
}

void HomeWindow::OnPaint(wxPaintEvent & event)
{
	wxBufferedPaintDC pdc(this);

	if (HomeBitmap != nullptr)
	{
		pdc.DrawBitmap(*HomeBitmap, wxPoint(0, 0), true);
	}
}

void HomeWindow::LoadHomeBitmap()
{
	//jika menggunakan relative path
	//letakkan file potato.jpg pada folder Debug
	wxStandardPaths &stdPaths = wxStandardPaths::Get();
	wxString fileLocation = stdPaths.GetExecutablePath();
	fileLocation = wxFileName(fileLocation).GetPath() +	wxT("\\asset\\MainMenu.jpg");
	wxMessageOutputDebug().Printf("Relative path of image is at %s",fileLocation);
	wxImage image(fileLocation, wxBITMAP_TYPE_JPEG);
	
	HomeBitmap = new wxBitmap(image);
}
