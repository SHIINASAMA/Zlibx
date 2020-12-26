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
	b1->SetPosition(ZPoint{ 100, 100 });
}

int main()
{
	win = new ZWindow(L"Hello", 250, 200, 400, 300);
	win->Create();
	//win->ShowCenter();

	/*tb1 = new ZTextBox(5, 5, 100, 21);
	win->Add(tb1);*/

	b1 = new ZButton(L"Hello", 5, 105, 100, 50);
	b1->Bind(btn_clicked);
	//b1->SetEnable(FALSE);
	win->Add(b1);
	b1->SetHeight(25);
	b1->SetWidth(50);

	win->Run();
}