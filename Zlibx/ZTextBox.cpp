/**
 * \file   ZTextBox.cpp
 * \brief  文本编辑控件类定义
 *
 * \author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * \date   2020-12-22
 */

#include "ZTextBox.h"

void ZTextBox::SetStyle(TextBoxStyle style, TextBoxTextStyle textStyle)
{
	switch (style)
	{
	case TextBoxStyle::Normal:
		this->style = WS_CHILD | WS_VISIBLE | WS_BORDER;
		break;
	case TextBoxStyle::MultiV:
		this->style = WS_CHILD | WS_VISIBLE | WS_BORDER | ES_MULTILINE | WS_VSCROLL;
		break;
	case TextBoxStyle::Multi:
		this->style = WS_CHILD | WS_VISIBLE | WS_BORDER | ES_MULTILINE | WS_VSCROLL | WS_HSCROLL;
		break;
	case TextBoxStyle::Num:
		this->style = WS_CHILD | WS_VISIBLE | WS_BORDER | ES_NUMBER;
		break;
	case TextBoxStyle::Pwd:
		this->style = WS_CHILD | WS_VISIBLE | WS_BORDER | ES_PASSWORD;
		break;
	default:
		break;
	}

	switch (textStyle)
	{
	case TextBoxTextStyle::Center:
		this->style |= ES_CENTER;
		break;
	case TextBoxTextStyle::Right:
		this->style |= ES_RIGHT;
		break;
	case TextBoxTextStyle::Left:
		this->style |= ES_LEFT;
		break;
	default:
		break;
	}
}

ZTextBox::ZTextBox(int x, int y, int w, int h, TextBoxStyle style, TextBoxTextStyle textStyle)
{
	this->rect = RECT{ x,y,x + w,y + h };
	SetStyle(style, textStyle);
}

void ZTextBox::Init(HWND hWnd)
{
	phWnd = hWnd;
	this->hWnd = CreateWindow(
		type,
		L"",
		style,
		rect.A.x,
		rect.A.y,
		rect.B.x - rect.A.x,
		rect.B.y - rect.A.y,
		phWnd,
		NULL,
		(HINSTANCE)GetWindowLongPtr(phWnd, GWLP_HINSTANCE),
		NULL
	);

	SetDefFont();
}

void ZTextBox::SetFont(ZFont font)
{
	SendMessage(hWnd, WM_SETFONT, (WPARAM)(HFONT)font, 0);
}

void ZTextBox::SetDefFont()
{
	SetFont(ZFont(L"新宋体"));
}

void ZTextBox::SetEnable(BOOL enable)
{
	SendMessage(hWnd, EM_SETREADONLY, !enable, 0);
}