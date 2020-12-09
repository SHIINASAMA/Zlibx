/**	@file	ZPoint.h
*	@brief	��ά���ඨ��
*	@author kaoru(SHIINA_KAORU@OUTLOOK.COM)
*	@date	2020-12-09
*/

#pragma once

#include <Windows.h>

/**	@brief	ZPoint��ʵ��
*/
class ZPoint
{
public:
	int x = 0;
	int y = 0;

	/**@brief	ʵ����һ����ZPoin����
	*/
	ZPoint();

	/**@brief	ʵ����һ��ZPoin����
	* @param X	x����
	* @param Y	y����
	*/
	ZPoint(int x, int y);

	void operator=(POINT pt);
	operator POINT();
};
