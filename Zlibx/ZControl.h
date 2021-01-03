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

 /**
  * \brief 获取控件坐标
  * \brief 注意，这不是一个Win Sdk的API，目的是对应SetWindowPos使用
  *
  * \param hWnd	目标句柄
  * \param point 返回结果
  */
void GetWindowPos(HWND hWnd, POINT* point);

/** \brief 回调函数 */
typedef DLLAPI void(*CallBackFunc)(WPARAM, LPARAM);

/** \brief ZControl 类 */
class DLLAPI ZControl
{
protected:
	/** \brief 控件句柄 */
	HWND hWnd{ 0 };
	/** \brief 父窗口句柄 */
	HWND phWnd{ 0 };
	/** \brief 控件类型（类名） */
	static ZString type;
	/** \brief 控件区域 */
	ZRect rect;

	/**
	 * \brief 子消息循环.
	 *
	 * \param hWnd		控件句柄
	 * \param uMsg		消息类型
	 * \param wParam	参数1
	 * \param lParam	参数2
	 * \return			结果
	 */
	static LRESULT CALLBACK ConProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	/**
	 * \brief 更新控件位置
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
	 * \brief 该函数由窗口调用
	 *
	 * \param hWnd 窗口句柄
	 */
	virtual void Init(HWND hWnd) = 0;

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
	 * \brief 获取控件高度
	 *
	 * \return 高
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
	 * \brief 设置控件是否可见
	 *
	 * \param enable 指示值
	 */
	void SetVisible(BOOL enable);

	/**
	 * \brief 设置控件是否可用
	 *
	 * \param enable 指示值
	 */
	void SetEnable(BOOL enable);

	/**
	 * \brief 获取控件句柄
	 *
	 * \retval 控件句柄
	 */
	HWND GetHandle();
};
