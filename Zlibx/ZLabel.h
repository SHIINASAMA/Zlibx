/**
 * \file   ZLabel.h
 * \brief  文本控件类声明
 *
 * \author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * \date   2020-12-19
 */

#pragma once

#include "ZControl.h"
#include <map>

 /**
  * \brief ZLabel 类
  */
class ZLabel :
	public ZControl
{
	ZString type = L"Zlibx_label";
	BOOL isRegistered = FALSE;
	WNDCLASSEX wcex;

	ZString text;
	ZFont font;
	ZColor textColol{ 0,0,0 };

	static std::map<HWND, const ZLabel*> labelMap;

	static const ZLabel* GetLabel(HWND hWnd);

	static LRESULT CALLBACK ConProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	void SetDefFont();

	~ZLabel();

public:
	/**
	 * 初始化一个文本控件对象
	 *
	 * \param text	文本内容
	 * \param x		x坐标
	 * \param y		y坐标
	 * \param w		宽
	 * \param h		高
	 */
	ZLabel(ZString text, int x, int y, int w, int h);

	/**
	 * 该函数由窗口调用
	 *
	 * \param hWnd 窗口句柄
	 */
	void Init(HWND hWnd);

	/**
	 * 设置字体
	 *
	 * \param font 目标字体
	 */
	void SetFont(ZFont font);
};