#include "App.h"

App::App()
	:
	wnd(800,600,"Donkey Fart Box")
{}

int App::Go()
{
	while (true)
	{
		if (const auto ecode = Window::ProcessMessages())
		{
			return *ecode;
		}
		while (!wnd.kbd.KeyIsEmpty())
		{
			if (wnd.kbd.ReadKey().GetCode() == VK_ESCAPE)
			{
				PostQuitMessage(0);
			}
		}

		DoFrame();
		Sleep(1000.0f/90.0f);
	}
}

void App::DoFrame()
{
	const float c = sin(timer.Peek()) / 2.0f + 0.5f;
	wnd.Gfx().ClearBuffer(c, c, 1.0f);
	//wnd.Gfx().DrawTestTriangle(
	//	-timer.Peek(),
	//	0,
	//	0
	//);
	wnd.Gfx().DrawTestTriangle(
		timer.Peek(),
		wnd.mouse.GetPosX()/400.0f -1.0f,
		-wnd.mouse.GetPosY()/300.0f + 1
	);
	wnd.Gfx().EndFrame();
}