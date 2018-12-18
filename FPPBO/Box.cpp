#include "Box.h"
Box::Box()
{
}
Box::Box(int x, int y, int width, int height)
	: x(x), y(y), width(width), height(height)
{
}
void Box::Draw(wxPaintDC &dc)
{
	dc.SetBrush(wxBrush(wxColour(*wxRED)));
	dc.SetPen(wxPen(wxColor(*wxGREEN), 1, wxPENSTYLE_SOLID));
	dc.DrawRectangle(wxPoint(this->x, this->y), wxSize(this->width,this->height));
}

void Box::Move(int xAmount, int yAmount, int maxX, int maxY)
{
	if (x + width >= maxX || x <= 0) {
		xDirection *= -1;
	}

	this->x += xDirection * xAmount;

	if (y + height >= maxY || y <= 0) {
		yDirection *= -1;
	}

	this->y += yDirection * yAmount;
}