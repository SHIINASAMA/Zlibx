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

/** \brief ZControl 类 */
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

	/**
	 * 更新控件位置
	 *
	 * \param con 目标控件
	 */
	static void UpdateRect(ZControl* con);

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
