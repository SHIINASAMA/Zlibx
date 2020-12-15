/**
 * \file   ZControl.cpp
 * \brief  控件基类实现
 *
 * \author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * \date   2020-12-15
 */

#include "ZControl.h"

void ZControl::Bind(MessageType type, CallbackFunc func)
{
	ControlFunc confunc{ type,func };
	funcs.push_back(confunc);
}

void ZControl::SetFont(ZFont font)
{
	SendMessage(hWnd, WM_SETFONT, (WPARAM)(HFONT)font, 0);
}

void ZControl::SetDefFont()
{
	ZFont font;
	font.Create(L"新宋体");
	SetFont(font);
}

ZString ZControl::GetText()
{
	UINT len = GetWindowTextLengthW(hWnd);
	WChar* str = (WChar*)malloc(sizeof(WChar) * (static_cast<unsigned long long>(len) + 1));
	GetWindowTextW(hWnd, str, sizeof(WChar) * (static_cast<unsigned long long>(len) + 1));
	//str[len] = L'\0';
	ZString temp;
	temp.Pause(str);
	return temp;
}

void ZControl::SetText(ZString text)
{
	SetWindowTextW(hWnd, text);
}

void ZControl::SetPoint(ZPoint point)
{
	int w = rect.GetSize().w;
	int h = rect.GetSize().h;
	MoveWindow(hWnd,
		point.x,
		point.y,
		w,
		h,
		TRUE
	);

	rect.A = point;
	rect.SetSize(ZSize(w, h));
}

ZPoint ZControl::GetPoint()
{
	return rect.A;
}

void ZControl::SetSize(ZSize size)
{
	MoveWindow(
		hWnd,
		rect.A.x,
		rect.A.y,
		size.w,
		size.h,
		TRUE
	);

	rect.SetSize(size);
}

ZSize ZControl::GetSize()
{
	return rect.GetSize();
}