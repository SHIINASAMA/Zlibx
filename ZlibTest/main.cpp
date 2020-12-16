#include <stdio.h>
#include "../Zlibx/ZWindow.h"
#include "../Zlibx/ZLabel.h"
#include "../Zlibx/ZButton.h"
#include "../Zlibx/ZTextBox.h"
#include "../Zlibx/ZProgressBar.h"

#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )

ZWindow* win;
ZLabel* l1;
ZButton* b1;
ZProgressBar* pb1;

UINT v = 0;

LRESULT b1_clicked(Param param)
{
	pb1->SetValue(++v);
	WChar str[128];
	wsprintf(str, L"value:%d", v, sizeof(WChar) * 128);
	l1->SetText(str);
	return 0;
}

int main()
{
	win = new ZWindow(L"Hello", 50, 50, 300, 200, WindowType::Sizable);
	win->Create();

	pb1 = new ZProgressBar(5, 5, 300, 21);
	win->AddControl(pb1);

	l1 = new ZLabel(L"value:0", 5, 30, 80, 21);
	win->AddControl(l1);

	b1 = new ZButton(L"Ôö¼Ó", 5, 55, 90, 50);
	b1->Bind(MessageType::Clicked, b1_clicked);
	win->AddControl(b1);

	win->Run();
	return 0;
}