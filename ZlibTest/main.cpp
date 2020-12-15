#include <stdio.h>
#include "../Zlibx/ZWindow.h"
#include "../Zlibx/ZLabel.h"
#include "../Zlibx/ZButton.h"

#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )

ZWindow* win;
ZLabel* l1;
ZButton* b1;

LRESULT b1_clicked(Param param)
{
	l1->SetText(L"WDNMD");
	return 0;
}

int main()
{
	win = new ZWindow(L"Hello", 50, 50, 300, 200, WindowType::Sizable);
	win->Create();

	l1 = new ZLabel(L"Hello", 5, 5, 100, 21);
	win->AddControl(l1);

	b1 = new ZButton(L"Click me", 5, 30, 90, 50);
	b1->Bind(MessageType::Clicked, b1_clicked);
	win->AddControl(b1);

	win->Run();
	return 0;
}