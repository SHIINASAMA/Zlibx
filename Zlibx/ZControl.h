/**	@file	ZControl.h
*	@brief	控件基类定义
*	@author	kaoru(SHHINA_KAORU@OUTLOOK.COM)
*	@date	2020-12-10
*/

#pragma once

#include <Windows.h>
#include "main.h"
#include "ZString.h"
#include "ZRect.h"

/**	@brief ZControl 类定义
*/
class DLLAPI ZControl
{
protected:
	/**	@brief 控件类型
	*/
	ZString type;

	/** @brief 控件ID
	*/
	DWORDLONG id;

	/** @brief 控件句柄
	*/
	HANDLE handle;

	/** @brief 控件风格
	*/
	DWORD style;

	/** @brief 控件文本
	*/
	ZString text;

	/**	@brief 控件矩形
	*/
	ZRect rect;

	/**	@brief 控件字体
	*/
	//ZFont font;

	/** @brief			初始化方法\n供父项调用
	*	@param handle	父窗口句柄
	*/
	virtual void Init(HANDLE handle) = 0;
};
