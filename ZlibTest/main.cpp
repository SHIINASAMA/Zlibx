#include <stdio.h>
#include "../Zlibx/ZWindow.h"
#include "../Zlibx/ZLabel.h"
#include "../Zlibx/ZButton.h"

//#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )

void ClickerBtn1(WPARAM p1, LPARAM p2)
{
	printf("You clicked me\n");
}

int main()
{
	ZWindow* win = new ZWindow(L"Hello");
	win->Create();
	win->SetSize(ZSize(400, 300));

	/*ZLabel* l1 = new ZLabel(L"Hello", 5, 5, 60, 25);
	win->AddControl(l1);*/

	ZButton* b1 = new ZButton(L"Hello", 5, 5, 60, 25, ClickerBtn1);
	win->AddControl(b1);
	win->RemoveControl(b1->GetHandle());

	win->Run();
	return 0;
}