#pragma once

#include <Windows.h>
#include "main.h"
#include "ZString.h"
#include "ZRect.h"
#include "ZFont.h"
#include "ZColor.h"

class DLLAPI ZControl
{
protected:
	HWND hWnd;
	HWND phWnd;

	ZString type;
	ZString text;
	ZRect rect;
	ZFont font;
	ZColor textColol{ 0,0,0 };

	static LRESULT CALLBACK ConProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	~ZControl();
public:
	ZControl();

	virtual void Init(HWND hWnd) = 0;

	void SetFont(ZFont font);

	void SetDefFont();
};
