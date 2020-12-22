/**
 * \file   ZWindow.cpp
 * \brief  窗体类定义
 *
 * \author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * \date   2020-12-19
 */

#include "ZWindow.h"

ZString ZWindow::type = L"Zlibx_window";
BOOL ZWindow::isRegistered = FALSE;

GdiplusStartupInput ZWindow::gdiplusStartupInput;
ULONG_PTR ZWindow::gdiplusToken;
UINT ZWindow::count = 0;

void ZWindow::SetStyle(WindowStyle style)
{
	switch (style)
	{
	case WindowStyle::None:
		this->style = WS_POPUP | WS_VISIBLE | WS_CLIPSIBLINGS | WS_EX_LEFT | WS_EX_LTRREADING | WS_EX_RIGHTSCROLLBAR | WS_EX_CONTROLPARENT | WS_EX_APPWINDOW;
		break;
	case WindowStyle::FixedSingle:
		this->style = WS_CAPTION | WS_VISIBLE | WS_CLIPSIBLINGS | WS_SYSMENU | WS_OVERLAPPED | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_EX_LEFT | WS_EX_LTRREADING | WS_EX_RIGHTSCROLLBAR | WS_EX_WINDOWEDGE | WS_EX_CONTROLPARENT | WS_EX_APPWINDOW;
		break;
	case WindowStyle::Fixed3D:
		this->style = WS_CAPTION | WS_VISIBLE | WS_CLIPSIBLINGS | WS_SYSMENU | WS_OVERLAPPED | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_EX_LEFT | WS_EX_LTRREADING | WS_EX_RIGHTSCROLLBAR | WS_EX_OVERLAPPEDWINDOW | WS_EX_CONTROLPARENT | WS_EX_APPWINDOW;
		break;
	case WindowStyle::FixedDialog:
		this->style = WS_CAPTION | WS_VISIBLE | WS_CLIPSIBLINGS | WS_SYSMENU | WS_OVERLAPPED | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_EX_LEFT | WS_EX_LTRREADING | WS_EX_RIGHTSCROLLBAR | WS_EX_DLGMODALFRAME | WS_EX_WINDOWEDGE | WS_EX_CONTROLPARENT | WS_EX_APPWINDOW;
		break;
	case WindowStyle::Sizable:
		this->style = WS_CAPTION | WS_VISIBLE | WS_CLIPSIBLINGS | WS_SYSMENU | WS_THICKFRAME | WS_OVERLAPPED | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_EX_LEFT | WS_EX_RIGHTSCROLLBAR | WS_EX_WINDOWEDGE | WS_EX_CONTROLPARENT | WS_EX_APPWINDOW;
		break;
	case WindowStyle::FixedToolWindow:
		this->style = WS_CAPTION | WS_VISIBLE | WS_CLIPSIBLINGS | WS_SYSMENU | WS_OVERLAPPED | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_EX_LEFT | WS_EX_LTRREADING | WS_EX_RIGHTSCROLLBAR | WS_EX_TOOLWINDOW | WS_EX_WINDOWEDGE | WS_EX_CONTROLPARENT | WS_EX_APPWINDOW;
		break;
	case WindowStyle::SizableToolWindow:
		this->style = WS_CAPTION | WS_VISIBLE | WS_CLIPSIBLINGS | WS_SYSMENU | WS_THICKFRAME | WS_OVERLAPPED | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_EX_LEFT | WS_EX_LTRREADING | WS_EX_RIGHTSCROLLBAR | WS_EX_TOOLWINDOW | WS_EX_WINDOWEDGE | WS_EX_CONTROLPARENT | WS_EX_APPWINDOW;
		break;
	}
}

LRESULT ZWindow::WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_DESTROY:
		count--;
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
		break;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

ZWindow::~ZWindow()
{
	if (count == 0)
	{
		GdiplusShutdown(gdiplusToken);
	}
}

ZWindow::ZWindow(ZString text, int x, int y, int w, int h, WindowStyle style)
{
	this->text = text;
	this->rect = RECT{ x,y,x + w,y + h };
	SetStyle(style);
}

void ZWindow::Create()
{
	if (!isRegistered)
	{
		hInstance = ::GetModuleHandle(NULL);
		WNDCLASSEX wcex;
		wcex.cbSize = sizeof(WNDCLASSEX);
		wcex.style = CS_HREDRAW | CS_VREDRAW;
		wcex.cbClsExtra = 0;
		wcex.cbWndExtra = 0;
		wcex.hInstance = hInstance;
		wcex.hIcon = NULL;
		wcex.hCursor = NULL;
		wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
		wcex.lpszMenuName = NULL;
		wcex.lpszClassName = type;
		wcex.hIconSm = NULL;
		wcex.lpfnWndProc = WndProc;

		if (!RegisterClassEx(&wcex))
		{
			MessageBox(hWnd, L"控件注册失败", type, MB_OK | MB_ICONERROR);
			return;
		}
		else
		{
			isRegistered = TRUE;
		}
	}

	hWnd = CreateWindow(
		type,
		text,
		style,
		rect.A.x,
		rect.A.y,
		rect.B.x,
		rect.B.y,
		NULL,
		NULL,
		hInstance,
		NULL
	);

	if (count++ == 0)
	{
		GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
	}
}

void ZWindow::Run()
{
	ShowWindow(hWnd, SW_SHOWNORMAL);
	UpdateWindow(hWnd);
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

void ZWindow::Add(ZControl* con)
{
	con->Init(hWnd);
}

void ZWindow::Remove(ZControl* con)
{
	DestroyWindow(hWnd);
}

void ZWindow::ShowCenter()
{
	MONITORINFOEX info;
	info.cbSize = sizeof(MONITORINFOEX);
	GetMonitorInfo(MonitorFromWindow(hWnd, MONITOR_DEFAULTTONEAREST), &info);
	long pw = info.rcMonitor.right - info.rcMonitor.left;
	long ph = info.rcMonitor.bottom - info.rcMonitor.top;
	//printf("x1:%d\ty1:%d\tx2:%d\ty2:%d\n", info.rcWork.left, info.rcWork.top, info.rcWork.right, info.rcWork.bottom);

	RECT rect;
	GetWindowRect(hWnd, &rect);
	long w = rect.right - rect.left;
	long h = rect.bottom - rect.top;
	//printf("w:%d\th:%d\n", w, h);

	long x = info.rcMonitor.left + (pw - w) / 2;
	long y = info.rcMonitor.top + (ph - h) / 2;

	MoveWindow(hWnd, x, y, w, h, TRUE);
}