/**
 * \file   ZButton.h
 * \brief  ��ť�ؼ��ඨ��
 *
 * \author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * \date   2020-12-15
 */

#pragma once
#include "ZControl.h"

 /** \brief ZButton �ඨ�� */
class DLLAPI ZButton :
	public ZControl
{
public:
	ZButton(ZString text, int x, int y, int w, int h);

	void Init(HWND hWnd);
};
