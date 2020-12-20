/**	@file	ZPoint.h
*	@brief	��ά��������
*	@author kaoru(SHIINA_KAORU@OUTLOOK.COM)
*	@date	2020-12-09
*/

#pragma once

#include <Windows.h>
#include "main.h"

/**	@brief	ZPoint ��
*/
class DLLAPI ZPoint
{
public:
	/** @brief x������
	*/
	int x = 0;
	/** @brief y������
	*/
	int y = 0;

	/**@brief	ʵ����һ����ZPoin����
	*/
	ZPoint();

	/**@brief	ʵ����һ��ZPoin����
	* @param x	x����
	* @param y	y����
	*/
	ZPoint(int x, int y);

	void operator=(POINT pt);
	operator POINT();
};
