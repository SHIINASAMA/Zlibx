/**
 * \file   ZLabel.cpp
 * \brief  静态文本控件类实现
 *
 * \author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * \date   2020-12-12
 */

#include "ZLabel.h"

ZLabel::ZLabel(ZString text)
{
	type = L"static";
	this->text = text;
}

ZLabel::ZLabel(ZString text, int x, int y, int w, int h)
{
	type = L"static";
	this->text = text;
	this->rect = RECT{ x,y,x + w,y + h };
}

void ZLabel::Init(HANDLE handle)
{
	this->handle = CreateWindow(
		type,
		text,
		WS_CHILD | WS_VISIBLE,
		rect.A.x,
		rect.A.y,
		rect.GetSize().w,
		rect.GetSize().h,
		(HWND)handle,
		NULL,
		(HINSTANCE)GetWindowLong((HWND)handle, -6),
		NULL
	);
}