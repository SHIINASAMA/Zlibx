/**
 * \file   ZListBox.h
 * \brief  列表控件类声明
 *
 * \author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * \date   2020-12-31
 */

#pragma once
#pragma warning(disable: 4251)
#include "ZControl.h"

 /**
  * \brief ZListBox 类
  *
  * \brief 一个列表控件类
  *
  * \image html ZListBox.png
  */
class DLLAPI ZListBox :
	public ZControl
{
	static ZString type;
	static BOOL isRegistered;

	static std::map<HWND, ZListBox*> listBoxList;
	static ZListBox* GetListBox(HWND hWnd);

	static WNDPROC oldProc;
	static LRESULT CALLBACK ConProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	void SetDefFont();

	void SetFont(ZFont font);

	~ZListBox();
public:
	/**
	 * \brief 初始化一个列表控件对象
	 *
	 * \param x	x坐标
	 * \param y	y坐标
	 * \param w	宽
	 * \param h	高
	 */
	ZListBox(int x, int y, int w, int h);

	/**
	 * \brief 该函数由窗口调用
	 *
	 * \param hWnd 窗口句柄
	 */
	void Init(HWND hWnd);

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
