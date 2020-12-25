/**	@file	ZRect.h
*	@brief	����������
*	@author kaoru(SHIINA_KAORU@OUTLOOK.COM)
*	@date	2020-12-09
*/

#pragma once
#include <Windows.h>
#include "ZPoint.h"
#include "ZSize.h"
#include "main.h"

/**	@brief	ZRect ��
*/
class DLLAPI ZRect
{
public:
	/** @brief ���Ͻ�����
	*/
	ZPoint A;
	/** @brief ���½�����
	*/
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
	* @param x1 ���Ͻǵ�X����
	* @param y1 ���Ͻǵ�Y����
	* @param x2 ���½ǵ�Y����
	* @param y2 ���½ǵ�Y����
	*/
	ZRect(int x1, int y1, int x2, int y2);

	/**
	 * ���þ���Ŀ�
	 *
	 * \param w Ŀ����
	 */
	void SetWidth(int w);

	/**
	 * ��ȡ����Ŀ�
	 *
	 * \return ������
	 */
	int GetWidth();

	/**
	 * ���þ���ĸ�
	 *
	 * \param h Ŀ��߶�
	 */
	void SetHeight(int h);

	/**
	 * ��ȡ����ĸ�
	 *
	 * \return ����߶�
	 */
	int GetHeight();

	/**@brief	��ȡ�����С
	* @retval	��С
	*/
	ZSize GetSize();

	/**@brief		���þ����С
	* @param Size	Ŀ���С
	*/
	void SetSize(ZSize Size);

	/**
	 * ת���ӿؼ��ľ���
	 *
	 * \return �������
	 */
	ZRect ToClientRect();

	/**
	 * ���þ���ƫ��ֵ
	 *
	 * \param x	����ƫ��ֵ
	 * \param y ����ƫ��ֵ
	 */
	void OffsetRect(int x, int y);

	operator RECT();
	operator LPRECT();
	operator Gdiplus::Rect();
};
