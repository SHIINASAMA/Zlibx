/**	@file	ZSize.h
*	@brief	大小类定义
*	@author kaoru(SHIINA_KAORU@OUTLOOK.COM)
*	@date	2020-12-09
*/

#pragma once

#include "main.h"

/**	@brief ZSize 类定义
*/
class DLLAPI ZSize
{
public:
	/** @brief 宽
	*/
	int w = 0;
	/** @brief 高
	*/
	int h = 0;

	/**	@brief		初始化一个ZSize对象
	*	@param	w	目标宽
	*	@param	h	目标高
	*/
	ZSize(int w, int h);
};
