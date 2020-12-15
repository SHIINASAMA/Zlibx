/**
 * \file   ZControl.h
 * \brief  控件基类定义
 *
 * \author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * \date   2020-12-15
 */
#pragma once

#include <Windows.h>
#include <map>
#include <vector>
#include "main.h"
#include "ZFont.h"
#include "ZRect.h"

 /** \brief 消息类型 */
enum class DLLAPI MessageType
{
	/** \brief 单击消息 */
	Clicked,
};

/** \brief 参数集合 */
typedef struct DLLAPI Param
{
	/** \brief 窗口句柄 */
	HWND hWnd;
	/** \brief 消息类型 */
	UINT uMsg;
	/** \brief 参数1 */
	WPARAM wParam;
	/** \brief 参数2 */
	LPARAM lParam;
}Param;

/** \brief 回调函数 */
typedef DLLAPI LRESULT(*CallbackFunc)(Param);

/** \brief 控件的消息类型和回调函数 */
typedef struct DLLAPI ControlFunc
{
	/** 消息类类型 */
	MessageType type;
	/** 回调函数 */
	CallbackFunc func;
}ControlFunc;

/**
 * \brief ZControl 类定义
 */
class DLLAPI ZControl
{
protected:
	HWND hWnd;
	HWND phWnd;

	ZString type;
	ZString text;
	ZRect rect;
	DWORD style;

public:
	UINT id;
	std::vector<ControlFunc> funcs;

	/**
	 * ZWindow::AddControl 将调用该函数
	 * 在这里应该完成控件的CreateWindow和保存父窗体的句柄
	 *
	 * \param hWnd 父窗口句柄
	 */
	virtual void Init(HWND hWnd) = 0;

	/**
	 * 绑定消息
	 *
	 * \param type 消息类型
	 * \param func 回调函数
	 */
	void Bind(MessageType type, CallbackFunc func);

	/**
	 * 设置字体
	 *
	 * \param font 目标字体
	 */
	void SetFont(ZFont font);

	/** \brief 设置默认字体位新宋体 */
	void SetDefFont();

	/**
	 * 获取控件文本
	 *
	 * \return 控件文本
	 */
	ZString GetText();

	/**
	 * 设置控件文本
	 *
	 * \param text 目标文本
	 */
	void SetText(ZString text);

	/**
	 * 设置左上角点坐标
	 *
	 * \param point 坐标
	 */
	void SetPoint(ZPoint point);

	/**
	 * 获取左上角点坐标
	 *
	 * \return 坐标
	 */
	ZPoint GetPoint();

	/**
	 * 设置控件尺寸
	 *
	 * \param size 尺寸
	 */
	void SetSize(ZSize size);

	/**
	 * 获取控件尺寸
	 *
	 * \return 尺寸
	 */
	ZSize GetSize();
};
