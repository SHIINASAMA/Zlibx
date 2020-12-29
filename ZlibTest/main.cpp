#include "../Zlibx/ZWindow.h"
#include "../Zlibx/ZLabel.h"
#include "../Zlibx/ZButton.h"
#include "../Zlibx/ZTextBox.h"
#include "../Zlibx/ZPictureBox.h"
#include "../Zlibx/ZLink.h"
#include "../Zlibx/ZComboBox.h"

ZWindow* win;
ZComboBox* cb1;
ZButton* b1;

void btn_clicked(WPARAM wParam, LPARAM lParam)
{
}

int main()
{
	win = new ZWindow(L"Hello", 250, 200, 400, 300);
	win->Create();

	cb1 = new ZComboBox(5, 5, 100, 100, ComboBoxStyle::DropDownList);
	win->Add(cb1);

	b1 = new ZButton(L"Hello", 5, 105, 100, 50);
	b1->Bind(btn_clicked);
	win->Add(b1);

	win->Run();
}