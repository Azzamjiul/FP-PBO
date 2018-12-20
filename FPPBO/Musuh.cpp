#include "Musuh.h"
#include <wx/stdpaths.h>
#include <wx/filename.h>



Musuh::Musuh(int x, int y) : Mobil(x,y)
{
	this->x = x;
	this->y = y;

	//load JPEGHandler untuk membaca file JPEG.
	wxImageHandler *jpegLoader = new wxPNGHandler();
	wxImage::AddHandler(jpegLoader);
	//load image
	this->LoadMobil();
}


Musuh::~Musuh()
{
}

void Musuh::LoadMobil()
{
	//jika menggunakan relative path
	//letakkan file potato.jpg pada folder Debug
	wxStandardPaths &stdPaths = wxStandardPaths::Get();
	wxString fileLocation = stdPaths.GetExecutablePath();
	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\musuh.png");
	wxMessageOutputDebug().Printf("Relative path of image is at %s", fileLocation);
	wxImage image(fileLocation, wxBITMAP_TYPE_PNG);
	image.Rescale(50, 100, wxIMAGE_QUALITY_NORMAL);
	mobil = new wxBitmap(image);
}