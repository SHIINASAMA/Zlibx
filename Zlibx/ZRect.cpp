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
	ZPoint A = ZPoint(x1, y1);
	ZPoint B = ZPoint(x2, y2);
	this->A = A;
	this->B = B;
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

RECT ZRect::GetRect()
{
	RECT rect;
	rect.left = A.x;
	rect.top = A.y;
	rect.right = B.x;
	rect.bottom = B.y;
	return rect;
}

ZRect::operator RECT()
{
	return GetRect();
}

ZRect::operator LPCRECT()
{
	RECT r = { A.x,A.y,B.x,B.y };
	return &r;
}