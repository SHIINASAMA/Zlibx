#include "../Zlibx/ZWindow.h"
#include "../Zlibx/ZLabel.h"
#include "../Zlibx/ZButton.h"
#include "../Zlibx/ZTextBox.h"
#include "../Zlibx/ZPictureBox.h"
#include "../Zlibx/ZLink.h"
#include "../Zlibx/ZComboBox.h"
#include "../Zlibx/ZListBox.h"

ZWindow* win;

int main()
{
	win = new ZWindow(L"Hello", 250, 200, 400, 300);
	win->Create();

	auto a = new ZTextBox(100, 100, 50, 21);
	win->Add(a);

	win->Run();
}