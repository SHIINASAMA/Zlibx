/**	@file	ZRect.h
*	@brief	矩形类定义
*	@author kaoru(SHIINA_KAORU@OUTLOOK.COM)
*	@date	2020-12-09
*/

#pragma once
#include <Windows.h>
#include "ZPoint.h"
#include "ZSize.h"
#include "main.h"

/**	@brief	ZRect 类定义
*/
class DLLAPI ZRect
{
public:
	/** @brief 左上角坐标
	*/
	ZPoint A;
	/** @brief 右下角坐标
	*/
	ZPoint B;

	/**@brief 创建空 ZRect 对象
	*/
	ZRect();

	/**@brief		初始化 ZRect 对象
	* @param Rect	源对象
	*/
	ZRect(RECT Rect);

	/**@brief	初始化 ZRect 对象
	* @param A	左上角的点
	* @param B	右下角的点
	*/
	ZRect(ZPoint A, ZPoint B);

	/**@brief	初始化 ZRect 对象
	* @param x1 左上角点X坐标
	* @param y1 左上角点Y坐标
	* @param x2 右下角点Y坐标
	* @param y2 右下角点Y坐标
	*/
	ZRect(int x1, int y1, int x2, int y2);

	/**@brief	获取矩阵大小
	* @retval	大小
	*/
	ZSize GetSize();

	/**@brief		设置矩阵大小
	* @param Size	目标大小
	*/
	void SetSize(ZSize Size);

	/**@brief	获取RECT结构
	* @retval	结构
	*/
	RECT GetRect();

	operator RECT();
};
