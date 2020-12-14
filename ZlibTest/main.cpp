#include <stdio.h>
#include "../Zlibx/ZWindow.h"

//#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )

int main()
{
	ZWindow* win = new ZWindow(L"Hello", 300, 300, 600, 400);
	win->Create();
	win->Run();
	return 0;
}