#include "../Zlibx/ZWindow.h"
#include "../Zlibx/ZLabel.h"
#include "../Zlibx/ZButton.h"

void btn_clicked(WPARAM wParam, LPARAM lParam)
{
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