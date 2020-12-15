#include <stdio.h>
#include "../Zlibx/ZWindow.h"
#include "../Zlibx/ZLabel.h"

//#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )

int main()
{
	ZWindow* win = new ZWindow(L"Hello", 50, 50, 300, 200, WindowType::Sizable);
	win->Create();

	ZLabel* l1 = new ZLabel(L"Hello", 5, 5, 100, 21);
	win->AddControl(l1);

	win->Run();
	return 0;
}