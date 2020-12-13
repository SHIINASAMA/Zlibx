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
  * @brief ZButton �ඨ��
  */
class DLLAPI ZButton :
	public ZControl
{
public:
	/**
	 * ʵ����һ����ť����
	 *
	 * \param text ��ť�ı�
	 * \param func ��ť��Ӧ����
	 */
	ZButton(ZString text, CALLBACKFUNC func = NULL);

	/**
	 * ʵ����һ����ť����
	 *
	 * \param text ��ť�ı�
	 * \param x	   x����
	 * \param y	   y����
	 * \param w    ��
	 * \param h    ��
	 * \param func ��ť��Ӧ����
	 */
	ZButton(ZString text, int x, int y, int w, int h, CALLBACKFUNC func = NULL);

	/**
	 * ���ظ��ؼ����غ���
	 *
	 * \param handle ���ؼ����
	 */
	void Init(HANDLE handle);

	/**
	 * ���ð�ť�Ƿ����
	 *
	 * \param enable �Ƿ����
	 */
	void SetEnable(BOOL enable);
};
