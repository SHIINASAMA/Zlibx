/**
 * \file   ZTextBox.cpp
 * \brief  文本编辑控件类定义
 *
 * \author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * \date   2020-12-22
 */

#include "ZTextBox.h"
#include "ZDebug.h"

ZString ZTextBox::type = L"Zlibx_textBox";
BOOL ZTextBox::isRegistered = FALSE;

std::map<HWND, const ZTextBox*> ZTextBox::textBoxList;

WNDPROC ZTextBox::oldProc;

void ZTextBox::SetStyle(TextBoxStyle style, TextBoxTextStyle textStyle)
{
	switch (style)
	{
	case TextBoxStyle::Normal:
		this->style = WS_CHILD | WS_VISIBLE | WS_BORDER;
		break;
	case TextBoxStyle::MultiV:
		this->style = WS_CHILD | WS_VISIBLE | WS_BORDER | ES_MULTILINE | WS_VSCROLL;
		break;
	case TextBoxStyle::Multi:
		this->style = WS_CHILD | WS_VISIBLE | WS_BORDER | ES_MULTILINE | WS_VSCROLL | WS_HSCROLL;
		break;
	case TextBoxStyle::Num:
		this->style = WS_CHILD | WS_VISIBLE | WS_BORDER | ES_NUMBER;
		break;
	case TextBoxStyle::Pwd:
		this->style = WS_CHILD | WS_VISIBLE | WS_BORDER | ES_PASSWORD;
		break;
	default:
		break;
	}

	switch (textStyle)
	{
	case TextBoxTextStyle::Center:
		this->style |= ES_CENTER;
		break;
	case TextBoxTextStyle::Right:
		this->style |= ES_RIGHT;
		break;
	case TextBoxTextStyle::Left:
		this->style |= ES_LEFT;
		break;
	default:
		break;
	}
}

ZTextBox::ZTextBox(int x, int y, int w, int h, TextBoxStyle style, TextBoxTextStyle textStyle)
{
	this->rect = RECT{ x,y,x + w,y + h };
	SetStyle(style, textStyle);
}

void ZTextBox::Init(HWND hWnd)
{
	auto hInstance = (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE);
	if (!isRegistered)
	{
		WNDCLASSEX wcex = { 0 };
		GetClassInfoEx(hInstance, L"edit", &wcex);
		wcex.cbSize = sizeof(WNDCLASSEX);
		wcex.lpszClassName = type;
		oldProc = wcex.lpfnWndProc;
		wcex.lpfnWndProc = ConProc;
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
		L"",
		style,
		rect.A.x,
		rect.A.y,
		rect.B.x - rect.A.x,
		rect.B.y - rect.A.y,
		phWnd,
		NULL,
		(HINSTANCE)GetWindowLongPtr(phWnd, GWLP_HINSTANCE),
		NULL
	);

	SetDefFont();
	textBoxList.insert(std::pair<HWND, const ZTextBox*>(this->hWnd, this));
}

void ZTextBox::SetFont(ZFont font)
{
	SendMessage(hWnd, WM_SETFONT, (WPARAM)(HFONT)font, 0);
}

const ZTextBox* ZTextBox::GetTextBox(HWND hWnd)
{
	auto iter = textBoxList.find(hWnd);
	if (iter != textBoxList.end() && iter->second != NULL)
	{
		return iter->second;
	}
	else
	{
		return nullptr;
	}
}

void ZTextBox::SetDefFont()
{
	SetFont(ZFont(L"新宋体"));
}

LRESULT ZTextBox::ConProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	ZTextBox* temp = const_cast<ZTextBox*>(GetTextBox(hWnd));
	if (temp != NULL)
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
			temp->~ZTextBox();
			break;
		}
		default:
			return oldProc(hWnd, uMsg, wParam, lParam);
			break;
		}
	}
	return oldProc(hWnd, uMsg, wParam, lParam);
}

ZTextBox::~ZTextBox()
{
	textBoxList.erase(hWnd);
}

void ZTextBox::SetEnable(BOOL enable)
{
	SendMessage(hWnd, EM_SETREADONLY, !enable, 0);
}

void ZTextBox::SetText(ZString text)
{
	SetWindowText(hWnd, text);
}

ZString ZTextBox::GetText()
{
	UINT len = GetWindowTextLengthW(hWnd);
	WChar* str = new WChar[static_cast<unsigned __int64>(len) + 1];
	GetWindowTextW(this->hWnd, str, len + 1);
	//str[len] = L'\0';
	ZString temp;
	temp.Pause(str);
	return temp;
}