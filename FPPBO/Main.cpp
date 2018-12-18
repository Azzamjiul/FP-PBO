#include "wx\wx.h"
#include "MainFrame.h"
#include "TimerFrame.h"

class MyApp : public wxApp
{
public:
	virtual bool OnInit();
};

IMPLEMENT_APP(MyApp)
DECLARE_APP(MyApp)

bool MyApp::OnInit()
{
	/*MainFrame *frame = new MainFrame("2D Car Racing Game");
	frame->Show(true);
	return true;
	*/
	TimerFrame *frame = new TimerFrame("Timer App");
	frame->Show();
	return true;
}