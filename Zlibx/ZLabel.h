/**
 * \file   ZLabel.h
 * \brief  ��̬�ı��ؼ��ඨ��
 *
 * \author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * \date   2020-12-15
 */

#pragma once
#include "ZControl.h"

 /**
  * \breif ZLabel �ඨ��
  */
class DLLAPI ZLabel :
	public ZControl
{
public:
	/**
	 * ʵ����һ����̬�ı��ؼ�����
	 *
	 * \param text ��ʾ�ı�
	 */
	ZLabel(ZString text);

	/**
	 * ʵ����һ����̬�ı��ؼ�����
	 *
	 * \param text	��ʾ
	 * \param x		x����
	 * \param y		y����
	 * \param w		��
	 * \param h		��
	 */
	ZLabel(ZString text, int x, int y, int w, int h);

	/**
	 * ��д���ؼ����õĳ�ʼ������
	 *
	 * \param hWnd ���ؼ����
	 */
	void Init(HWND hWnd);

	/**
	 * ���ÿؼ��ı�
	 *
	 * \param text Ŀ���ı�
	 */
	void SetText(ZString text);
};
