#include <stdio.h>
#include "../Zlibx/ZWindow.h"

#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )

int main()
{
	ZWindow* win = new ZWindow(L"Hello");
	win->Create();
	win->SetSize(ZSize(400, 300));
	win->Run();
	return 0;
}