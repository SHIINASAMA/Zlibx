/**	@file	ZPoint.h
*	@brief	二维点类定义
*	@author kaoru(SHIINA_KAORU@OUTLOOK.COM)
*	@date	2020-12-09
*/

#pragma once

#include <Windows.h>

/**	@brief	ZPoint类实现
*/
class ZPoint
{
public:
	int x = 0;
	int y = 0;

	/**@brief	实例化一个空ZPoin对象
	*/
	ZPoint();

	/**@brief	实例化一个ZPoin对象
	* @param X	x坐标
	* @param Y	y坐标
	*/
	ZPoint(int x, int y);

	void operator=(POINT pt);
	operator POINT();
};
