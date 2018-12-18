#include "Lintasan.h"
#include <wx/stdpaths.h>
#include <wx/filename.h>


Lintasan::Lintasan()
{
	//load JPEGHandler untuk membaca file JPEG.
	wxImageHandler *pngLoader = new wxPNGHandler();
	wxImage::AddHandler(pngLoader);
	//load image
	this->LoadLintasan();
}

Lintasan::Lintasan(int x1, int y1)
{
	this->x1 = x1;
	this->y1 = y1;

	//load JPEGHandler untuk membaca file JPEG.
	wxImageHandler *pngLoader = new wxPNGHandler();
	wxImage::AddHandler(pngLoader);
	//load image
	this->LoadLintasan();
}


Lintasan::~Lintasan()
{
	delete lintasan;
}

void Lintasan::Draw(wxPaintDC & event)
{
	if (lintasan != nullptr)
	{
		event.DrawBitmap(*lintasan, wxPoint(x1, y1), true);
	}
}

void Lintasan::Move(int dx, int dy)
{
	this->x1 += dx;
	this->y1 += dy;
}

int Lintasan::getX()
{
	return this->x1;
}

int Lintasan::getY()
{
	return this->y1;
}

void Lintasan::LoadLintasan()
{
	//jika menggunakan relative path
	//letakkan file potato.jpg pada folder Debug
	wxStandardPaths &stdPaths = wxStandardPaths::Get();
	wxString fileLocation = stdPaths.GetExecutablePath();
	fileLocation = wxFileName(fileLocation).GetPath() +
		wxT("\\road.png");
	wxMessageOutputDebug().Printf("Relative path of image is at %s",fileLocation);
	wxImage image(fileLocation, wxBITMAP_TYPE_PNG);

	lintasan = new wxBitmap(image);
}
