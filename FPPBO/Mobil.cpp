#include "Mobil.h"
#include <wx/stdpaths.h>
#include <wx/filename.h>

Mobil::Mobil(int x1, int y1)
{
}

Mobil::~Mobil()
{
	delete mobil;
}

void Mobil::Draw(wxBufferedPaintDC & event)
{
	if (mobil != nullptr)
	{
		event.DrawBitmap(*mobil, wxPoint(x, y), true);
	}
}

void Mobil::Move(int dx, int dy)
{
	this->x += dx;
	this->y += dy;
}

int Mobil::getX()
{
	return this->x;
}

int Mobil::getY()
{
	return this->y;
}

void Mobil::change(int x, int y)
{
	this->x = x;
	this->y = y;
}
