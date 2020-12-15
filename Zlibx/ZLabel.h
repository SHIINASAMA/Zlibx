/**
 * \file   ZLabel.h
 * \brief  静态文本控件类定义
 *
 * \author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * \date   2020-12-15
 */

#pragma once
#include "ZControl.h"

 /**
  * \breif ZLabel 类定义
  */
class DLLAPI ZLabel :
	public ZControl
{
public:
	/**
	 * 实例化一个静态文本控件对象
	 *
	 * \param text 显示文本
	 */
	ZLabel(ZString text);

	/**
	 * 实例化一个静态文本控件对象
	 *
	 * \param text	显示
	 * \param x		x坐标
	 * \param y		y坐标
	 * \param w		宽
	 * \param h		高
	 */
	ZLabel(ZString text, int x, int y, int w, int h);

	/**
	 * 重写父控件调用的初始化函数
	 *
	 * \param hWnd 父控件句柄
	 */
	void Init(HWND hWnd);

	/**
	 * 设置控件文本
	 *
	 * \param text 目标文本
	 */
	void SetText(ZString text);
};
