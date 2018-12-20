#pragma once
#include <wx\dcclient.h>
#include "wx/dcbuffer.h"
class Box
{
private:
	int x;
	int y;
	int width;
	int height;
	int xDirection = 1;
	int yDirection = 1;
public:
	Box();
	Box(int x, int y, int width, int height);
	void Draw(wxBufferedPaintDC &dc);
	void Move(int xAmount, int yAmount, int maxX, int maxY);
};