/**	@file	ZRect.cpp
*	@brief	矩形类定义
*	@author kaoru(SHIINA_KAORU@OUTLOOK.COM)
*	@date	2020-12-09
*/

#include "ZRect.h"

ZRect::ZRect()
{
}

ZRect::ZRect(RECT Rect)
{
	this->A.x = Rect.left;
	this->A.y = Rect.top;
	this->B.x = Rect.right;
	this->B.y = Rect.bottom;
}

ZRect::ZRect(ZPoint A, ZPoint B)
{
	this->A = A;
	this->B = B;
}

ZRect::ZRect(int x1, int y1, int x2, int y2)
{
	this->A = ZPoint(x1, y1);;
	this->B = ZPoint(x2, y2);
}

void ZRect::SetWidth(int w)
{
	B.x = A.x + w;
}

int ZRect::GetWidth()
{
	return B.x - A.x;
}

void ZRect::SetHeight(int h)
{
	B.y = A.y + h;
}

int ZRect::GetHeight()
{
	return B.y - A.y;
}

ZSize ZRect::GetSize()
{
	int w = B.x - A.x;
	int h = B.y - A.y;
	return ZSize(w, h);
}

void ZRect::SetSize(ZSize Size)
{
	B.x = A.x + Size.w;
	B.y = A.y + Size.h;
}

ZRect ZRect::ToClientRect()
{
	ZRect rect;
	rect.A.x = 0;
	rect.A.y = 0;
	rect.B.x = GetWidth();
	rect.B.y = GetHeight();
	return rect;
}

void ZRect::OffsetRect(int x, int y)
{
	A.x += x;
	B.x += x;

	A.y += y;
	B.y += y;
}

ZRect::operator RECT()
{
	RECT rect;
	rect.left = A.x;
	rect.top = A.y;
	rect.right = B.x;
	rect.bottom = B.y;
	return rect;
}

ZRect::operator LPRECT()
{
	return new RECT{ A.x,A.y,B.x,B.y };
}

ZRect::operator Gdiplus::Rect()
{
	return Gdiplus::Rect(
		A.x,
		A.y,
		B.x - A.x,
		B.y - A.y
	);
}