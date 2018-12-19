#include "Mobil.h"
#include <wx/stdpaths.h>
#include <wx/filename.h>

Mobil::Mobil()
{
	//load JPEGHandler untuk membaca file JPEG.
	wxImageHandler *pngLoader = new wxPNGHandler();
	wxImage::AddHandler(pngLoader);
	//load image
	this->LoadMobil();
}

Mobil::Mobil(int x1, int y1)
{
	this->x1 = x1;
	this->y1 = y1;

	//load JPEGHandler untuk membaca file JPEG.
	wxImageHandler *jpegLoader = new wxPNGHandler();
	wxImage::AddHandler(jpegLoader);
	//load image
	this->LoadMobil();
}


Mobil::~Mobil()
{
	delete mobil;
}

void Mobil::Draw(wxBufferedPaintDC & event)
{
	if (mobil != nullptr)
	{
		event.DrawBitmap(*mobil, wxPoint(x1, y1), true);
	}
}

int Mobil::getX()
{
	return this->x1;
}

int Mobil::getY()
{
	return this->y1;
}

void Mobil::LoadMobil()
{
	//jika menggunakan relative path
	//letakkan file potato.jpg pada folder Debug
	wxStandardPaths &stdPaths = wxStandardPaths::Get();
	wxString fileLocation = stdPaths.GetExecutablePath();
	fileLocation = wxFileName(fileLocation).GetPath() +	wxT("\\mobil.png");
	wxMessageOutputDebug().Printf("Relative path of image is at %s", fileLocation);
	wxImage image(fileLocation, wxBITMAP_TYPE_PNG);

	mobil = new wxBitmap(image);
}

