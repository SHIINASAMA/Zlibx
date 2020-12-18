#pragma once

#include <Windows.h>
#include "main.h"
#include "ZString.h"
#include "ZRect.h"

class DLLAPI ZControl
{
	HWND hWnd;
	HWND phWnd;

	ZString type;
	ZString text;
	ZRect rect;
	DWORD style;

	virtual void Init(HWND hWnd) = 0;

	static LRESULT CALLBACK ConProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
};
