/**	@file	ZSize.h
*	@brief	��С�ඨ��
*	@author kaoru(SHIINA_KAORU@OUTLOOK.COM)
*	@date	2020-12-09
*/

#pragma once

#include "main.h"

/**	@brief ZSize �ඨ��
*/
class DLLAPI ZSize
{
public:
	/** @brief ��
	*/
	int w = 0;
	/** @brief ��
	*/
	int h = 0;

	/**	@brief		��ʼ��һ��ZSize����
	*	@param	w	Ŀ���
	*	@param	h	Ŀ���
	*/
	ZSize(int w, int h);
};
