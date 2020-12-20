/**
 * \file   ZControl.h
 * \brief  �ؼ���������
 *
 * \author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * \date   2020-12-19
 */

#pragma once

#include <Windows.h>
#include "main.h"
#include "ZString.h"
#include "ZRect.h"
#include "ZFont.h"
#include "ZColor.h"

 /** \brief �ص����� */
typedef DLLAPI void(*CallBackFunc)(WPARAM, LPARAM);

/** \brief ZControl �ඨ�� */
class DLLAPI ZControl
{
protected:
	/** \brief �ؼ���� */
	HWND hWnd;
	/** \brief �����ھ�� */
	HWND phWnd;
	/** \brief �ؼ����ͣ������� */
	ZString type;
	/** \brief �ؼ����� */
	ZRect rect;

	/**
	 * \brief ����Ϣѭ��.
	 *
	 * \param hWnd		�ؼ����
	 * \param uMsg		��Ϣ����
	 * \param wParam	����1
	 * \param lParam	����2
	 * \return
	 */
	static LRESULT CALLBACK ConProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	/** \brief �ؼ�Ĭ���������� */
	~ZControl();
public:
	/** \brief �ؼ�Ĭ�Ϲ��캯�� */
	ZControl();

	/**
	 * �ú����ɴ��ڵ���
	 *
	 * \param hWnd ���ھ��
	 */
	virtual void Init(HWND hWnd) = 0;
};
