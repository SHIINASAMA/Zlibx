/**	@file	ZPoint.cpp
*	@brief	二维点类定义
*	@author kaoru(SHIINA_KAORU@OUTLOOK.COM)
*	@date	2020-12-09
*/

#include "ZPoint.h"

ZPoint::ZPoint()
{
}

ZPoint::ZPoint(int x, int y)
{
	this->x = x;
	this->y = y;
}

void ZPoint::operator=(POINT pt)
{
	this->x = pt.x;
	this->y = pt.y;
}

ZPoint::operator POINT()
{
	POINT pt;
	pt.x = this->x;
	pt.y = this->y;
	return pt;
}