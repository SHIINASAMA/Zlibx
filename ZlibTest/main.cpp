#include "../Zlibx/ZWindow.h"
#include "../Zlibx/ZLabel.h"
#include "../Zlibx/ZButton.h"
#include "../Zlibx/ZTextBox.h"
#include "../Zlibx/ZPictureBox.h"

ZWindow* win;
ZTextBox* tb1;
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

	b1 = new ZButton(L"Hello", 5, 105, 100, 50);
	b1->Bind(btn_clicked);
	win->Add(b1);

	win->Run();
}