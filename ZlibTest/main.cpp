#include "../Zlibx/ZWindow.h"
#include "../Zlibx/ZLabel.h"
#include "../Zlibx/ZButton.h"
#include "../Zlibx/ZTextBox.h"

ZWindow* win;

void btn_clicked(WPARAM wParam, LPARAM lParam)
{
}

int main()
{
	win = new ZWindow(L"Hello", NULL, NULL, 400, 300);
	win->Create();
	win->ShowCenter();

	ZButton* b1 = new ZButton(L"Hello", 5, 35, 100, 50);
	b1->Bind(btn_clicked);
	//b1->SetEnable(FALSE);
	win->Add(b1);

	auto tb1 = new ZTextBox(5, 5, 100, 21);
	win->Add(tb1);

	win->Run();
}