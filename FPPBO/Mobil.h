#pragma once
#include "wx\wx.h"

class Mobil
{
public:
	Mobil();
	Mobil(int x1, int y1);
	~Mobil();

	void Draw(wxPaintDC &event);
	void Move(int dx, int dy); 
private:
	wxBitmap *mobil = nullptr;
	int x1, x2, y1, y2;
	void LoadMobil();
};

