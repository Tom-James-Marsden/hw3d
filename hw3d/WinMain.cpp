#include "BumWin.h"
#include "BumException.h"
#include "App.h"
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
		return App{}.Go();
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

