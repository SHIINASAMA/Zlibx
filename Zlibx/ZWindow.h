/**
 * \file   ZWindow.h
 * \brief  窗体类定义
 *
 * \author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * \date   2020-12-14
 */

#pragma once

#include "ZControl.h"

 /** @brief 窗体类型枚举
 */
enum class DLLAPI WindowType
{
	/**@brief 无边框*/
	None,
	/**@brief 固定的单行边框*/
	FixedSingle,
	/**@brief 固定的三维边框*/
	Fixed3D,
	/**@brief 固定的对话框样式的粗边框*/
	FixedDialog,
	/**@brief 可调整大小的边框*/
	Sizable,
	/**@brief 不可调整大小的工具窗口边框*/
	FixedToolWindow,
	/**@brief 可调整大小的工具窗口边框*/
	SizableToolWindow,
};

/**
 * @brief 窗体返回值类型
 */
enum class DialogResult {
	Ok,
	No
};

class DLLAPI ZWindow
{
protected:
	HWND hWnd;

	ZString text;
	DWORD style;
	ZRect rect;

	static UINT conut;
	//static std::map<HANDLE, ZControl> controlMap;
	static LRESULT WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	static std::map<UINT, ControlFunc> ClickedFuncs;

public:
	ZWindow(ZString text,
		WindowType type = WindowType::Sizable);

	ZWindow(ZString text,
		int x, int y, int w, int h,
		WindowType type = WindowType::Sizable);

	/**	@brief 设置窗体风格
	*	\deprecated 该函数最好是让框架自己调用，用户也可以自己在Create函数运行前调用该函数
	*/
	void SetWindowType(WindowType type);

	void Create();
	void Run();
	DialogResult RunDialog();

	void AddControl(ZControl* con);
	void RemoveControl(ZControl* con);
};
