/**
 * \file   ZProgressBar.cpp
 * \brief  进度条控件类定义
 *
 * \author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * \date   2021-01-01
 */

#include "ZProgressBar.h"

ZString ZProgressBar::type = L"Zlibx_progessBar";
BOOL ZProgressBar::isRegistered = FALSE;

std::map<HWND, ZProgressBar*> ZProgressBar::progressBarList;

ZProgressBar* ZProgressBar::GetProgressBar(HWND hWnd)
{
	auto itor = progressBarList.find(hWnd);
	if (itor != progressBarList.end())
	{
		return itor->second;
	}
	else
	{
		return nullptr;
	}
}

LRESULT ZProgressBar::ConProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	auto temp = GetProgressBar(hWnd);
	if (temp != NULL)
	{
		RECT rect = temp->rect.ToClientRect();
		switch (uMsg)
		{
		case WM_PAINT:
		{
			temp->SetVisible(FALSE);
			temp->SetVisible(TRUE);
			int w = temp->rect.GetWidth();
			int h = temp->rect.GetHeight();
			float progress = (float)temp->pos / (temp->range.x2 - temp->range.x1);
			int sw = progress * w;
			PAINTSTRUCT ps;
			HDC hdc = BeginPaint(hWnd, &ps);
			Graphics g(hdc);

			//绘制矩形
			SolidBrush bkBrush(Color(74, 200, 176));
			g.FillRectangle(&bkBrush, 0, 0, sw, h);
			//绘制文本
			SetBkMode(hdc, TRANSPARENT);
			SelectObject(hdc, temp->font);
			WChar str[16];
			wsprintf(str, L"%d%%", (int)(progress * 100));
			DrawText(hdc, str, -1, &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

			EndPaint(hWnd, &ps);
			break;
		}
		case WM_SIZE:
		case WM_MOVE:
		{
			UpdateRect(temp);
			break;
		}
		case WM_DESTROY:
		{
			temp->~ZProgressBar();
			break;
		}
		default:
			return DefWindowProc(hWnd, uMsg, wParam, lParam);
			break;
		}
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

ZProgressBar::~ZProgressBar()
{
	progressBarList.erase(hWnd);
}

ZProgressBar::ZProgressBar(int x, int y, int w, int h)
{
	this->rect = RECT{ x,y,x + w,y + h };
}

void ZProgressBar::SetValue(int pos)
{
	this->pos = pos;
	InvalidateRect(hWnd, rect.ToClientRect(), TRUE);
}

int ZProgressBar::GetValue()
{
	return pos;
}

void ZProgressBar::MakeStep()
{
	if (pos != range.x2)
	{
		pos++;
		InvalidateRect(hWnd, rect.ToClientRect(), TRUE);
	}
}

void ZProgressBar::Init(HWND hWnd)
{
	auto hInstance = (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE);
	if (!isRegistered)
	{
		WNDCLASSEX wcex{ 0 };
		wcex.cbSize = sizeof(WNDCLASSEX);
		wcex.hInstance = hInstance;
		wcex.cbClsExtra = 0;
		wcex.cbWndExtra = 0;
		wcex.hIcon = NULL;
		wcex.hIconSm = NULL;
		wcex.hbrBackground = NULL;
		wcex.hCursor = NULL;
		wcex.lpszMenuName = NULL;
		wcex.lpszClassName = type;
		wcex.lpfnWndProc = ConProc;

		if (!RegisterClassEx(&wcex))
		{
			MessageBox(phWnd, L"控件注册失败", type, MB_OK | MB_ICONERROR);
			return;
		}
		else
		{
			isRegistered = TRUE;
		}
	}

	phWnd = hWnd;
	this->hWnd = CreateWindow(
		type,
		NULL,
		WS_BORDER | WS_CHILD | WS_VISIBLE,
		rect.A.x,
		rect.A.y,
		rect.GetWidth(),
		rect.GetHeight(),
		phWnd,
		NULL,
		hInstance,
		NULL
	);

	font.Create(L"新宋体");
	progressBarList.insert(std::pair<HWND, ZProgressBar*>(this->hWnd, this));
}