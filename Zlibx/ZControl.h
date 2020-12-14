#pragma once

#include <Windows.h>
#include <map>
#include <vector>
#include "main.h"
#include "ZFont.h"
#include "ZRect.h"

enum class MessageType
{
	Clicked,
};

typedef struct Param
{
	HWND hWnd;
	UINT uMsg;
	WPARAM wParam;
	LPARAM lParam;
}Param;

typedef LRESULT(*CallbackFunc)(Param);

typedef struct ControlFunc
{
	MessageType type;
	CallbackFunc func;
}ControlFunc;

class DLLAPI ZControl
{
protected:
	HWND hWnd;

public:
	UINT id;
	std::vector<ControlFunc> funcs;
	virtual void Init(HWND hWnd) = 0;
	void Bind(MessageType type, CallbackFunc func);

	void SetFont(ZFont font);
	void SetDefFont();
};
