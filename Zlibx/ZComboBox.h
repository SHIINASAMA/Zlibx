/**
 * \file   ZComboBox.h
 * \brief  下拉框控件类声明
 *
 * \author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * \date   2020-12-29
 */

#pragma once
#pragma warning(disable: 4251)

#include "ZControl.h"

 /**
  * \brief 下拉框风格
  */
enum class DLLAPI ComboBoxStyle
{
	/**
	 * \brief 可输入文本或在下拉列表中选择
	 */
	DropDown,
	/**
	 * \brief 可输入文本或在列表中选择，列表框一直显示
	 */
	 Simple,
	 /**
	  * \brief 只能在下拉列表中选择
	  */
	  DropDownList
};

/**
 * \brief ZComboBox 类
 *
 * \brief 一个下拉栏控件类
 *
 * \image html ZComboBox.png
 */
class DLLAPI ZComboBox :
	public ZControl
{
	static ZString type;
	static BOOL isRegistered;

	static std::map<HWND, ZComboBox*> comboBoxList;
	static ZComboBox* GetComboBox(HWND hWnd);

	ZFont font;
	void SetDefFont();

	DWORD style;
	void SetStyle(ComboBoxStyle style);
public:
	/**
	 * \brief 初始化一个下拉框控件
	 *
	 * \param x		x坐标
	 * \param y		y坐标
	 * \param w		宽
	 * \param h		高
	 * \param style 控件风格
	 */
	ZComboBox(int x, int y, int w, int h, ComboBoxStyle style = ComboBoxStyle::DropDownList);

	/**
	 * 该函数由窗口调用
	 *
	 * \param hWnd 窗口句柄
	 */
	void Init(HWND hWnd);

	/**
	 * \brief 设置控件字体
	 *
	 * \param font 目标字体
	 */
	void SetFont(ZFont font);

	/**
	 * \brief 添加项
	 *
	 * \param text 项文本
	 */
	void AddItem(ZString text);

	/**
	 * \brief 移除项
	 *
	 * \param pos 项索引
	 */
	void RemoveAt(UINT pos);

	/**
	 * \brief 查找项
	 *
	 * \param text 项文本
	 * \return
	 */
	int Find(ZString text);

	//void Update(UINT pos, ZString text);

	/**
	 * \brief		插入项
	 *
	 * \param pos	目标位置索引
	 * \param text	项文本
	 */
	void Insert(UINT pos, ZString text);

	/**
	 * \brief		获取项文本
	 *
	 * \param pos	位置索引
	 * \return		文本
	 */
	ZString GetText(UINT pos);

	/**
	 * \brief		设置当前索引值
	 *
	 * \param index 索引值
	 */
	void SetSelectedIndex(UINT index);

	/**
	 * \brief		获取当前索引值
	 *
	 * \return		当前缩影值
	 */
	UINT GetSelectedIndex();

	/**
	 * \brief 移除所有项
	 *
	 */
	void RemoveAll();

	/**
	 * \brief 获取当前项总数
	 *
	 * \return 项总数
	 */
	UINT Count();
};
