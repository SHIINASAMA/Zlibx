#include "../Zlibx/ZWindow.h"
#include "../Zlibx/ZLabel.h"
#include "../Zlibx/ZButton.h"
#include "../Zlibx/ZTextBox.h"
#include "../Zlibx/ZPictureBox.h"
#include "../Zlibx/ZLink.h"
#include "../Zlibx/ZComboBox.h"
#include "../Zlibx/ZListBox.h"
#include "../Zlibx/ZProgressBar.h"

ZWindow* win, * cwin;
ZButton* btn;

void clicked(WPARAM w, LPARAM l)
{
	cwin = new ZWindow(L"Client", 50, 50, 200, 160);
	auto result = cwin->RunDialog(win->GetHandle());
	auto hWnd = cwin->GetHandle();
}

int main()
{
	win = new ZWindow(L"Hello", 250, 200, 400, 300);
	win->Create();

	btn = new ZButton(L"µãÎÒ", 5, 5, 200, 30);
	win->Add(btn);
	btn->Bind(clicked);

	win->Run();
}