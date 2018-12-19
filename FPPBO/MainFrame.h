#pragma once
#include "wx/wx.h"

class HomeWindow;
class GameWindow;

class Window;


class MainFrame : public wxFrame {
private:
	wxBoxSizer* boxSizer;

	//window awal
	HomeWindow* homeWindow;

	//window untuk bermain
	GameWindow* gameWindow;
	void fitWindowSize();

	//sulton
	Window* window;

public:
	//MainFrame(const wxString &title);
	void InitComponents();
	void ShowHomeWindow();
	void ShowGameWindow();

	//x dan y main frame
	int XMainFrame;
	int YMainFrame;

	//sulton
	MainFrame(const wxString &title);
};


