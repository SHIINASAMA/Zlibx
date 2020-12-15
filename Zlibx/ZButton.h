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
	/**
	 * ʵ����һ����ť�ؼ�����
	 *
	 * \param text	�ؼ��ı�
	 * \param x		x����
	 * \param y		y����
	 * \param w		��
	 * \param h		��
	 */
	ZButton(ZString text, int x, int y, int w, int h);

	/**
	 * ���ظ��ؼ����غ���
	 *
	 * \param hWnd ���ؼ����
	 */
	void Init(HWND hWnd);
};
