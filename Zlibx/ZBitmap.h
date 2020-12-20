/**
 * \file   ZBitmap.h
 * \brief  λͼ������
 *
 * \author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * \date   2020-12-17
 */

#pragma once
#include "ZResource.h"

 /** \brief ZBitmap �ඨ�� */
class DLLAPI ZBitmap :
	public ZResource
{
private:
	HBITMAP hbmp;

public:
	/**
	 * ����Դ�ļ��м���λͼ
	 *
	 * \param ID λͼ��ԴID
	 */
	void Load(WORD ID);

	/**
	 * \brief ���ⲿ�ļ��м���λͼ
	 *
	 * \param Path λͼ·��
	 */
	void LoadFromFile(ZString Path);

	/**
	 * ��ȡWin32λͼ����
	 *
	 * \return λͼ
	 */
	BITMAP GetBitmap();

	void operator=(HBITMAP hBmp);
	operator HBITMAP();
};
