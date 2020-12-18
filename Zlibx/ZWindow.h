#pragma once

#include "ZControl.h"
#include <map>

/** \brief 窗体类型枚举 */
enum class DLLAPI WindowStyle
{
	/** \brief 无边框*/
	None,
	/** \brief 固定的单行边框*/
	FixedSingle,
	/** \brief 固定的三维边框*/
	Fixed3D,
	/** \brief 固定的对话框样式的粗边框*/
	FixedDialog,
	/** \brief 可调整大小的边框*/
	Sizable,
	/** \brief 不可调整大小的工具窗口边框*/
	FixedToolWindow,
	/** \brief 可调整大小的工具窗口边框*/
	SizableToolWindow,
};

/** \brief 窗体返回值类型 */
enum class DLLAPI DialogResult {
	/** \brief 是 */
	Ok,
	/** \brief 否 */
	No
};

class DLLAPI ZWindow
{
protected:
	HWND hWnd;
	DWORD style;
	ZRect rect;
	ZString text;
	HINSTANCE hInstance;

private:
	void SetStyle(WindowStyle style);

	static std::map<HWND, const ZWindow*> windowMap;

	static const ZWindow* GetWindow(HWND hWnd);

	static LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	~ZWindow();
public:
	ZWindow(ZString text, int x, int y, int w, int h, WindowStyle style = WindowStyle::Sizable);

	void Create();

	void Run();

	void Add(ZControl* con);
};