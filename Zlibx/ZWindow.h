/**	@file	ZWindow.h
*	@brief	窗体类定义
*	@author	kaoru(SHIINA_KAORU@OURLOOK.COM)
*	@date	2020-12-10
*/

#pragma once
#include "ZControl.h"
#include "ZPanel.h"
#include "main.h"

/** @brief 窗体类型枚举
*/
enum DLLAPI WindowType {
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

/**	@brief ZWindow 类定义
*/
class DLLAPI ZWindow : public ZControl, public ZPanel
{
private:
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	/** @brief 不要调用该函数
	*/
	void Init(HANDLE handle);

	/**
	 * 释放资源
	 *
	 */
	~ZWindow();

public:
	/** @brief		实例化 ZWindow 对象
	*	@param text 窗体标题
	*	@param type 窗体风格
	*/
	ZWindow(ZString text, WindowType type = Sizable);

	/**
	 * 实例化 ZWindow 对象
	 *
	 * \param text	窗体标题
	 * \param x		x坐标
	 * \param y		y坐标
	 * \param w		宽
	 * \param h		高
	 * \param type	窗体风格
	 */
	ZWindow(ZString text, int x, int y, int w, int h, WindowType type = Sizable);

	/**	@brief 设置窗体风格
	*	\deprecated 该函数最好是让框架自己调用，用户也可以自己在Create函数运行前调用该函数
	*/
	void SetWindowType(WindowType type);

	/** @brief 注册并创建窗体
	*/
	void Create();

	/**
	 * 展示窗体
	 */
	void Run();

	/**
	 * 向窗体添加控件
	 *
	 * \param con 目标控件
	 */
	void AddControl(ZControl* con);

	/**
	 * 从窗体移除控件
	 *
	 * \param con 目标控件
	 */
	void RemoveControl(ZControl* con);
};
