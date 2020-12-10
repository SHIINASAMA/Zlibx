/**	@file	ZWindow.h
*	@brief	窗体类定义
*	@author	kaoru(SHIINA_KAORU@OURLOOK.COM)
*	@date	2020-12-10
*/

#pragma once
#include "ZControl.h"
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
	/**@brief 可调整大小的边*/
	Sizable,
	/**@brief 不可调整大小的工具窗口边框*/
	FixedToolWindow,
	/**@brief 可调整大小的工具窗口边框*/
	SizableToolWindow,
};

/**	@brief ZWindow 类定义
*/
class DLLAPI ZWindow : public ZControl
{
public:
	ZWindow(ZString text);

	ZWindow(ZString text, int x, int y, int w, int h);

	ZWindow(ZString text, int x, int y, int w, int h, WindowType type = Sizable);

	void SetWindowType(WindowType type);

	/** @brief 不要调用该函数
	*/
	void Init(HANDLE handle);

	/** @brief 注册并创建窗体
	*/
	void Create();
};
