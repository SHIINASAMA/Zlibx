/**
 * \file   ZPictureBox.cpp
 * \brief  图片控件类定义
 *
 * \author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * \date   2020-12-24
 */

#include "ZPictureBox.h"

std::map<HWND, const ZPictureBox*> ZPictureBox::pictureBoxList;

const ZPictureBox* ZPictureBox::GetPictureBox(HWND hWnd)
{
	auto itor = pictureBoxList.find(hWnd);
	if (itor != pictureBoxList.end() && itor->second != NULL)
	{
		return itor->second;
	}
	else
	{
		return nullptr;
	}
}

LRESULT ZPictureBox::ConProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	ZPictureBox* temp = const_cast<ZPictureBox*>(GetPictureBox(hWnd));
	if (temp != NULL)
	{
		if (uMsg == WM_PAINT && temp->hasImage == TRUE)
		{
			PAINTSTRUCT ps;
			HDC hdc = BeginPaint(hWnd, &ps);
			HDC hdcmem = CreateCompatibleDC(hdc);
			BITMAP bmp = temp->bmp;
			SelectObject(hdcmem, temp->bmp);
			switch (temp->mode)
			{
			case DisplayMode::None:
			{
				LONG w = temp->rect.GetWidth(), h = temp->rect.GetHeight();
				if (bmp.bmWidth < temp->rect.GetWidth())
					w = bmp.bmWidth;
				if (bmp.bmHeight < temp->rect.GetHeight())
					h = bmp.bmHeight;
				BitBlt(hdc, 0, 0, w, h, hdcmem, 0, 0, SRCCOPY);
				break;
			}
			case DisplayMode::Stretch:
			{
				SetStretchBltMode(hdc, HALFTONE);
				StretchBlt(hdc, 0, 0, temp->rect.GetWidth(), temp->rect.GetHeight(), hdcmem, 0, 0, bmp.bmWidth, bmp.bmHeight, SRCCOPY);
				break;
			}
			case DisplayMode::Zoom:
			{
				SetStretchBltMode(hdc, HALFTONE);

				int w = temp->rect.GetWidth();
				int h = temp->rect.GetHeight();

				double con = (double)w / h;
				double pic = (double)bmp.bmWidth / (double)bmp.bmHeight;

				if (con >= 1)
				{
					LONG x = pic * h;
					x = (w - x) / 2;
					StretchBlt(hdc, x, 0, w - 2 * x, h, hdcmem, 0, 0, bmp.bmWidth, bmp.bmHeight, SRCCOPY);
				}
				else
				{
					LONG y = w / pic;
					y = (h - y) / 2;
					StretchBlt(hdc, 0, y, w, h - 2 * y, hdcmem, 0, 0, bmp.bmWidth, bmp.bmHeight, SRCCOPY);
				}
				break;
			}
			default:
				break;
			}
			DeleteDC(hdcmem);
			EndPaint(hWnd, &ps);
		}
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

ZPictureBox::ZPictureBox(int x, int y, int w, int h, DisplayMode mode)
{
	this->rect = RECT{ x, y, x + w, y + h };
	this->mode = mode;
}

void ZPictureBox::Init(HWND hWnd)
{
	if (!isRegistered)
	{
		WNDCLASSEX wcex = { 0 };
		wcex.cbSize = sizeof(WNDCLASSEX);
		wcex.lpfnWndProc = ConProc;
		wcex.hInstance = (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE);
		wcex.cbClsExtra = 0;
		wcex.cbWndExtra = 0;
		wcex.hIcon = NULL;
		wcex.hIconSm = NULL;
		wcex.hbrBackground = NULL;
		wcex.hCursor = NULL;
		wcex.lpszMenuName = NULL;
		wcex.lpszClassName = type;

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
		L"",
		WS_CHILD | WS_VISIBLE | WS_BORDER,
		rect.A.x,
		rect.A.y,
		rect.GetWidth(),
		rect.GetHeight(),
		phWnd,
		NULL,
		(HINSTANCE)GetWindowLongPtr(phWnd, GWLP_HINSTANCE),
		NULL
	);

	pictureBoxList.insert(std::pair<HWND, const ZPictureBox*>(this->hWnd, this));
}

void ZPictureBox::SetImage(ZBitmap bmp)
{
	this->hasImage = TRUE;
	this->bmp = bmp;
	RECT rect;
	GetClientRect(hWnd, &rect);
	InvalidateRect(hWnd, &rect, TRUE);
}

void ZPictureBox::ClearIamge()
{
	this->hasImage = FALSE;
	this->bmp = nullptr;
	RECT rect;
	GetClientRect(hWnd, &rect);
	InvalidateRect(hWnd, &rect, TRUE);
}