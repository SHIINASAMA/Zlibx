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

 /**
  * \brief ��ȡ�ؼ�����
  * \brief ע�⣬�ⲻ��һ��Win Sdk��API��Ŀ���Ƕ�ӦSetWindowPosʹ��
  *
  * \param hWnd	Ŀ����
  * \param point ���ؽ��
  */
void GetWindowPos(HWND hWnd, POINT* point);

/** \brief �ص����� */
typedef DLLAPI void(*CallBackFunc)(WPARAM, LPARAM);

/** \brief ZControl �� */
class DLLAPI ZControl
{
protected:
	/** \brief �ؼ���� */
	HWND hWnd;
	/** \brief �����ھ�� */
	HWND phWnd;
	/** \brief �ؼ����ͣ������� */
	static ZString type;
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

	/**
	 * ���¿ؼ�λ��
	 *
	 * \param con Ŀ��ؼ�
	 */
	static void UpdateRect(ZControl* con);

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

	/**
	 * ���ÿؼ�λ��
	 *
	 * \param point ԭ������
	 */
	void SetPosition(ZPoint point);

	/**
	 * ��ȡ�ؼ�λ��
	 *
	 * \return ԭ������
	 */
	ZPoint GetPosition();

	/**
	 * ���ÿؼ����
	 *
	 * \param w ��
	 */
	void SetWidth(UINT w);

	/**
	 * ��ȡ�ؼ��߶�
	 *
	 * \return
	 */
	UINT GetWidth();

	/**
	 * ���ÿؼ��߶�
	 *
	 * \param h ��
	 */
	void SetHeight(UINT h);

	/**
	 * ��ȡ�ؼ��߶�
	 *
	 * \return ��
	 */
	UINT GetHeight();
};
