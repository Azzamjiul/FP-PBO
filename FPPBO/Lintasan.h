#pragma once
#include "wx\wx.h"

class Lintasan
{
public:
	Lintasan();
	Lintasan(int x1, int y1);
	~Lintasan();

	void Draw(wxPaintDC &event);
	void Move(int dx, int dy);
	int getX();
	int getY();
private:
	wxBitmap *lintasan = nullptr;
	int x1, y1;
	void LoadLintasan();
};

