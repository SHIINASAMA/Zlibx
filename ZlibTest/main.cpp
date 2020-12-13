#include <stdio.h>
#include "../Zlibx/ZWindow.h"
#include "../Zlibx/ZLabel.h"
#include "../Zlibx/ZButton.h"
#include "../Zlibx/ZTextBox.h"

//#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )

void ClickerBtn1(WPARAM p1, LPARAM p2)
{
	printf("You clicked me\n");
}

int main()
{
	ZWindow* win = new ZWindow(L"Hello", 300, 300, 600, 400);
	win->Create();

	ZButton* b1 = new ZButton(L"Hello", 5, 5, 60, 25, ClickerBtn1);
	win->AddControl(b1);

	ZTextBox* t1 = new ZTextBox(5, 35, 600, 56);
	win->AddControl(t1);

	win->Run();
	return 0;
}