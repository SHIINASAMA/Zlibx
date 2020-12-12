/**
 * \file   ZControl.cpp
 * \brief  控件类实现
 *
 * \author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * \date   2020-12-11
 */

#include "ZControl.h"

ZString ZControl::GetText()
{
	UINT len = GetWindowTextLengthW((HWND)handle);
	WChar* str = (WChar*)malloc(sizeof(WChar) * (static_cast<unsigned long long>(len) + 1));
	GetWindowTextW((HWND)handle, str, sizeof(WChar) * (static_cast<unsigned long long>(len) + 1));
	//str[len] = L'\0';
	ZString temp;
	temp.Pause(str);
	return temp;
}

void ZControl::SetText(ZString text)
{
	SetWindowTextW((HWND)handle, text);
}

DWORDLONG ZControl::GetID()
{
	return id;
}

void ZControl::SetSize(ZSize size)
{
	RECT rect;
	GetWindowRect((HWND)handle, &rect);
	this->rect = rect;
	MoveWindow(
		(HWND)handle,
		rect.left,
		rect.top,
		size.w,
		size.h,
		TRUE
	);
}

void ZControl::SetSize(int w, int h)
{
	ZSize size{ w,h };
	RECT rect;
	GetWindowRect((HWND)handle, &rect);
	this->rect = rect;
	MoveWindow(
		(HWND)handle,
		rect.left,
		rect.top,
		size.w,
		size.h,
		TRUE
	);
}

ZSize ZControl::GetSize()
{
	RECT rect;
	GetWindowRect((HWND)handle, &rect);
	this->rect = rect;
	return this->rect.GetSize();
}

void ZControl::SetFont(ZFont font)
{
	this->font = font;
	SendMessage((HWND)handle, WM_SETFONT, (WPARAM)(HFONT)font, 0);
}

ZPoint ZControl::GetPoint()
{
	RECT rect;
	GetWindowRect((HWND)handle, &rect);
	this->rect = rect;
	return this->rect.A;
}

void ZControl::SetPoint(ZPoint point)
{
	RECT rect;
	GetWindowRect((HWND)handle, &rect);
	this->rect = rect;
	int w = this->rect.GetSize().w;
	int h = this->rect.GetSize().h;
	MoveWindow(
		(HWND)handle,
		point.x,
		point.y,
		w,
		h,
		TRUE
	);
	this->rect.A = point;
	this->SetSize(ZSize(w, h));
}

CALLBACKFUNC ZControl::GetFunc()
{
	return this->func;
}