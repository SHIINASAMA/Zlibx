/**
 * \file   ZButton.cpp
 * \brief  按钮控件类定义
 *
 * \author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * \date   2020-12-20
 */

#include "ZButton.h"
#include "ZDebug.h"

std::map<HWND, const ZButton*> ZButton::buttonMap;

const ZButton* ZButton::GetButton(HWND hWnd)
{
	auto iter = buttonMap.find(hWnd);
	if (iter != buttonMap.end() && iter->second != NULL)
	{
		return iter->second;
	}
	else
	{
		return nullptr;
	}
}

LRESULT ZButton::ConProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	ZButton* temp = const_cast<ZButton*>(GetButton(hWnd));
	switch (uMsg)
	{
	case WM_LBUTTONDOWN:
	case WM_LBUTTONDBLCLK:
	{
		if (temp->func != NULL)
		{
			temp->func(wParam, lParam);
		}
		temp->isPress = TRUE;
		printf("D\n");
		InvalidateRect(hWnd, temp->rect, TRUE);
		break;
	}
	case WM_LBUTTONUP:
	{
		temp->isPress = FALSE;
		printf("U\n");
		InvalidateRect(hWnd, temp->rect, TRUE);
		break;
	}
	case WM_PAINT:
	{
		HDC hdc = (HDC)wParam;
		PAINTSTRUCT ps;
		hdc = BeginPaint(hWnd, &ps);
		SetBkMode(hdc, 1);
		SelectObject(hdc, temp->font);
		SetTextColor(hdc, temp->textColor);

		HPEN Pen = CreatePen(PS_SOLID, 1, RGB(110, 110, 110));
		SelectObject(hdc, Pen);

		Rectangle(hdc,
			temp->rect.A.x,
			temp->rect.A.y,
			temp->rect.B.x - 5,
			temp->rect.B.y - 5
		);

		RECT rect{ temp->rect.A.x + 1,
			temp->rect.A.y + 1,
			temp->rect.B.x - 6,
			temp->rect.B.y - 6
		};

		FillRect(hdc, &rect, CreateSolidBrush(RGB(240, 240, 240)));

		if (!temp->isPress)
		{
			RECT rect = temp->rect;
			OffsetRect(&rect, -3, -3);
			DrawText(hdc, temp->text, -1, &rect, DT_SINGLELINE | DT_VCENTER | DT_CENTER);
		}
		else
		{
			RECT rect = temp->rect;
			OffsetRect(&rect, -2, -2);
			DrawText(hdc, temp->text, -1, &rect, DT_SINGLELINE | DT_VCENTER | DT_CENTER);
		}
		EndPaint(hWnd, &ps);
		break;
	}
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
		break;
	}
}

void ZButton::SetDefFont()
{
	this->font = ZFont(L"新宋体");
}

ZButton::~ZButton()
{
	buttonMap.erase(hWnd);
}

ZButton::ZButton(ZString text, int x, int y, int w, int h)
{
	this->text = text;
	this->rect = RECT{ x,y,x + w,y + h };
}

void ZButton::Init(HWND hWnd)
{
	if (!isRegistered)
	{
		WNDCLASSEX wcex{ 0 };
		wcex.cbSize = sizeof(WNDCLASSEX);
		wcex.lpfnWndProc = ConProc;
		wcex.hInstance = (HINSTANCE)GetWindowLong(hWnd, GWLP_HINSTANCE);
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
		(HINSTANCE)GetWindowLong(phWnd, GWLP_HINSTANCE),
		NULL
	);

	SetDefFont();
	buttonMap.insert(std::pair<HWND, const ZButton*>(this->hWnd, this));
}

void ZButton::Bind(CallBackFunc func)
{
	this->func = func;
}

void ZButton::SetFont(ZFont font)
{
	this->font = font;
}

void ZButton::SetTextColor(ZColor color)
{
	this->textColor = color;
}