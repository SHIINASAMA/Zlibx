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
	font.Create(L"ÐÂËÎÌå");
	SetFont(font);
}