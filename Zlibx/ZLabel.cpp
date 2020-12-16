/**
 * \file   ZLabel.cpp
 * \brief  静态文本控件类实现
 *
 * \author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * \date   2020-12-15
 */

#include "ZLabel.h"

ZLabel::ZLabel(ZString text, int x, int y, int w, int h)
{
	type = L"static";
	this->text = text;
	rect = RECT{ x,y,x + w,y + h };
	style = WS_CHILD | WS_VISIBLE;
}

void ZLabel::Init(HWND hWnd)
{
	phWnd = hWnd;
	this->hWnd = CreateWindow(
		type,
		text,
		style,
		rect.A.x,
		rect.A.y,
		rect.GetSize().w,
		rect.GetSize().h,
		phWnd,
		(HMENU)id,
		(HINSTANCE)GetWindowLong(phWnd, -6),
		NULL
	);
	SetDefFont();
}

void ZLabel::SetText(ZString text)
{
	RECT r = this->rect;
	SetWindowText(hWnd, text);
	::InvalidateRect(phWnd, &r, TRUE);
	/*ShowWindow(hWnd, SW_HIDE);
	ShowWindow(hWnd, SW_SHOW);*/
}