/**
 * \file   ZWindow.h
 * \brief  窗体类声明
 *
 * \author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * \date   2020-12-19
 */

#pragma once
#pragma warning(disable:4251)

#include "ZControl.h"

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

/** \brief ZWindow 类 */
class DLLAPI ZWindow
{
protected:
	/** \brief 窗体句柄 */
	HWND hWnd;
	/** \brief 窗体风格 */
	DWORD style;
	/** \brief 窗体区域 */
	ZRect rect;
	/** \brief 窗体文本 */
	ZString text;
	/** \brief 窗体实例句柄 */
	HINSTANCE hInstance;

private:
	static ZString type;
	static BOOL isRegistered;

	//GDI+
	static GdiplusStartupInput	gdiplusStartupInput;
	static ULONG_PTR			gdiplusToken;
	static UINT					count;

	void SetStyle(WindowStyle style);

	static std::map<HWND, const ZWindow*> windowList;

	static const ZWindow* GetWindow(HWND hWnd);

	static LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	~ZWindow();

	static void UpdateRect(ZWindow* win);
public:
	/**
	 * 初始化一个窗体对象
	 *
	 * \param text	窗体标题
	 * \param x		x坐标
	 * \param y		y坐标
	 * \param w		宽
	 * \param h		高
	 * \param style 窗体风格
	 */
	ZWindow(ZString text, int x, int y, int w, int h, WindowStyle style = WindowStyle::Sizable);

	/** \brief 注册并创建窗体 */
	void Create();

	/** \brief 运行窗体 */
	void Run();

	/**
	 * \brief 向窗体添加控件.
	 *
	 * \param con 目标控件
	 */
	void Add(ZControl* con);

	/**
	 * \brief 从目标窗体移除控件
	 *
	 * \param con 目标控件
	 */
	void Remove(ZControl* con);

	/**
	 * \brief 设置窗体居中显示，支持多显示器
	 *
	 */
	void ShowCenter();

	/**
	 * 设置控件位置
	 *
	 * \param point 原点坐标
	 */
	void SetPosition(ZPoint point);

	/**
	 * 获取控件位置
	 *
	 * \return 原点坐标
	 */
	ZPoint GetPosition();

	/**
	 * 设置控件宽度
	 *
	 * \param w 宽
	 */
	void SetWidth(UINT w);

	/**
	 * 获取控件高度
	 *
	 * \return
	 */
	UINT GetWidth();

	/**
	 * 设置控件高度
	 *
	 * \param h 高
	 */
	void SetHeight(UINT h);

	/**
	 * 获取控件高度
	 *
	 * \return 高
	 */
	UINT GetHeight();
};