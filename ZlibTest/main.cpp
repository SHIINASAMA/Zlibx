#include "../Zlibx/ZWindow.h"
#include "../Zlibx/ZLabel.h"
#include "../Zlibx/ZButton.h"
#include "../Zlibx/ZTextBox.h"

void btn_clicked(WPARAM wParam, LPARAM lParam)
{
	auto win = new ZWindow(L"A", 100, 200, 400, 300);
	win->Create();
	win->Run();
}

int main()
{
	auto win = new ZWindow(L"Hello", 0, 0, 400, 300);
	win->Create();

	auto b1 = new ZButton(L"Hello", 5, 35, 100, 50);
	b1->Bind(btn_clicked);
	b1->SetEnable(FALSE);
	win->Add(b1);

	auto tb1 = new ZTextBox(5, 5, 100, 21);
	win->Add(tb1);

	win->Run();
}