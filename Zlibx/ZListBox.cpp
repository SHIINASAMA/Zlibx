/**
 * \file   ZListBox.cpp
 * \brief  列表控件类定义
 *
 * \author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * \date   2020-12-31
 */

#include "ZListBox.h"

ZString ZListBox::type = L"Zlibx_listBox";
BOOL ZListBox::isRegistered = FALSE;

std::map<HWND, ZListBox*> ZListBox::listBoxList;
WNDPROC ZListBox::oldProc;

ZListBox* ZListBox::GetListBox(HWND hWnd)
{
	auto itor = listBoxList.find(hWnd);
	if (itor != listBoxList.end())
	{
		return itor->second;
	}
	else
	{
		return nullptr;
	}
}

LRESULT ZListBox::ConProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	ZListBox* temp = GetListBox(hWnd);
	if (temp != nullptr)
	{
		switch (uMsg)
		{
		case WM_MOVE:
		case WM_SIZE:
		{
			UpdateRect(temp);
			break;
		}
		case WM_DESTROY:
		{
			temp->~ZListBox();
			PostQuitMessage(0);
			break;
		}
		default:
		{
			return CallWindowProc(oldProc, hWnd, uMsg, wParam, lParam);
			break;
		}
		}
	}
	return CallWindowProc(oldProc, hWnd, uMsg, wParam, lParam);
}

void ZListBox::SetDefFont()
{
	SetFont(ZFont(L"新宋体"));
}

void ZListBox::SetFont(ZFont font)
{
	SendMessage(hWnd, WM_SETFONT, (WPARAM)(HFONT)font, 0);
}

ZListBox::~ZListBox()
{
	listBoxList.erase(hWnd);
}

ZListBox::ZListBox(int x, int y, int w, int h)
{
	this->rect = RECT{ x,y,x + w,y + h };
}

void ZListBox::Init(HWND hWnd)
{
	auto hInstance = (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE);
	if (!isRegistered)
	{
		WNDCLASSEX wcex{ 0 };
		GetClassInfoEx(hInstance, L"listbox", &wcex);
		wcex.cbSize = sizeof(WNDCLASSEX);
		oldProc = wcex.lpfnWndProc;
		wcex.lpfnWndProc = ConProc;
		wcex.hInstance = hInstance;
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

	phWnd = hWnd;
	this->hWnd = CreateWindow(
		type,
		NULL,
		WS_CHILD | WS_VISIBLE | LBS_HASSTRINGS | WS_BORDER,
		rect.A.x,
		rect.A.y,
		rect.B.x - rect.A.x,
		rect.B.y - rect.A.y,
		phWnd,
		NULL,
		hInstance,
		NULL
	);

	SetDefFont();
	listBoxList.insert(std::pair<HWND, ZListBox*>(this->hWnd, this));
}

void ZListBox::AddItem(ZString text)
{
	SendMessage(hWnd, LB_ADDSTRING, 0, (LPARAM)text.ToWString());
}

void ZListBox::RemoveAt(UINT pos)
{
	SendMessage(hWnd, LB_DELETESTRING, pos, 0);
}

int ZListBox::Find(ZString text)
{
	return (int)SendMessage(hWnd, LB_FINDSTRING, 0, (LPARAM)text.ToWString());
}

void ZListBox::Insert(UINT pos, ZString text)
{
	SendMessage(hWnd, LB_INSERTSTRING, pos, (LPARAM)text.ToWString());
}

ZString ZListBox::GetText(UINT pos)
{
	int len = (int)SendMessage(hWnd, LB_GETTEXTLEN, 0, pos);
	if (len > 0)
	{
		WChar* str = (WChar*)malloc(sizeof(WChar) * len);
		SendMessage(hWnd, LB_GETTEXT, (WPARAM)str, static_cast<unsigned __int64>(len));
		return str;
	}
	return ZString();
}

void ZListBox::SetSelectedIndex(UINT index)
{
	SendMessage(hWnd, LB_SETCURSEL, index, 0);
}

UINT ZListBox::GetSelectedIndex()
{
	return (UINT)SendMessage(hWnd, LB_GETCURSEL, 0, 0);
}

void ZListBox::RemoveAll()
{
	SendMessage(hWnd, LB_RESETCONTENT, 0, 0);
}

UINT ZListBox::Count()
{
	return (UINT)SendMessage(hWnd, LB_GETCOUNT, 0, 0);
}