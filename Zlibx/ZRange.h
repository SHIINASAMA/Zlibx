/**	@file	ZRange.h
*	@brief	区间类声明
*	@author	kaoru(SHIINA_KAORU@OUTLOOK.COM)
*	@date	2020-12-10
*/

#pragma once

#include <Windows.h>
#include <CommCtrl.h>
#include "main.h"

/**	@brief ZRange 类
*/
class DLLAPI ZRange
{
public:
	/** @brief 左端点
	*/
	int x1;
	/** @brief 右端点
	*/
	int x2;

	/**@brief	实例化一个空ZRange对象
	*/
	ZRange();
	/**@brief	实例化一个ZRange对象
	* @param x1 左端点
	* @param x2 右端点
	*/
	ZRange(int x1, int x2);

	void operator=(PBRANGE Range);
	operator PBRANGE();
};
