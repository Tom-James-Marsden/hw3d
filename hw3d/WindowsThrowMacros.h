#pragma once

#define BMWND_EXCEPT(hr) Window::HrException(__LINE__, __FILE__, (hr))
#define BMWND_LAST_EXCEPT() Window::HrException(__LINE__, __FILE__, GetLastError())
#define BMWND_NOGFX_EXCEPT() Window::NoGfxException(__LINE__,__FILE__)