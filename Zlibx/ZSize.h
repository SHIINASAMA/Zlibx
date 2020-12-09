/**	@file	ZSize.h
*	@brief	大小类定义
*	@author kaoru(SHIINA_KAORU@OUTLOOK.COM)
*	@date	2020-12-09
*/

#pragma once

/**	@brief ZSize类定义
*/
class ZSize
{
public:
	long w = 0;
	long h = 0;

	/**	@brief		初始化一个ZSize对象
	*	@param	w	目标宽
	*	@param	h	目标高
	*/
	ZSize(long w, long h);
};
