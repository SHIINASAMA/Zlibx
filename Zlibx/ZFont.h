/**@file	ZFont.h
* @brief	字体类声明
* @author	kaoru(SHIINA_KAORU@OUTLOOK.COM)
* @date		2020-12-10
*/

#pragma once

#include <Windows.h>
#include "ZString.h"

/** @brief ZFont 类
*/
class DLLAPI ZFont
{
protected:
	/** @brief 字体句柄
	*/
	HFONT font{ 0 };

	ZString fontName;

public:
	ZFont();

	/**@brief			根据字体名称创建字体
	* @param FontName	字体名称
	*/
	ZFont(ZString FontName);

	/**@brief			根据字体名称创建字体
	* @param FontName	字体名称
	*/
	void Create(ZString FontName);

	/**@brief					根据完整的Windows API创建ZFont字体
	* @param cHeight			字体逻辑高度
	* @param cWidth				字体逻辑宽度
	* @param cEscapement		移位向量和设备X轴之间的一个角度
	* @param cOrientation		每个字符的基线和设备X轴之间的角度
	* @param cWeight			字体范围权重（0~1000）
	* @param bItalic			指定字体斜体
	* @param bUnderline			指定字体下划线
	* @param bStrikeOut			指定字体删除线
	* @param iCharSet			指定字体字符集
	* @param iOutPrecision		字体输出精度
	* @param iClipPrecision		出界剪切精度
	* @param iQuality			输出质量
	* @param iPitchAndFamily	字体等宽和家族
	* @param pszFaceName		字体的名称
	*/
	void CreateEx(int cHeight, int cWidth, int cEscapement, int cOrientation, int cWeight, DWORD bItalic,
		DWORD bUnderline, DWORD bStrikeOut, DWORD iCharSet, DWORD iOutPrecision, DWORD iClipPrecision,
		DWORD iQuality, DWORD iPitchAndFamily, LPCWSTR pszFaceName);

	operator HFONT();
};
