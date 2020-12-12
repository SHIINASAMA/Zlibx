/**
 * \file   ZButton.h
 * \brief  ��ť�ؼ��ඨ��
 *
 * \author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * \date   2020-12-12
 */

#pragma once
#include "ZControl.h"

 /**
  * ZButton �ඨ��
  */
class DLLAPI ZButton :

	public ZControl
{
public:
	ZButton(ZString text, CALLBACKFUNC func = NULL);

	ZButton(ZString text, int x, int y, int w, int h, CALLBACKFUNC func = NULL);

	void Init(HANDLE handle);

	void SetEnable(BOOL enable);
};
