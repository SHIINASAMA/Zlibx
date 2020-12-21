#include "../Zlibx/ZWindow.h"
#include "../Zlibx/ZLabel.h"
#include "../Zlibx/ZButton.h"

void btn_clicked(WPARAM wParam, LPARAM lParam)
{
	auto win = new ZWindow(L"这是一个子窗体", 0, 0, 300, 200);
	win->Create();
	win->Run();
}

int main()
{
	auto win = new ZWindow(L"Hello", 0, 0, 400, 300);
	win->Create();

	auto b1 = new ZButton(L"Hello", 5, 5, 100, 50);
	b1->Bind(btn_clicked);
	win->Add(b1);

	win->Run();
}