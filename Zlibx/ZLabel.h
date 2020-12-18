#pragma once

#include "ZControl.h"
#include <map>

class ZLabel :
	public ZControl
{
	ZString type = L"Zlibx_label";
	BOOL isRegistered = FALSE;
	WNDCLASSEX wcex;

	static std::map<HWND, const ZLabel*> labelMap;

	static const ZLabel* GetLabel(HWND hWnd);

	static LRESULT CALLBACK ConProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

public:
	ZLabel(ZString text, int x, int y, int w, int h);

	void Init(HWND hWnd);
};