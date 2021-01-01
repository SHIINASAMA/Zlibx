#include "../Zlibx/ZWindow.h"
#include "../Zlibx/ZLabel.h"
#include "../Zlibx/ZButton.h"
#include "../Zlibx/ZTextBox.h"
#include "../Zlibx/ZPictureBox.h"
#include "../Zlibx/ZLink.h"
#include "../Zlibx/ZComboBox.h"
#include "../Zlibx/ZListBox.h"
#include "../Zlibx/ZProgressBar.h"

ZWindow* win;
ZProgressBar* a;

void clicked(WPARAM w, LPARAM l)
{
	a->MakeStep();
}

int main()
{
	win = new ZWindow(L"Hello", 250, 200, 400, 300);
	win->Create();

	a = new ZProgressBar(100, 100, 200, 21);
	win->Add(a);

	auto b = new ZButton(L"Step", 5, 5, 200, 21);
	win->Add(b);
	b->Bind(clicked);

	win->Run();
}