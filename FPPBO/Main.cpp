#include "wx\wx.h"
#include <wx/stdpaths.h>
#include <wx/filename.h>
#include "MainFrame.h"


class MyApp : public wxApp
{
public:
	virtual bool OnInit();
};

IMPLEMENT_APP(MyApp)
DECLARE_APP(MyApp)

bool MyApp::OnInit()
{
	MainFrame *frame = new MainFrame("2D Car Racing Game");
	frame->Show();
	return true;
}