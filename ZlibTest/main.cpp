#include "../Zlibx/ZWindow.h"
#include "../Zlibx/ZLabel.h"
#include "../Zlibx/ZButton.h"
#include "../Zlibx/ZTextBox.h"
#include "../Zlibx/ZPictureBox.h"

ZWindow* win;

void btn_clicked(WPARAM wParam, LPARAM lParam)
{
}

int main()
{
	win = new ZWindow(L"Hello", NULL, NULL, 400, 300);
	win->Create();
	win->ShowCenter();

	//ZButton* b1 = new ZButton(L"Hello", 5, 105, 100, 50);
	//b1->Bind(btn_clicked);
	////b1->SetEnable(FALSE);
	//win->Add(b1);

	ZLabel* l1 = new ZLabel(L"Hello", 5, 105, 100, 50);
	win->Add(l1);

	auto pb1 = new ZPictureBox(5, 5, 100, 100, DisplayMode::Zoom);
	ZBitmap bmp;
	bmp.LoadFromFile(L"C:\\Users\\kaoru\\Desktop\\女子高生.bmp");
	pb1->SetImage(bmp);
	win->Add(pb1);

	win->Run();
}