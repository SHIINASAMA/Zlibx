/**
 * \file   ZIcon.h
 * \brief  ͼ��������
 *
 * \author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * \date   2020-12-29
 */

#pragma once

#include "ZResource.h"

 /**
  * \brief ZIcon ��
  */
class ZIcon :
	public ZResource
{
	HICON hIcon{ 0 };
public:
	/**
	 * \brief Ĭ�Ϲ��캯��������һ����ZIcon����
	 *
	 */
	ZIcon();

	/**
	 * \brief ����Դ�м���һ��ͼ��
	 *
	 * \param ID ��ԴID
	 */
	ZIcon(WORD ID);

	/**
	 * \brief ���ļ��м���һ��ͼ��
	 *
	 * \param Path ��Դ·��
	 */
	ZIcon(ZString Path);

	/**
	 * \brief ����Դ�м���һ��ͼ��
	 *
	 * \param ID ��ԴID
	 */
	void Load(WORD ID);

	/**
	 * \brief ���ļ��м���һ��ͼ��
	 *
	 * \param Path ��Դ·��
	 */
	void LoadFromFile(ZString Path);

	operator HICON();

	void operator=(HICON hIcon);
};
