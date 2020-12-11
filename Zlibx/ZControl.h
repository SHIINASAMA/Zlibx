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
#include "ZFont.h"

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
	ZFont font;

public:
	/**
	 * 供父控件调用
	 *
	 * \param handle 父控件句柄
	 * \return		 子控件句柄
	 */
	virtual HANDLE Init(HANDLE handle) = 0;

	/**
	 * 获取控件文本
	 *
	 * \return 控件的文本
	 */
	ZString GetText();

	/**
	 * 设置控件文本
	 *
	 * \param text 目标文本
	 */
	void SetText(ZString text);

	/**
	 * 获取控件ID
	 *
	 * \return 控件的ID
	 */
	DWORDLONG GetID();

	/**
	 * 设置控件大小
	 *
	 * \param size 目标大小
	 */
	void SetSize(ZSize size);

	/**
	 * 设置控件大小
	 *
	 * \param w 宽
	 * \param h 高
	 */
	void SetSize(int w, int h);

	/**
	 * 获取控件大小
	 *
	 * \return 控件大小
	 */
	ZSize GetSize();

	/**
	 * 设置字体
	 *
	 * \param font 目标字体
	 */
	void SetFont(ZFont font);

	/**
	 * 获取控件左上角位置
	 *
	 * \return 控件位置
	 */
	ZPoint GetPoint();

	/**
	 * 设置控件位置
	 *
	 * \param point 目标位置
	 */
	void SetPoint(ZPoint point);
};
