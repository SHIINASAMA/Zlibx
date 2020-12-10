/**	@file	ZRange.cpp
*	@brief	区间类实现
*	@author	kaoru(SHIINA_KAORU@OUTLOOK.COM)
*	@date	2020-12-10
*/

#include "ZRange.h"

ZRange::ZRange()
{
}

ZRange::ZRange(int x1, int x2)
{
	this->x1 = x1;
	this->x2 = x2;
}

void ZRange::operator=(PBRANGE Range)
{
	this->x1 = Range.iLow;
	this->x2 = Range.iHigh;
}

ZRange::operator PBRANGE()
{
	PBRANGE range;
	range.iLow = x1;
	range.iHigh = x2;
	return range;
}