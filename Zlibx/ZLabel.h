/**
 * \file   ZLabel.h
 * \brief  静态文本控件类定义
 *
 * \author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * \date   2020-12-12
 */

#pragma once
#include "ZControl.h"

 /**
  * ZLabel 类定义
  */
class DLLAPI ZLabel :
	public ZControl
{
public:
	/**
	 * 实例化一个ZLabel对象
	 *
	 * \param text 显示文本
	 */
	ZLabel(ZString text);

	/**
	 * 实例化一个ZLabel对象
	 *
	 * \param text	显示文本
	 * \param x		x坐标
	 * \param y		y坐标
	 * \param w		宽
	 * \param h		高
	 */
	ZLabel(ZString text, int x, int y, int w, int h);

	/**
	 * 重载父控件加载函数
	 *
	 * \param handle 父控件句柄
	 * \return		 子控件句柄
	 */
	void Init(HANDLE handle);
};
