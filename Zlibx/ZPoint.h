/**	@file	ZPoint.h
*	@brief	二维点类声明
*	@author kaoru(SHIINA_KAORU@OUTLOOK.COM)
*	@date	2020-12-09
*/

#pragma once

#include <Windows.h>
#include "main.h"

/**	@brief	ZPoint 类
*/
class DLLAPI ZPoint
{
public:
	/** @brief x轴坐标
	*/
	int x = 0;
	/** @brief y轴坐标
	*/
	int y = 0;

	/**@brief	实例化一个空ZPoin对象
	*/
	ZPoint();

	/**@brief	实例化一个ZPoin对象
	* @param x	x坐标
	* @param y	y坐标
	*/
	ZPoint(int x, int y);

	void operator=(POINT pt);
	operator POINT();
};
