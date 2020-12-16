/**
 * \file   ZProgressBar.cpp
 * \brief  进度条控件类实现
 *
 * \author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * \date   2020-12-16
 */

#include "ZProgressBar.h"

ZProgressBar::ZProgressBar(int x, int y, int w, int h, UINT min, UINT max, ProgressBarType type)
{
	this->type = L"msctls_progress32";
	rect = { x,y,x + w,y + h };
	this->min = min;
	this->max = max;
	SetStyle(type);
}

void ZProgressBar::SetStyle(ProgressBarType type)
{
	switch (type)
	{
	case ProgressBarType::Normal:
		style = WS_CHILD | WS_VISIBLE;
		break;
	case ProgressBarType::Smooth:
		style = WS_CHILD | WS_VISIBLE | PBS_SMOOTH;
		break;
	case ProgressBarType::NormalV:
		style = WS_CHILD | WS_VISIBLE | PBS_VERTICAL;
		break;
	case ProgressBarType::SmoothV:
		style = WS_CHILD | WS_VISIBLE | PBS_SMOOTH | PBS_VERTICAL;
		break;
	default:
		break;
	}
}

void ZProgressBar::Init(HWND hWnd)
{
	phWnd = hWnd;
	this->hWnd = CreateWindow(
		type,
		NULL,
		style,
		rect.A.x,
		rect.A.y,
		rect.GetSize().w,
		rect.GetSize().h,
		phWnd,
		(HMENU)id,
		(HINSTANCE)GetWindowLong(phWnd, -6),
		NULL
	);
}

UINT ZProgressBar::GetValue()
{
	return (UINT)SendMessage(hWnd, PBM_GETPOS, 0, 0);
}

void ZProgressBar::SetValue(UINT value)
{
	SendMessage(hWnd, PBM_SETPOS, value, 0);
}

ZRange ZProgressBar::GetRange()
{
	PBRANGE range;
	SendMessage(hWnd, PBM_GETRANGE, TRUE, (LPARAM)&range);
	return ZRange(range.iLow, range.iHigh);
}

void ZProgressBar::SetRange(ZRange range)
{
	SendMessage(hWnd, PBM_SETRANGE, 0, MAKELPARAM(range.x1, range.x2));
}

void ZProgressBar::SetRange(UINT min, UINT max)
{
	SendMessage(hWnd, PBM_SETRANGE, 0, MAKELPARAM(min, max));
}