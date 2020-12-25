/**	@file	ZRect.h
*	@brief	矩形类声明
*	@author kaoru(SHIINA_KAORU@OUTLOOK.COM)
*	@date	2020-12-09
*/

#pragma once
#include <Windows.h>
#include "ZPoint.h"
#include "ZSize.h"
#include "main.h"

/**	@brief	ZRect 类
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

	/**
	 * 设置矩阵的宽
	 *
	 * \param w 目标宽度
	 */
	void SetWidth(int w);

	/**
	 * 获取矩阵的宽
	 *
	 * \return 矩阵宽度
	 */
	int GetWidth();

	/**
	 * 设置矩阵的高
	 *
	 * \param h 目标高度
	 */
	void SetHeight(int h);

	/**
	 * 获取矩阵的高
	 *
	 * \return 矩阵高度
	 */
	int GetHeight();

	/**@brief	获取矩阵大小
	* @retval	大小
	*/
	ZSize GetSize();

	/**@brief		设置矩阵大小
	* @param Size	目标大小
	*/
	void SetSize(ZSize Size);

	/**
	 * 转换子控件的矩阵
	 *
	 * \return 结果矩阵
	 */
	ZRect ToClientRect();

	/**
	 * 设置矩阵偏移值
	 *
	 * \param x	横向偏移值
	 * \param y 纵向偏移值
	 */
	void OffsetRect(int x, int y);

	operator RECT();
	operator LPRECT();
	operator Gdiplus::Rect();
};
