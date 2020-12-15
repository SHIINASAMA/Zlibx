/**
 * \file   ZTextBox.h
 * \brief  文本控件类定义
 *
 * \author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * \date   2020-12-13
 */

#pragma once

#include "ZControl.h"

 /**
  * @brief 控件样式枚举
  */
enum DLLAPI TextBoxType {
	/** @brief 普通单行*/
	Normal,
	/** @brief 自动向下滚动*/
	MultiV,
	/** @brief 自动多行文本*/
	Multi,
	/** @brief 单行数字 */
	Num,
	/** @brief 单行密码 */
	Pwd
};

/**
 * @brief 控件文本格式枚举
 */
enum DLLAPI TextBoxTextStyle {
	/** @brief 文本居中 */
	Center,
	/** @brief 文本右对齐 */
	Right,
	/** @brief 文本左对齐 */
	Left
};

/**
 * @brief ZTextBox 类定义
 */
class DLLAPI ZTextBox :
	public ZControl
{
public:
	/**
	 * 实例化一个文本对象
	 *
	 * \param x			x坐标
	 * \param y			y坐标
	 * \param w			宽
	 * \param h			高
	 * \param type		控件样式
	 * \param textStyle 文本格式
	 */
	ZTextBox(int x, int y, int w, int h,
		TextBoxType type = TextBoxType::Normal,
		TextBoxTextStyle textStyle = TextBoxTextStyle::Left);

	/**
	 * 设置控件风格
	 *
	 * \param type		控件样式
	 * \param textStyle 文本格式
	 * \deprecated		最好不要使用该函数
	 */
	void SetStyle(TextBoxType type,
		TextBoxTextStyle textStyle);

	/**
	 * 设置文本框是否可用
	 *
	 * \param enable 是否可用
	 */
	void SetEnable(BOOL enable);

	/**
	 * 重载父控件加载函数
	 *
	 * \param hWnd 父控件句柄
	 */
	void Init(HWND hWnd);
};