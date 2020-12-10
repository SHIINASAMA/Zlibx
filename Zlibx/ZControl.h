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
	//ZFont font;

	/** @brief			��ʼ������\n���������
	*	@param handle	�����ھ��
	*/
	virtual void Init(HANDLE handle) = 0;
};
