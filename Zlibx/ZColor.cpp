/**@file	ZColor.cpp
* @brief	颜色类定义
* @author	kaoru(SHIINA_KAORU@OUTLOOK.COM)
* @date		2020-12-09
*/

#include "ZColor.h"

ZColor::ZColor(BYTE R, BYTE G, BYTE B)
{
	this->color = RGB(R, G, B);
}

ZColor::operator COLORREF()
{
	return this->color;
}

ZColor::operator Gdiplus::Color()
{
	return Color(GetRVar(), GetGVar(), GetBVar());
}

void ZColor::operator=(COLORREF color)
{
	this->color = color;
}

BYTE ZColor::GetRVar()
{
	return GetRValue(color);
}

BYTE ZColor::GetGVar()
{
	return GetGValue(color);
}

BYTE ZColor::GetBVar()
{
	return GetBValue(color);
}