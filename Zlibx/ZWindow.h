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
#include "ZIcon.h"

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
enum class DLLAPI DialogResult
{
	/** \brief 是 */
	Ok,
	/** \brief 否 */
	No
};

/**
 * \brief ZWindow 类
 *
 * \brief 窗体类
 *
 * \image html SimpleDemo.png
 */
class DLLAPI ZWindow : public ZControl
{
protected:
	/** \brief 窗体风格 */
	DWORD style{ 0 };
	/** \brief 窗体区域 */
	ZRect rect;
	/** \brief 窗体文本 */
	ZString text;
	/** \brief 窗体实例句柄 */
	HINSTANCE hInstance{ 0 };

	/**
	 * \brief 供父窗体调用
	 *
	 * \param hWnd 父窗体句柄
	 *
	 */
	void Init(HWND hWnd);
	//todo:待完善
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

	//窗体返回值
	DialogResult dialogResult = DialogResult::No;
	//指示窗口是否是模式对话框
	BOOL isModal = FALSE;

	~ZWindow();

	static void UpdateRect(ZWindow* win);
public:
	/**
	 * \brief 初始化一个窗体对象
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
	 * \brief 创建一个模式对话框
	 *
	 * \param hWnd	父窗口句柄
	 * \return		窗体返回值
	 */
	DialogResult RunDialog(HWND hWnd);

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
	 * \brief 设置控件位置
	 *
	 * \param point 原点坐标
	 */
	void SetPosition(ZPoint point);

	/**
	 * \brief 获取控件位置
	 *
	 * \return 原点坐标
	 */
	ZPoint GetPosition();

	/**
	 * \brief 设置控件宽度
	 *
	 * \param w 宽
	 */
	void SetWidth(UINT w);

	/**
	 * \brief 获取控件宽度
	 *
	 * \return 宽
	 */
	UINT GetWidth();

	/**
	 * \brief 设置控件高度
	 *
	 * \param h 高
	 */
	void SetHeight(UINT h);

	/**
	 * \brief 获取控件高度
	 *
	 * \return 高
	 */
	UINT GetHeight();

	/**
	 * \brief 设置控件文本
	 *
	 * \param text 文本
	 */
	void SetText(ZString text);

	/**
	 * \brief 获取控件文本
	 *
	 * \return 文本
	 */
	ZString GetText();

	/**
	 * \brief 设置窗体图标
	 *
	 * \param icon 目标图标
	 */
	void SetIcon(ZIcon icon);
};