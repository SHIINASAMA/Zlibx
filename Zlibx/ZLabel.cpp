/**
 * \file   ZLabel.cpp
 * \brief  文本控件类定义
 *
 * \author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * \date   2020-12-19
 */

#include "ZLabel.h"

ZString ZLabel::type = L"Zlibx_label";
BOOL ZLabel::isRegistered = FALSE;

std::map<HWND, const ZLabel*> ZLabel::labelMap;

const ZLabel* ZLabel::GetLabel(HWND hWnd)
{
	auto iter = labelMap.find(hWnd);
	if (iter != labelMap.end() && iter->second != NULL)
	{
		return iter->second;
	}
	else
	{
		return nullptr;
	}
}

LRESULT ZLabel::ConProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	ZLabel* temp = const_cast<ZLabel*>(GetLabel(hWnd));
	if (temp != NULL)
	{
		switch (uMsg)
		{
		case WM_PAINT:
		{
			RECT rect = temp->rect;
			HDC hdc;
			PAINTSTRUCT ps;
			hdc = BeginPaint(hWnd, &ps);
			Graphics g(hdc);
			SelectObject(hdc, temp->font);
			SetTextColor(hdc, temp->textColol);
			DrawText(hdc, temp->text, -1, &rect, DT_SINGLELINE);
			EndPaint(hWnd, &ps);
			break;
		}
		default:
			return DefWindowProc(hWnd, uMsg, wParam, lParam);
			break;
		}
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

ZLabel::~ZLabel()
{
	labelMap.erase(hWnd);
}

ZLabel::ZLabel(ZString text, int x, int y, int w, int h)
{
	this->text = text;
	this->rect = RECT{ x,y,x + w,y + h };
}

void ZLabel::Init(HWND hWnd)
{
	if (!isRegistered)
	{
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
		text,
		WS_CHILD | WS_VISIBLE,
		rect.A.x,
		rect.A.y,
		rect.GetSize().w,
		rect.GetSize().h,
		phWnd,
		NULL,
		(HINSTANCE)GetWindowLongPtr(phWnd, GWLP_HINSTANCE),
		NULL
	);

	SetDefFont();
	labelMap.insert(std::pair<HWND, const ZLabel*>(this->hWnd, this));
}

void ZLabel::SetFont(ZFont font)
{
	this->font = font;
}

void ZLabel::SetDefFont()
{
	SetFont(ZFont(L"新宋体"));
}