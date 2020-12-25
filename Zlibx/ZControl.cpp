/**
 * \file   ZControl.cpp
 * \brief  控件基类定义
 *
 * \author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * \date   2020-12-19
 */

#include "ZControl.h"

LRESULT ZControl::ConProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return LRESULT();
}

void ZControl::UpdateRect(ZControl* con)
{
	RECT rect;
	GetWindowRect(con->hWnd, &rect);
	con->rect = rect;
}

ZControl::~ZControl()
{
}

ZControl::ZControl()
{
}

void ZControl::SetPosition(ZPoint point)
{
	UpdateRect(this);
	auto rect = this->rect.ToClientRect();
	rect.OffsetRect(point.x, point.y);
	MoveWindow(
		hWnd,
		rect.A.x,
		rect.A.y,
		rect.GetWidth(),
		rect.GetHeight(),
		TRUE
	);
}

ZPoint ZControl::GetPosition()
{
	UpdateRect(this);
	return rect.A;
}

void ZControl::SetWidth(UINT w)
{
	UpdateRect(this);
	MoveWindow(
		hWnd,
		rect.A.x,
		rect.A.y,
		rect.A.x + w,
		rect.B.y,
		TRUE
	);
}

UINT ZControl::GetWidth()
{
	UpdateRect(this);
	return rect.GetWidth();
}

void ZControl::SetHeight(UINT h)
{
	UpdateRect(this);
	MoveWindow(
		hWnd,
		rect.A.x,
		rect.A.y,
		rect.B.x,
		rect.A.y + h,
		TRUE
	);
}

UINT ZControl::GetHeight()
{
	UpdateRect(this);
	return rect.GetHeight();
}