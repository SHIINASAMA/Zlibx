#include <stdio.h>
#include "../Zlibx/ZWindow.h"
#include "../Zlibx/ZLabel.h"

//#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )

int main()
{
	ZWindow* win = new ZWindow(L"Hello", 300, 300, 600, 400);
	win->Create();

	ZLabel* l1 = new ZLabel(L"Hello", 5, 5, 100, 21);
	win->AddControl(l1);

	l1->SetText(L"ţ");

	win->Run();
	return 0;
}