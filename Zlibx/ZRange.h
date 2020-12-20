/**	@file	ZRange.h
*	@brief	����������
*	@author	kaoru(SHIINA_KAORU@OUTLOOK.COM)
*	@date	2020-12-10
*/

#pragma once

#include <Windows.h>
#include <CommCtrl.h>
#include "main.h"

/**	@brief ZRange ��
*/
class DLLAPI ZRange
{
public:
	/** @brief ��˵�
	*/
	int x1;
	/** @brief �Ҷ˵�
	*/
	int x2;

	/**@brief	ʵ����һ����ZRange����
	*/
	ZRange();
	/**@brief	ʵ����һ��ZRange����
	* @param x1 ��˵�
	* @param x2 �Ҷ˵�
	*/
	ZRange(int x1, int x2);

	void operator=(PBRANGE Range);
	operator PBRANGE();
};
