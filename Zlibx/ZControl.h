/**
 * \file   ZControl.h
 * \brief  控件基类声明
 *
 * \author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * \date   2020-12-19
 */

#pragma once

#include <Windows.h>
#include "main.h"
#include "ZString.h"
#include "ZRect.h"
#include "ZFont.h"
#include "ZColor.h"

 /** \brief 回调函数 */
typedef DLLAPI void(*CallBackFunc)(WPARAM, LPARAM);

/** \brief ZControl 类定义 */
class DLLAPI ZControl
{
protected:
	/** \brief 控件句柄 */
	HWND hWnd;
	/** \brief 父窗口句柄 */
	HWND phWnd;
	/** \brief 控件类型（类名） */
	ZString type;
	/** \brief 控件区域 */
	ZRect rect;

	/**
	 * \brief 子消息循环.
	 *
	 * \param hWnd		控件句柄
	 * \param uMsg		消息类型
	 * \param wParam	参数1
	 * \param lParam	参数2
	 * \return
	 */
	static LRESULT CALLBACK ConProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	/** \brief 控件默认析构函数 */
	~ZControl();
public:
	/** \brief 控件默认构造函数 */
	ZControl();

	/**
	 * 该函数由窗口调用
	 *
	 * \param hWnd 窗口句柄
	 */
	virtual void Init(HWND hWnd) = 0;
};
