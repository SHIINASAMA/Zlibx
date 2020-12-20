/**
 * \file   ZButton.h
 * \brief  按钮控件类定义
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
	WNDCLASSEX wcex = { 0 };

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
	ZButton(ZString text, int x, int y, int w, int h);

	void Init(HWND hWnd);

	void Bind(CallBackFunc func);

	void SetFont(ZFont font);
};
