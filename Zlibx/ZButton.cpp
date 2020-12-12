/**
 * \file   ZButton.cpp
 * \brief  按钮控件类实现
 *
 * \author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * \date   2020-12-12
 */

#include "ZButton.h"

ZButton::ZButton(ZString text, CALLBACKFUNC func)
{
	this->type = L"button";
	this->text = text;
	this->func = func;
}

ZButton::ZButton(ZString text, int x, int y, int w, int h, CALLBACKFUNC func)
{
	this->type = L"button";
	this->text = text;
	this->rect = RECT{ x,y,x + w,y + h };
	this->func = func;
}

void ZButton::Init(HANDLE handle)
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
		(HMENU)this->id,
		(HINSTANCE)GetWindowLong((HWND)handle, -6),
		NULL
	);
}

void ZButton::SetEnable(BOOL enable)
{
	EnableWindow((HWND)this->handle, enable);
}