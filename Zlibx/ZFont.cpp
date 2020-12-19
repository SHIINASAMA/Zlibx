/**@file	ZFont.cpp
* @brief	字体类定义
* @author	kaoru(SHIINA_KAORU@OUTLOOK.COM)
* @date		2020-12-10
*/

#include "ZFont.h"

ZFont::ZFont()
{
}

ZFont::ZFont(ZString FontName)
{
	Create(FontName);
}

void ZFont::Create(ZString FontName)
{
	this->font = CreateFont(15, 0, 0, 0, 0, 0, 0, 0,
		GB2312_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY, DEFAULT_PITCH, FontName);
}

void ZFont::CreateEx(int cHeight, int cWidth, int cEscapement, int cOrientation, int cWeight, DWORD bItalic, DWORD bUnderline, DWORD bStrikeOut, DWORD iCharSet, DWORD iOutPrecision, DWORD iClipPrecision, DWORD iQuality, DWORD iPitchAndFamily, LPCWSTR pszFaceName)
{
	this->font = CreateFont(cHeight, cWeight, cEscapement, cOrientation, cWeight, bItalic, bUnderline, bStrikeOut, iCharSet, iOutPrecision, iClipPrecision, iQuality, iPitchAndFamily, pszFaceName);
}

ZFont::operator HFONT()
{
	return this->font;
}