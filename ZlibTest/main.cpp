#include <stdio.h>
#include "../Zlibx/ZWindow.h"
#include "../Zlibx/ZLabel.h"

#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )

int main()
{
	ZWindow* win = new ZWindow(L"Hello");
	win->Create();
	win->SetSize(ZSize(400, 300));

	ZLabel* l1 = new ZLabel(L"Hello", 5, 5, 60, 25);
	win->AddControl(l1);

	win->Run();
	return 0;
}