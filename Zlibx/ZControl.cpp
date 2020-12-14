/**
 * \file   ZControl.cpp
 * \brief  控件基类实现
 *
 * \author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * \date   2020-12-15
 */

#include "ZControl.h"

void ZControl::Bind(MessageType type, CallbackFunc func)
{
	ControlFunc confunc{ type,func };
	funcs.push_back(confunc);
}

void ZControl::SetFont(ZFont font)
{
	SendMessage(hWnd, WM_SETFONT, (WPARAM)(HFONT)font, 0);
}

void ZControl::SetDefFont()
{
	ZFont font;
	font.Create(L"新宋体");
	SetFont(font);
}