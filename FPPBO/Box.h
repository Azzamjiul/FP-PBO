#pragma once
#include <wx\dcclient.h>
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
	void Draw(wxPaintDC &dc);
	void Move(int xAmount, int yAmount, int maxX, int maxY);
};