/**
 * \file   ZButton.h
 * \brief  按钮控件类定义
 *
 * \author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * \date   2020-12-15
 */

#pragma once
#include "ZControl.h"

 /** \brief ZButton 类定义 */
class DLLAPI ZButton :
	public ZControl
{
public:
	/**
	 * 实例化一个按钮控件对象
	 *
	 * \param text	控件文本
	 * \param x		x坐标
	 * \param y		y坐标
	 * \param w		宽
	 * \param h		高
	 */
	ZButton(ZString text, int x, int y, int w, int h);

	/**
	 * 重载父控件加载函数
	 *
	 * \param hWnd 父控件句柄
	 */
	void Init(HWND hWnd);
};
