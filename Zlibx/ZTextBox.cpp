/**
 * \file   ZTextBox.cpp
 * \brief  文本控件类实现
 *
 * \author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * \date   2020-12-13
 */
#include "ZTextBox.h"

ZTextBox::ZTextBox(int x, int y, int w, int h, TextBoxType type, TextBoxTextStyle textStyle)
{
	this->type = L"edit";
	SetStyle(type, textStyle);
	this->rect = RECT{ x,y,x + w,y + h };
}

void ZTextBox::SetStyle(TextBoxType type, TextBoxTextStyle textStyle)
{
	switch (type)
	{
	case Normal:
		style = WS_CHILD | WS_VISIBLE | WS_BORDER;
		break;
	case MultiV:
		style = WS_CHILD | WS_VISIBLE | WS_BORDER | ES_MULTILINE | WS_VSCROLL;
		break;
	case Multi:
		style = WS_CHILD | WS_VISIBLE | WS_BORDER | ES_MULTILINE | WS_VSCROLL | WS_HSCROLL;
		break;
	case Num:
		style = WS_CHILD | WS_VISIBLE | WS_BORDER | ES_NUMBER;
		break;
	case Pwd:
		style = WS_CHILD | WS_VISIBLE | WS_BORDER | ES_PASSWORD;
		break;
	default:
		break;
	}

	switch (textStyle)
	{
	case Center:
		style |= ES_CENTER;
		break;
	case Right:
		style |= ES_RIGHT;
		break;
	case Left:
		style |= ES_LEFT;
		break;
	default:
		break;
	}
}

void ZTextBox::SetEnable(BOOL enable)
{
	SendMessage((HWND)this->handle, EM_SETREADONLY, !enable, 0);
}

void ZTextBox::Init(HANDLE handle)
{
	this->handle = CreateWindow(
		type,
		L"",
		style,
		rect.A.x,
		rect.A.y,
		rect.GetSize().w,
		rect.GetSize().h,
		(HWND)handle,
		(HMENU)this->id,
		(HINSTANCE)GetWindowLong((HWND)handle, -6),
		NULL
	);
	SetDefaultFont();
}