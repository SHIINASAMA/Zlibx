/**
 * \file   ZWindow.cpp
 * \brief  窗体类实现
 *
 * \author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * \date   2020-12-15
 */

#include "ZWindow.h"

UINT ZWindow::conut = 0;

//std::map<HANDLE, ZControl> ZWindow::controlMap;

std::map<UINT, ControlFunc> ZWindow::ClickedFuncs;

ZWindow::ZWindow(ZString text, WindowType type)
{
	this->text = text;
	SetWindowType(type);
}

ZWindow::ZWindow(ZString text, int x, int y, int w, int h, WindowType type)
{
	this->text = text;
	this->rect = RECT{ x,y,x + w,y + h };
	SetWindowType(type);
}

void ZWindow::SetWindowType(WindowType type)
{
	switch (type)
	{
	case WindowType::None:
		style = WS_POPUP | WS_VISIBLE | WS_CLIPSIBLINGS | WS_EX_LEFT | WS_EX_LTRREADING | WS_EX_RIGHTSCROLLBAR | WS_EX_CONTROLPARENT | WS_EX_APPWINDOW;
		break;
	case WindowType::FixedSingle:
		style = WS_CAPTION | WS_VISIBLE | WS_CLIPSIBLINGS | WS_SYSMENU | WS_OVERLAPPED | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_EX_LEFT | WS_EX_LTRREADING | WS_EX_RIGHTSCROLLBAR | WS_EX_WINDOWEDGE | WS_EX_CONTROLPARENT | WS_EX_APPWINDOW;
		break;
	case WindowType::Fixed3D:
		style = WS_CAPTION | WS_VISIBLE | WS_CLIPSIBLINGS | WS_SYSMENU | WS_OVERLAPPED | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_EX_LEFT | WS_EX_LTRREADING | WS_EX_RIGHTSCROLLBAR | WS_EX_OVERLAPPEDWINDOW | WS_EX_CONTROLPARENT | WS_EX_APPWINDOW;
		break;
	case WindowType::FixedDialog:
		style = WS_CAPTION | WS_VISIBLE | WS_CLIPSIBLINGS | WS_SYSMENU | WS_OVERLAPPED | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_EX_LEFT | WS_EX_LTRREADING | WS_EX_RIGHTSCROLLBAR | WS_EX_DLGMODALFRAME | WS_EX_WINDOWEDGE | WS_EX_CONTROLPARENT | WS_EX_APPWINDOW;
		break;
	case WindowType::Sizable:
		style = WS_CAPTION | WS_VISIBLE | WS_CLIPSIBLINGS | WS_SYSMENU | WS_THICKFRAME | WS_OVERLAPPED | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_EX_LEFT | WS_EX_RIGHTSCROLLBAR | WS_EX_WINDOWEDGE | WS_EX_CONTROLPARENT | WS_EX_APPWINDOW;
		break;
	case WindowType::FixedToolWindow:
		style = WS_CAPTION | WS_VISIBLE | WS_CLIPSIBLINGS | WS_SYSMENU | WS_OVERLAPPED | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_EX_LEFT | WS_EX_LTRREADING | WS_EX_RIGHTSCROLLBAR | WS_EX_TOOLWINDOW | WS_EX_WINDOWEDGE | WS_EX_CONTROLPARENT | WS_EX_APPWINDOW;
		break;
	case WindowType::SizableToolWindow:
		style = WS_CAPTION | WS_VISIBLE | WS_CLIPSIBLINGS | WS_SYSMENU | WS_THICKFRAME | WS_OVERLAPPED | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_EX_LEFT | WS_EX_LTRREADING | WS_EX_RIGHTSCROLLBAR | WS_EX_TOOLWINDOW | WS_EX_WINDOWEDGE | WS_EX_CONTROLPARENT | WS_EX_APPWINDOW;
		break;
	default:
		break;
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

	hWnd = CreateWindow(
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
	ShowWindow(hWnd, SW_SHOWNORMAL);
	UpdateWindow(hWnd);
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

DialogResult ZWindow::RunDialog()
{
	return DialogResult::Ok;
}

LRESULT ZWindow::WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_COMMAND:
	{
		auto iter = ClickedFuncs.find(wParam);
		iter->second.func(Param{ hWnd,uMsg,wParam,lParam });
		break;
	}
	case WM_CTLCOLORSTATIC:
	{
		SetBkMode((HDC)wParam, TRANSPARENT);
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

void ZWindow::AddControl(ZControl* con)
{
	con->id = WM_USER + (++conut);
	con->Init(hWnd);

	//将控件的回调函数添加到引用中
	for (auto iter : con->funcs)
	{
		switch (iter.type)
		{
		case MessageType::Clicked:
			ClickedFuncs.insert(std::pair<UINT, ControlFunc>(con->id, iter));
			break;
			//TODO:在这里添加其他消息的回调函数
		default:
			break;
		}
	}
}

void ZWindow::RemoveControl(ZControl* con)
{
	//清除控件的回调函数
	for (auto iter : con->funcs)
	{
		switch (iter.type)
		{
		case MessageType::Clicked:
			ClickedFuncs.erase(con->id);
			break;
			//TODO:在这里删除其他消息的回调函数
		default:
			break;
		}
	}
}