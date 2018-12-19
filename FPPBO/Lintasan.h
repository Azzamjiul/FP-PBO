#pragma once
#include "wx\wx.h"
#include "wx/dcbuffer.h"

class Lintasan
{
public:
	Lintasan();
	Lintasan(int x1, int y1);
	~Lintasan();

	//void Draw(wxPaintDC &event);
	void Draw(wxBufferedPaintDC &event);
	void Move(int dx, int dy);
	int getX();
	int getY();
private:
	wxBitmap *lintasan = nullptr;
	int x1, y1, x0, y0;
	void LoadLintasan();
};

