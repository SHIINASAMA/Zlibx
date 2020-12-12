/**
 * @file   ZWindow.cpp
 * @brief  窗体类实现
 *
 * @author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * @date   2020-12-11
 */

#include "ZWindow.h"

static LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	//TODO:实现ID映射
	switch (uMsg)
	{
	case WM_CTLCOLORSTATIC:
	{
		HDC dc = (HDC)wParam;
		SetBkMode(dc, TRANSPARENT);
		return (LRESULT)GetStockObject(NULL_BRUSH);
		break;
	}
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		break;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

ZWindow::ZWindow(ZString text, WindowType type)
{
	this->text = text;
	SetWindowType(type);
}

ZWindow::ZWindow(ZString text, int x, int y, int w, int h, WindowType type)
{
	this->text = text;
	this->rect = ZRect(x, y, x + w, y + h);
	SetWindowType(type);
}

void ZWindow::SetWindowType(WindowType type)
{
	switch (type)
	{
	case None:
		style = WS_POPUP | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_EX_LEFT | WS_EX_LTRREADING | WS_EX_RIGHTSCROLLBAR | WS_EX_CONTROLPARENT | WS_EX_APPWINDOW;
		break;
	case FixedSingle:
		style = WS_CAPTION | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_SYSMENU | WS_OVERLAPPED | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_EX_LEFT | WS_EX_LTRREADING | WS_EX_RIGHTSCROLLBAR | WS_EX_WINDOWEDGE | WS_EX_CONTROLPARENT | WS_EX_APPWINDOW;
		break;
	case Fixed3D:
		style = WS_CAPTION | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_SYSMENU | WS_OVERLAPPED | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_EX_LEFT | WS_EX_LTRREADING | WS_EX_RIGHTSCROLLBAR | WS_EX_OVERLAPPEDWINDOW | WS_EX_CONTROLPARENT | WS_EX_APPWINDOW;
		break;
	case FixedDialog:
		style = WS_CAPTION | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_SYSMENU | WS_OVERLAPPED | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_EX_LEFT | WS_EX_LTRREADING | WS_EX_RIGHTSCROLLBAR | WS_EX_DLGMODALFRAME | WS_EX_WINDOWEDGE | WS_EX_CONTROLPARENT | WS_EX_APPWINDOW;
		break;
	case Sizable:
		style = WS_CAPTION | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_SYSMENU | WS_THICKFRAME | WS_OVERLAPPED | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_EX_LEFT | WS_EX_RIGHTSCROLLBAR | WS_EX_WINDOWEDGE | WS_EX_CONTROLPARENT | WS_EX_APPWINDOW;
		break;
	case FixedToolWindow:
		style = WS_CAPTION | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_SYSMENU | WS_OVERLAPPED | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_EX_LEFT | WS_EX_LTRREADING | WS_EX_RIGHTSCROLLBAR | WS_EX_TOOLWINDOW | WS_EX_WINDOWEDGE | WS_EX_CONTROLPARENT | WS_EX_APPWINDOW;
		break;
	case SizableToolWindow:
		style = WS_CAPTION | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_SYSMENU | WS_THICKFRAME | WS_OVERLAPPED | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_EX_LEFT | WS_EX_LTRREADING | WS_EX_RIGHTSCROLLBAR | WS_EX_TOOLWINDOW | WS_EX_WINDOWEDGE | WS_EX_CONTROLPARENT | WS_EX_APPWINDOW;
		break;
	default:
		break;
	}
}

HANDLE ZWindow::Init(HANDLE handle)
{
	return NULL;
}

ZWindow::~ZWindow()
{
	if (this->handle != NULL && ::IsWindow((HWND)handle))
	{
		::DestroyWindow((HWND)handle);
	}
}

void ZWindow::Create()
{
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = ::GetModuleHandle(NULL);
	wcex.hIcon = NULL;
	wcex.hCursor = NULL;
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = L"Zlibx_Window";
	wcex.hIconSm = NULL;
	wcex.lpfnWndProc = WndProc;
	RegisterClassEx(&wcex);

	handle = CreateWindow(
		wcex.lpszClassName,
		text,
		style,
		rect.A.x,
		rect.A.y,
		rect.B.x,
		rect.B.y,
		NULL,
		NULL,
		wcex.hInstance,
		NULL
	);
}

void ZWindow::Run()
{
	ShowWindow((HWND)handle, SW_SHOWNORMAL);
	UpdateWindow((HWND)handle);
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

//TODO:测试添加控件函数
void ZWindow::AddControl(ZControl* con)
{
	HANDLE h = con->Init(handle);
}

//TODO:实现移除控件函数
void ZWindow::RemoveControl(DWORDLONG id)
{
}