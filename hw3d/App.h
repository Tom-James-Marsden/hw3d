#pragma once
#include "Window.h"
#include "BumTimer.h"
class App
{
public:
	App();
	//master frame/message loop
	int Go();
	~App();
private:
	void DoFrame();
private:
	Window wnd;
	BumTimer timer;
	std::vector<std::unique_ptr<class Drawable>> drawables;
	static constexpr size_t nDrawables = 180;
};

