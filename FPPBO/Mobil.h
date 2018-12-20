#pragma once
#include "wx\wx.h"
#include "wx/dcbuffer.h"

class Mobil
{
public:
	Mobil(int x, int y);
	~Mobil();
	int x, y, x1, y1, x2, y2, x3, y3;
	virtual void Draw(wxBufferedPaintDC &event);
	virtual void Move(int dx, int dy);
	virtual void LoadMobil() = 0;
	virtual int getX();
	virtual int getY();
	virtual void change(int x, int y);
	wxBitmap *mobil = nullptr;
};

