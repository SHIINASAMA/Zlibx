/**
 * \file   ZComboBox.cpp
 * \brief  下拉框控件类定义
 *
 * \author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * \date   2020-12-29
 */

#include "ZComboBox.h"

ZString ZComboBox::type = L"Zlibx_comboBox";
BOOL ZComboBox::isRegistered = FALSE;

std::map<HWND, ZComboBox*> ZComboBox::comboBoxList;

WNDPROC ZComboBox::oldProc;

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

LRESULT ZComboBox::ConProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	auto temp = GetComboBox(hWnd);
	if (temp != NULL)
	{
		switch (uMsg)
		{
		case WM_COMMAND:
		{
			if (HIWORD(wParam) == CBN_SELCHANGE)
			{
				if (temp->selectedItemChange != NULL)
				{
					temp->selectedItemChange(wParam, lParam);
				}
			}
		}
		case WM_MOVE:
		case WM_SIZE:
		{
			UpdateRect(temp);
			break;
		}
		case WM_DESTROY:
		{
			temp->~ZComboBox();
			break;
		}
		default:
			break;
		}
	}
	return CallWindowProc(oldProc, hWnd, uMsg, wParam, lParam);
}

void ZComboBox::SetDefFont()
{
	font.Create(L"新宋体");
	SetFont(font);
}

void ZComboBox::SetStyle(ComboBoxStyle style)
{
	this->style = WS_VISIBLE | WS_CHILD | CBS_HASSTRINGS | CBS_AUTOHSCROLL | WS_VSCROLL;
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

ZComboBox::~ZComboBox()
{
	comboBoxList.erase(hWnd);
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
		oldProc = wcex.lpfnWndProc;
		wcex.lpfnWndProc = ConProc;
		wcex.lpszClassName = type;
		if (!RegisterClassEx(&wcex))
		{
			MessageBox(phWnd, L"控件注册失败", type, MB_OK | MB_ICONERROR);
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

void ZComboBox::AddItem(ZString text)
{
	SendMessage(hWnd, CB_ADDSTRING, 0, (LPARAM)text.ToWString());
}

void ZComboBox::RemoveAt(UINT pos)
{
	SendMessage(hWnd, CB_DELETESTRING, pos, 0);
}

int ZComboBox::Find(ZString text)
{
	return (int)SendMessage(hWnd, CB_FINDSTRING, 0, (LPARAM)text.ToWString());
}

void ZComboBox::Insert(UINT pos, ZString text)
{
	SendMessage(hWnd, CB_INSERTSTRING, pos, (LPARAM)text.ToWString());
}

ZString ZComboBox::GetText(UINT pos)
{
	int len = (int)SendMessage(hWnd, CB_GETLBTEXTLEN, 0, pos);
	if (len > 0)
	{
		WChar* str = (WChar*)malloc(sizeof(WChar) * len);
		SendMessage(hWnd, CB_GETLBTEXT, (WPARAM)str, static_cast<unsigned __int64>(len));
		return str;
	}
	return ZString();
}

void ZComboBox::SetSelectedIndex(UINT index)
{
	SendMessage(hWnd, CB_SETCURSEL, index, 0);
}

UINT ZComboBox::GetSelectedIndex()
{
	return (UINT)SendMessage(hWnd, CB_GETCURSEL, 0, 0);
}

void ZComboBox::RemoveAll()
{
	SendMessage(hWnd, CB_RESETCONTENT, 0, 0);
}

UINT ZComboBox::Count()
{
	return (UINT)SendMessage(hWnd, CB_GETCOUNT, 0, 0);
}

void ZComboBox::Bind(CallBackFunc func)
{
	this->selectedItemChange = func;
}