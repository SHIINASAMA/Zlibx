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
	/** 是 */
	Ok,
	/** 否 */
	No
};

/**
 * \brief ZWindow 类定义
 */
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
	//TODO:在这里添加其他消息队列
public:
	/**
	 * 实例化一个窗体对象
	 *
	 * \param text	窗体标题
	 * \param x		x坐标
	 * \param y		y坐标
	 * \param w		宽
	 * \param h		高
	 * \param type	风格类型
	 */
	ZWindow(ZString text,
		int x, int y, int w, int h,
		WindowType type = WindowType::Sizable);

	/**	\brief 设置窗体风格
	*	\param type 风格类型
	*	\deprecated 该函数最好是让框架自己调用，用户也可以自己在Create函数运行前调用该函数
	*/
	void SetWindowType(WindowType type);

	/** \brief 注册并创建窗体 */
	void Create();

	/** \brief 进入消息循环 */
	void Run();

	/** \brief 显示模式对话框 */
	DialogResult RunDialog();

	/**
	 * 向窗体添加控件
	 *
	 * \param con 目标控件
	 */
	void AddControl(ZControl* con);

	/**
	 * 从窗体中移除控件
	 *
	 * \param con 目标控件
	 */
	void RemoveControl(ZControl* con);
};
