/**	@file	ZString.h
*	@brief	�ַ����ඨ��
*	@author kaoru(SHIINA_KAORU@OUTLOOK.COM)
*	@date	2020-12-09
*/

#pragma once

#include <Windows.h>
#include "main.h"

/**@brief ���ַ���
*/
#define WString LPCWSTR

/**@brief ���ַ�
*/
#define WChar wchar_t

/**@brief խ�ַ���
*/
#define AString char*

/**@brief խ�ַ�
*/
#define AChar char

/**	@brief ZString �ඨ��
*/
class DLLAPI ZString
{
private:
	WString str;

public:
	/** @brief ע�⣬��ᴴ��һ���յ�ZString����
	*/
	ZString();

	/** @brief			����WString��ʼ��һ��ZString����
	*	@param	objStr	Ŀ��WString����
	*/
	ZString(WString objStr);

	/** @brief			����AString��ʼ��һ��ZString����
	*	@param	objStr	Ŀ��AString����
	*/
	ZString(AString objStr);

	/** @brief	�õ�ZString��WString����
	*	@retval Ŀ�����
	*/
	WString ToWString();

	/** @brief	�õ�ZString��AString����
	*	@retval	Ŀ�����
	*/
	AString ToAString();

	/** @brief	ZString������ַ�������
	*	@retval	�ַ�������
	*/
	int Len();

	/**	@brief			ת��һ��WString����
	*	@param	srcStr	Դ�ַ���
	*/
	void Pause(WString srcStr);

	/**	@brief			ת��һ��AString����
	*	@param	srcStr	Դ�ַ���
	*/
	void Pause(AString srcStr);

	void operator=(WString str);
	void operator=(WChar str[]);
	operator WString();
	WChar operator[](int index);
};