#include "wx\wx.h"
#include "MainFrame.h"
#include "TimerFrame.h"
#include "KeyboardFrame.h"

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
	//merFrame *frame = new TimerFrame("Timer App");
	//yboardFrame *frame = new KeyboardFrame("Keyboard Event Handling");

	frame->Show();
	return true;
}