#include "../Zlibx/ZWindow.h"
#include "../Zlibx/ZLabel.h"
#include "../Zlibx/ZButton.h"
#include "../Zlibx/ZTextBox.h"
#include "../Zlibx/ZPictureBox.h"
#include "../Zlibx/ZLink.h"
#include "../Zlibx/ZComboBox.h"
#include "../Zlibx/ZListBox.h"

ZWindow* win;
ZButton* b1;

int main()
{
	win = new ZWindow(L"Hello", 250, 200, 400, 300);
	win->Create();

	ZListBox* lb1 = new ZListBox(5, 5, 200, 200);
	win->Add(lb1);
	lb1->AddItem(L"Hello");

	win->Run();
}