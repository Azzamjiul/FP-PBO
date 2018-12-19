#pragma once
#include "wx\wx.h"
#include "wx/dcbuffer.h"

class Mobil
{
public:
	Mobil();
	Mobil(int x1, int y1);
	~Mobil();

	void Draw(wxBufferedPaintDC &event);
	int getX();
	int getY();
private:
	wxBitmap *mobil = nullptr;
	int x1, y1;
	void LoadMobil();
};

