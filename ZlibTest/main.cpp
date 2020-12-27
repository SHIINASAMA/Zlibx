#include "../Zlibx/ZWindow.h"
#include "../Zlibx/ZLabel.h"
#include "../Zlibx/ZButton.h"
#include "../Zlibx/ZTextBox.h"
#include "../Zlibx/ZPictureBox.h"
#include "../Zlibx/ZLink.h"

ZWindow* win;
ZLink* lk1;
ZButton* b1;

void btn_clicked(WPARAM wParam, LPARAM lParam)
{
	win->SetHeight(600);
	win->SetWidth(600);
}

int main()
{
	win = new ZWindow(L"Hello", 250, 200, 400, 300);
	win->Create();

	lk1 = new ZLink(L"°Ù¶È", L"https://www.baidu.com", 5, 5, 100, 21);
	win->Add(lk1);

	b1 = new ZButton(L"Hello", 5, 105, 100, 50);
	b1->Bind(btn_clicked);
	win->Add(b1);

	win->Run();
}