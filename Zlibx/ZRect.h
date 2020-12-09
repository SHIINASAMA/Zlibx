/**	@file	ZRect.h
*	@brief	�����ඨ��
*	@author kaoru(SHIINA_KAORU@OUTLOOK.COM)
*	@date	2020-12-09
*/

#pragma once
#include <Windows.h>
#include "ZPoint.h"
#include "ZSize.h"

/**	@brief	ZRect �ඨ��
*/
class ZRect
{
public:
	ZPoint A;
	ZPoint B;

	/**@brief ������ ZRect ����
	*/
	ZRect();

	/**@brief		��ʼ�� ZRect ����
	* @param Rect	Դ����
	*/
	ZRect(RECT Rect);

	/**@brief	��ʼ�� ZRect ����
	* @param A	���Ͻǵĵ�
	* @param B	���½ǵĵ�
	*/
	ZRect(ZPoint A, ZPoint B);

	/**@brief	��ʼ�� ZRect ����
	* @param X1 ���Ͻǵ�X����
	* @param Y1 ���Ͻǵ�Y����
	* @param X2 ���½ǵ�Y����
	* @param Y2 ���½ǵ�Y����
	*/
	ZRect(int x1, int y1, int x2, int y2);

	/**@brief	��ȡ�����С
	* @retval	��С
	*/
	ZSize GetSize();

	/**@brief		���þ����С
	* @param Size	Ŀ���С
	*/
	void SetSize(ZSize Size);

	/**@brief	��ȡRECT�ṹ
	* @retval	�ṹ
	*/
	RECT GetRect();

	operator RECT();
	operator LPCRECT();
};
