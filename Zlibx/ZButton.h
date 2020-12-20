/**
 * \file   ZButton.h
 * \brief  按钮控件类声明
 *
 * \author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * \date   2020-12-19
 */
#pragma once
#include "ZControl.h"
#include <map>
class ZButton :
	public ZControl
{
	ZString type = L"Zlibx_button";
	BOOL isRegistered = FALSE;

	ZString text;
	ZFont font;
	ZColor textColor{ 0,0,0 };
	BOOL isPress = FALSE;

	CallBackFunc func;

	static std::map<HWND, const ZButton*> buttonMap;

	static const ZButton* GetButton(HWND hWnd);

	static LRESULT CALLBACK ConProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	void SetDefFont();

	~ZButton();

public:
	/**
	 * 初始化一个按钮对象
	 *
	 * \param text	按钮文本
	 * \param x		x坐标
	 * \param y		y坐标
	 * \param w		宽
	 * \param h		高
	 */
	ZButton(ZString text, int x, int y, int w, int h);

	/**
	 * 该函数由窗口调用
	 *
	 * \param hWnd 窗口句柄
	 */
	void Init(HWND hWnd);

	/**
	 * 绑定回调函数
	 *
	 * \param func 目标函数
	 */
	void Bind(CallBackFunc func);

	/**
	 * 设置字体
	 *
	 * \param font 目标字体
	 */
	void SetFont(ZFont font);

	/**
	 * 设置字体颜色
	 *
	 * \param color 目标颜色
	 */
	void SetTextColor(ZColor color);
};
