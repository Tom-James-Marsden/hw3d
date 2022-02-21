#include "BumWin.h"
#include "BumException.h"
#include "Window.h"
#include <string>
#include <sstream>

int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR     lpCmdLine,
	int       nShowCmd)
{
	try
	{
		Window wnd(800, 300, "Donkey Fart Box");
		MSG msg;
		BOOL gResult;
		while ((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0)
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			while (!wnd.mouse.IsEmpty())
			{
				const auto e = wnd.mouse.Read();
				switch (e.GetType())
				{
				case Mouse::Event::Type::Leave:
					wnd.SetTitle("Gone!");
					break;
				case Mouse::Event::Type::Move:
				{
					std::ostringstream oss;
					oss << "Mouse Cringe moved to (" << e.GetPosX() << "," << e.GetPosY() << ")" << wnd.mouse.IsInWindow() << "IDKKKK";
					wnd.SetTitle(oss.str());
				}
				break;
				}
			}
		}

		if (gResult == -1)
		{
			return -1;
		}
		return msg.wParam;


	}
	catch (const BumException& e)
	{
		MessageBox(nullptr, e.what(), e.GetType(), MB_OK | MB_ICONEXCLAMATION);
	}
	catch (const std::exception& e)
	{
		MessageBox(nullptr, e.what(), "Standard Exception", MB_OK | MB_ICONEXCLAMATION);
	}
	catch (...)
	{
		MessageBox(nullptr, "No Details Available", "Unkowm Exception", MB_OK | MB_ICONEXCLAMATION);
	}
	return -1;
}

