/**
 * \file   ZControl.cpp
 * \brief  控件基类定义
 *
 * \author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * \date   2020-12-19
 */

#include "ZControl.h"

ZString ZControl::type = L"Zlibx_control";

LRESULT ZControl::ConProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return LRESULT();
}

void ZControl::UpdateRect(ZControl* con)
{
	POINT p;
	RECT rect;
	GetWindowPos(con->hWnd, &p);
	GetClientRect(con->hWnd, &rect);
	ZRect temp;
	temp.B.x = rect.right;
	temp.B.y = rect.bottom;
	temp.OffsetRect(p.x, p.y);
	con->rect = temp;

	//printf_s("%4d|%4d|%4d|%4d\n\n", temp.A.x, temp.A.y, temp.B.x, temp.B.y);
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
	ZRect rect = this->rect.ToClientRect();
	MoveWindow(
		hWnd,
		this->rect.A.x,
		this->rect.A.y,
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
	ZRect rect = this->rect.ToClientRect();
	MoveWindow(
		hWnd,
		this->rect.A.x,
		this->rect.A.y,
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

void GetWindowPos(HWND hWnd, POINT* point)
{
	HWND hWndParent = GetParent(hWnd);
	POINT p = { 0 };

	MapWindowPoints(hWnd, hWndParent, &p, 1);

	*point = p;
}