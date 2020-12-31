/**
 * \file   ZTextBox.h
 * \brief  文本编辑控件类声明
 *
 * \author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * \date   2020-12-22
 */

#pragma once
#pragma warning(disable:4251)

#include "ZControl.h"

 /**
  * @brief 控件样式枚举
  */
enum class DLLAPI TextBoxStyle {
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
enum class DLLAPI TextBoxTextStyle {
	/** @brief 文本居中 */
	Center,
	/** @brief 文本右对齐 */
	Right,
	/** @brief 文本左对齐 */
	Left
};

/**
 * \brief ZTextBox 类
 *
 * \brief 一个文本框控件类
 *
 * \image html ZTextBox.png
 */
class DLLAPI ZTextBox :
	public ZControl
{
	static ZString type;
	static BOOL isRegistered;

	DWORD style;
	void SetStyle(TextBoxStyle style, TextBoxTextStyle textStyle);

	static std::map<HWND, const ZTextBox*> textBoxList;

	static const ZTextBox* GetTextBox(HWND hWnd);

	static WNDPROC oldProc;

	static LRESULT CALLBACK ConProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	void SetDefFont();

	~ZTextBox();
public:
	/**
	 * \brief 初始化一个文本编辑对象
	 *
	 * \param x			x坐标
	 * \param y			y坐标
	 * \param w			宽
	 * \param h			高
	 * \param style		文本框风格
	 * \param textStyle 文本对其风格
	 */
	ZTextBox(int x, int y, int w, int h, TextBoxStyle style = TextBoxStyle::Normal, TextBoxTextStyle textStyle = TextBoxTextStyle::Left);

	/**
	 * \brief 该函数由窗口调用
	 *
	 * \param hWnd 窗口句柄
	 */
	void Init(HWND hWnd);

	/**
	 * \brief 设置字体
	 *
	 * \param font 目标字体
	 */
	void SetFont(ZFont font);

	/**
	 * \brief 设置文本框是否可用
	 *
	 * \param enable 目标状态
	 */
	void SetEnable(BOOL enable);

	/**
	 * \brief 设置控件文本
	 */
	void SetText(ZString text);

	/**
	 * \brief 获取控件文本
	  *
	 * \return 控件文本
	 */
	ZString GetText();
};
