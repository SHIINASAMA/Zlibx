/**@file	ZFont.h
* @brief	����������
* @author	kaoru(SHIINA_KAORU@OUTLOOK.COM)
* @date		2020-12-10
*/

#pragma once

#include <Windows.h>
#include "ZString.h"

/** @brief ZFont ��
*/
class DLLAPI ZFont
{
protected:
	/** @brief ������
	*/
	HFONT font{ 0 };

	ZString fontName;

public:
	ZFont();

	/**@brief			�����������ƴ�������
	* @param FontName	��������
	*/
	ZFont(ZString FontName);

	/**@brief			�����������ƴ�������
	* @param FontName	��������
	*/
	void Create(ZString FontName);

	/**@brief					����������Windows API����ZFont����
	* @param cHeight			�����߼��߶�
	* @param cWidth				�����߼����
	* @param cEscapement		��λ�������豸X��֮���һ���Ƕ�
	* @param cOrientation		ÿ���ַ��Ļ��ߺ��豸X��֮��ĽǶ�
	* @param cWeight			���巶ΧȨ�أ�0~1000��
	* @param bItalic			ָ������б��
	* @param bUnderline			ָ�������»���
	* @param bStrikeOut			ָ������ɾ����
	* @param iCharSet			ָ�������ַ���
	* @param iOutPrecision		�����������
	* @param iClipPrecision		������о���
	* @param iQuality			�������
	* @param iPitchAndFamily	����ȿ�ͼ���
	* @param pszFaceName		���������
	*/
	void CreateEx(int cHeight, int cWidth, int cEscapement, int cOrientation, int cWeight, DWORD bItalic,
		DWORD bUnderline, DWORD bStrikeOut, DWORD iCharSet, DWORD iOutPrecision, DWORD iClipPrecision,
		DWORD iQuality, DWORD iPitchAndFamily, LPCWSTR pszFaceName);

	operator HFONT();
};
