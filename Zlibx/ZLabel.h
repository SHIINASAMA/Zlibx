/**
 * \file   ZLabel.h
 * \brief  ��̬�ı��ؼ��ඨ��
 *
 * \author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * \date   2020-12-12
 */

#pragma once
#include "ZControl.h"

 /**
  * ZLabel �ඨ��
  */
class DLLAPI ZLabel :
	public ZControl
{
public:
	/**
	 * ʵ����һ��ZLabel����
	 *
	 * \param text ��ʾ�ı�
	 */
	ZLabel(ZString text);

	/**
	 * ʵ����һ��ZLabel����
	 *
	 * \param text	��ʾ�ı�
	 * \param x		x����
	 * \param y		y����
	 * \param w		��
	 * \param h		��
	 */
	ZLabel(ZString text, int x, int y, int w, int h);

	/**
	 * ���ظ��ؼ����غ���
	 *
	 * \param handle ���ؼ����
	 * \return		 �ӿؼ����
	 */
	void Init(HANDLE handle);
};
