/**	@file	ZSize.h
*	@brief	��С������
*	@author kaoru(SHIINA_KAORU@OUTLOOK.COM)
*	@date	2020-12-09
*/

#pragma once

#include "main.h"

/**	@brief ZSize ��
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
