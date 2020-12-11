/**	@file	ZControl.h
*	@brief	�ؼ����ඨ��
*	@author	kaoru(SHHINA_KAORU@OUTLOOK.COM)
*	@date	2020-12-10
*/

#pragma once

#include <Windows.h>
#include "main.h"
#include "ZString.h"
#include "ZRect.h"
#include "ZFont.h"

/**	@brief ZControl �ඨ��
*/
class DLLAPI ZControl
{
protected:
	/**	@brief �ؼ�����
	*/
	ZString type;

	/** @brief �ؼ�ID
	*/
	DWORDLONG id;

	/** @brief �ؼ����
	*/
	HANDLE handle;

	/** @brief �ؼ����
	*/
	DWORD style;

	/** @brief �ؼ��ı�
	*/
	ZString text;

	/**	@brief �ؼ�����
	*/
	ZRect rect;

	/**	@brief �ؼ�����
	*/
	ZFont font;

public:
	/**
	 * �����ؼ�����
	 *
	 * \param handle ���ؼ����
	 * \return		 �ӿؼ����
	 */
	virtual HANDLE Init(HANDLE handle) = 0;

	/**
	 * ��ȡ�ؼ��ı�
	 *
	 * \return �ؼ����ı�
	 */
	ZString GetText();

	/**
	 * ���ÿؼ��ı�
	 *
	 * \param text Ŀ���ı�
	 */
	void SetText(ZString text);

	/**
	 * ��ȡ�ؼ�ID
	 *
	 * \return �ؼ���ID
	 */
	DWORDLONG GetID();

	/**
	 * ���ÿؼ���С
	 *
	 * \param size Ŀ���С
	 */
	void SetSize(ZSize size);

	/**
	 * ���ÿؼ���С
	 *
	 * \param w ��
	 * \param h ��
	 */
	void SetSize(int w, int h);

	/**
	 * ��ȡ�ؼ���С
	 *
	 * \return �ؼ���С
	 */
	ZSize GetSize();

	/**
	 * ��������
	 *
	 * \param font Ŀ������
	 */
	void SetFont(ZFont font);

	/**
	 * ��ȡ�ؼ����Ͻ�λ��
	 *
	 * \return �ؼ�λ��
	 */
	ZPoint GetPoint();

	/**
	 * ���ÿؼ�λ��
	 *
	 * \param point Ŀ��λ��
	 */
	void SetPoint(ZPoint point);
};
