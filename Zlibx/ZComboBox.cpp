#include "ZComboBox.h"

ZString ZComboBox::type = L"Zlibx_comboBox";
BOOL ZComboBox::isRegistered = FALSE;

std::map<HWND, ZComboBox*> ZComboBox::comboBoxList;

ZComboBox* ZComboBox::GetComboBox(HWND hWnd)
{
	auto itor = comboBoxList.find(hWnd);
	if (itor != comboBoxList.end())
	{
		return itor->second;
	}
	else
	{
		return nullptr;
	}
}

void ZComboBox::SetDefFont()
{
	font.Create(L"ÐÂËÎÌå");
	SetFont(font);
}

void ZComboBox::SetStyle(ComboBoxStyle style)
{
	this->style = WS_VISIBLE | WS_CHILD | CBS_HASSTRINGS | CBS_AUTOHSCROLL;
	switch (style)
	{
	case ComboBoxStyle::DropDown:
		this->style |= CBS_DROPDOWN;
		break;
	case ComboBoxStyle::Simple:
		this->style |= CBS_SIMPLE;
		break;
	case ComboBoxStyle::DropDownList:
		this->style |= CBS_DROPDOWNLIST;
		break;
	}
}

ZComboBox::ZComboBox(int x, int y, int w, int h, ComboBoxStyle style)
{
	this->rect = RECT{ x, y, x + w, y + h };
	SetStyle(style);
}

void ZComboBox::Init(HWND hWnd)
{
	auto hInstance = (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE);
	if (!isRegistered)
	{
		WNDCLASSEX wcex = { 0 };
		GetClassInfoEx(hInstance, L"combobox", &wcex);
		wcex.cbSize = sizeof(WNDCLASSEX);
		wcex.lpszClassName = type;
		if (!RegisterClassEx(&wcex))
		{
			MessageBox(phWnd, L"¿Ø¼þ×¢²áÊ§°Ü", type, MB_OK | MB_ICONERROR);
			return;
		}
		else
		{
			isRegistered = TRUE;
		}
	}

	this->phWnd = hWnd;
	this->hWnd = CreateWindow(
		type,
		L"",
		style,
		rect.A.x,
		rect.A.y,
		rect.GetWidth(),
		rect.GetHeight(),
		phWnd,
		NULL,
		hInstance,
		NULL
	);

	this->comboBoxList.insert(std::pair<HWND, ZComboBox*>(this->hWnd, this));
	SetDefFont();
}

void ZComboBox::SetFont(ZFont font)
{
	SendMessage(hWnd, WM_SETFONT, (WPARAM)(HFONT)font, 0);
}