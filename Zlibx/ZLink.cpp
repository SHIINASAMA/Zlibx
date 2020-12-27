/**
 * \file   ZLink.cpp
 * \brief  链接控件类定义
 *
 * \author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * \date   2020-12-27
 */

#include "ZLink.h"
#include "ZDebug.h"

ZString ZLink::type = L"Zlibx_link";
BOOL ZLink::isRegistered = FALSE;

std::map<HWND, const ZLink*> ZLink::linkList;

const ZLink* ZLink::GetLink(HWND hWnd)
{
	auto itor = linkList.find(hWnd);
	if (itor != linkList.end() && itor->second != NULL)
	{
		return itor->second;
	}
	else
	{
		return nullptr;
	}
}

LRESULT ZLink::ConProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	ZLink* temp = const_cast<ZLink*>(GetLink(hWnd));
	if (temp != NULL)
	{
		switch (uMsg)
		{
		case WM_PAINT:
		{
			HDC hdc;
			PAINTSTRUCT ps;
			hdc = BeginPaint(hWnd, &ps);
			Graphics g(hdc);
			SelectObject(hdc, temp->font);
			::SetTextColor(hdc, temp->textColor);
			DrawText(hdc, temp->text, -1, temp->rect.ToClientRect(), DT_SINGLELINE | DT_CENTER | DT_VCENTER);
			EndPaint(hWnd, &ps);
			break;
		}
		case WM_LBUTTONDOWN:
		{
			temp->textColor = ZColor(236, 65, 65);
			InvalidateRect(hWnd, temp->rect.ToClientRect(), TRUE);
			break;
		}
		case WM_LBUTTONUP:
		{
			temp->textColor = ZColor(83, 150, 206);
			InvalidateRect(hWnd, temp->rect.ToClientRect(), TRUE);
			ShellExecute(hWnd, L"open", temp->url, NULL, NULL, FALSE);
			break;
		}
		case WM_SIZE:
		case WM_MOVE:
		{
			UpdateRect(temp);
			break;
		}
		default:
		{
			return DefWindowProc(hWnd, uMsg, wParam, lParam);
			break;
		}
		}
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

void ZLink::SetDefFont()
{
	font.CreateEx(
		-15,
		0,
		0,
		0,
		0,
		TRUE,
		TRUE,
		FALSE,
		GB2312_CHARSET,
		OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY,
		DEFAULT_PITCH,
		L"新宋体"
	);
}

ZLink::~ZLink()
{
	linkList.erase(hWnd);
}

ZLink::ZLink(ZString text, ZString url, int x, int y, int w, int h)
{
	this->text = text;
	this->url = url;
	this->rect = RECT{ x,y,x + w,y + h };
}

void ZLink::Init(HWND hWnd)
{
	auto hInstance = (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE);
	if (!isRegistered)
	{
		WNDCLASSEX wcex{ 0 };
		wcex.cbSize = sizeof(WNDCLASSEX);
		wcex.lpfnWndProc = ConProc;
		wcex.hInstance = hInstance;
		wcex.cbClsExtra = 0;
		wcex.cbWndExtra = 0;
		wcex.hIcon = NULL;
		wcex.hIconSm = NULL;
		wcex.hbrBackground = NULL;
		wcex.hCursor = LoadCursor(NULL, IDC_HAND);
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
		hInstance,
		NULL
	);

	SetDefFont();
	linkList.insert(std::pair<HWND, const ZLink*>(this->hWnd, this));
}

void ZLink::SetText(ZString text)
{
	this->text = text;
	InvalidateRect(hWnd, this->rect.ToClientRect(), TRUE);
}

ZString ZLink::GetText()
{
	return this->text;
}

void ZLink::SetUrl(ZString url)
{
	this->url = url;
}

ZString ZLink::GetUrl()
{
	return this->url;
}