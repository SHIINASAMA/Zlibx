/**
 * \file   ZButton.h
 * \brief  按钮控件类定义
 *
 * \author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * \date   2020-12-12
 */

#pragma once
#include "ZControl.h"

 /**
  * @brief ZButton 类定义
  */
class DLLAPI ZButton :
	public ZControl
{
public:
	/**
	 * 实例化一个按钮对象
	 *
	 * \param text 按钮文本
	 * \param func 按钮响应函数
	 */
	ZButton(ZString text, CALLBACKFUNC func = NULL);

	/**
	 * 实例化一个按钮对象
	 *
	 * \param text 按钮文本
	 * \param x	   x坐标
	 * \param y	   y坐标
	 * \param w    宽
	 * \param h    高
	 * \param func 按钮响应函数
	 */
	ZButton(ZString text, int x, int y, int w, int h, CALLBACKFUNC func = NULL);

	/**
	 * 重载父控件加载函数
	 *
	 * \param handle 父控件句柄
	 */
	void Init(HANDLE handle);

	/**
	 * 设置按钮是否可用
	 *
	 * \param enable 是否可用
	 */
	void SetEnable(BOOL enable);
};
