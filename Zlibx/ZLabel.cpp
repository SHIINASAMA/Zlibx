#include "ZLabel.h"

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
	switch (uMsg)
	{
	case WM_PAINT:
	{
		ZLabel* temp = const_cast<ZLabel*>(GetLabel(hWnd));
		RECT rect = temp->rect;
		HDC hdc;
		PAINTSTRUCT ps;
		hdc = BeginPaint(hWnd, &ps);
		DrawText(hdc, temp->text, -1, &rect, DT_SINGLELINE);
		EndPaint(hWnd, &ps);
		break;
	}
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
		break;
	}
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
			MessageBox(phWnd, L"¿Ø¼þ×¢²áÊ§°Ü", type, MB_OK | MB_ICONERROR);
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

	labelMap.insert(std::pair<HWND, const ZLabel*>(this->hWnd, this));
}