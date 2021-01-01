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
ZComboBox* box;

void change(WPARAM w, LPARAM l)
{
	int index = box->GetSelectedIndex();
	printf("选中了%d项\n", index);
}

int main()
{
	win = new ZWindow(L"Hello", 250, 200, 400, 300);
	win->Create();

	box = new ZComboBox(5, 5, 200, 150);
	win->Add(box);
	box->AddItem(L"A");
	box->AddItem(L"B");
	box->AddItem(L"C");
	box->Bind(change);

	win->Run();
}