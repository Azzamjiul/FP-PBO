#include "Pemain.h"
#include <wx/stdpaths.h>
#include <wx/filename.h>



Pemain::Pemain(int x, int y) : Mobil(x, y)
{
	this->x = x;
	this->y = y;
	this->x1 = this->x + 100;
	this->x2 = this->x;
	this->x3 = this->x + 100;
	this->y1 = this->y;
	this->y2 = this->y + 100;
	this->y3 = this->y + 100;
	this->score = 0;
	this->isNubruk = false;

	//load JPEGHandler untuk membaca file JPEG.
	wxImageHandler *jpegLoader = new wxPNGHandler();
	wxImage::AddHandler(jpegLoader);
	//load image
	this->LoadMobil();
}

Pemain::~Pemain()
{
}

void Pemain::LoadMobil()
{
	//jika menggunakan relative path
	//letakkan file potato.jpg pada folder Debug
	wxStandardPaths &stdPaths = wxStandardPaths::Get();
	wxString fileLocation = stdPaths.GetExecutablePath();
	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\mobil.png");
	wxMessageOutputDebug().Printf("Relative path of image is at %s", fileLocation);
	wxImage image(fileLocation, wxBITMAP_TYPE_PNG);
	image.Rescale(50, 100, wxIMAGE_QUALITY_NORMAL);
	mobil = new wxBitmap(image);
}

void Pemain::Tubrukan()
{
	this->isNubruk = true;
}

void Pemain::UpScore()
{
	this->score += 1;
}
