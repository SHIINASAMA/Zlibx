/**
 * \file   ZButton.h
 * \brief  按钮控件类定义
 *
 * \author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * \date   2020-12-15
 */

#pragma once
#include "ZControl.h"

 /** \brief ZButton 类定义 */
class DLLAPI ZButton :
	public ZControl
{
public:
	ZButton(ZString text, int x, int y, int w, int h);

	void Init(HWND hWnd);
};
