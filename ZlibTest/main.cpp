#include "../Zlibx/ZWindow.h"
#include "../Zlibx/ZLabel.h"

int main()
{
	auto win = new ZWindow(L"Hello", 0, 0, 400, 300);
	win->Create();

	auto l1 = new ZLabel(L"Hello", 5, 5, 200, 60);
	win->Add(l1);

	win->Run();
}