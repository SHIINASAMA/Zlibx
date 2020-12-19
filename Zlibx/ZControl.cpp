#include "ZControl.h"

LRESULT ZControl::ConProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return LRESULT();
}

ZControl::~ZControl()
{
}

ZControl::ZControl()
{
}

void ZControl::SetFont(ZFont font)
{
	this->font = font;
}

void ZControl::SetDefFont()
{
	SetFont(ZFont(L"ĞÂËÎÌå"));
}