/**@file	ZColor.h
* @brief	��ɫ������
* @author	kaoru(SHIINA_KAORU@OUTLOOK.COM)
* @date		2020-12-09
*/

#pragma once

#include <Windows.h>
#include "main.h"

/**	@brief ZColor ��
*/
class DLLAPI ZColor
{
private:
	COLORREF color;

public:
	/**@brief ����RGBֵ��ʼ��һ��ZColor����
	* @param R ��
	* @param G ��
	* @param B ��
	*/
	ZColor(BYTE R, BYTE G, BYTE B);

	operator COLORREF();
	void operator=(COLORREF color);

	/**@brief ��ȡ��ֵ
	* @retval ���
	*/
	BYTE GetRVar();

	/**@brief ��ȡ��ֵ
	* @retval ���
	*/
	BYTE GetGVar();

	/**@brief ��ȡ��ֵ
	* @retval ���
	*/
	BYTE GetBVar();
};
