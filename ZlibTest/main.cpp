#include "../Zlibx/ZWindow.h"

int main()
{
	auto win = new ZWindow(L"Hello", 0, 0, 400, 300);
	win->Create();
	win->Run();
}