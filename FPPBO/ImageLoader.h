#pragma once
#include "wx/wx.h"
#include "wx/dcbuffer.h"
class ImageLoader
{
public:
	ImageLoader();
	~ImageLoader();
	virtual void Draw(wxBufferedPaintDC &pdc);
	virtual void Load() = 0;
};