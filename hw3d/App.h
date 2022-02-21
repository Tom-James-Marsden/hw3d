#pragma once
#include "Window.h"
#include "BumTimer.h"
class App
{
public:
	App();
	//master frame/message loop
	int Go();
private:
	void DoFrame();
private:
	Window wnd;
	BumTimer timer;
};

