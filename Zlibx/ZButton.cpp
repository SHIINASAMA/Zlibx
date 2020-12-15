#include "ZButton.h"

ZButton::ZButton(ZString text, int x, int y, int w, int h)
{
	type = L"button";
	style = WS_CHILD | WS_VISIBLE;
	this->text = text;
	rect = RECT{ x,y,x + w,y + h };
}

void ZButton::Init(HWND hWnd)
{
	phWnd = hWnd;
	this->hWnd = CreateWindow(
		type,
		text,
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

	SetDefFont();
}