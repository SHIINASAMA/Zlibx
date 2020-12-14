/**	@file	ZString.cpp
*	@brief	字符串类实现
*	@author	kaoru(SHIINA_KAORU@OUTLOOK.COM)
*	@date	2020-12-09
*/

#include "ZString.h"

ZString::ZString()
{
}

ZString::ZString(WString objStr)
{
	this->str = objStr;
}

ZString::ZString(AString objStr)
{
	Pause(objStr);
}

WString ZString::ToWString()
{
	return this->str;
}

AString ZString::ToAString()
{
	int nLen = WideCharToMultiByte(CP_ACP, 0, str, -1, NULL, 0, NULL, NULL);
	if (nLen == 0)
	{
		return NULL;
	}
	char* pResult = new char[nLen];
	WideCharToMultiByte(CP_ACP, 0, str, -1, pResult, nLen, NULL, NULL);
	return pResult;
}

int ZString::Len()
{
	if (this->str == NULL)return -1;
	WString str = this->str;
	int len = 0;
	while (*str++)
	{
		len++;
	}
	return len;
}

void ZString::Pause(WString srcStr)
{
	this->str = srcStr;
}

void ZString::Pause(AString srcStr)
{
	int nLen = MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, srcStr, -1, NULL, 0);
	if (nLen == 0)
	{
		return;
	}
	wchar_t* pResult = new wchar_t[nLen];
	MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, srcStr, -1, pResult, nLen);
	this->str = pResult;
}

int ZString::Strcmp(ZString str1, ZString str2)
{
	return lstrcmpiW(str1, str2);
}

int ZString::Strlen(ZString str)
{
	return lstrlen(str);
}

void ZString::operator=(WString str)
{
	this->str = str;
}

void ZString::operator=(WChar str[])
{
	this->str = str;
}

ZString::operator WString()
{
	return this->str;
}

WChar ZString::operator[](int index)
{
	WString str = this->str;
	str += index;
	WChar c = *str;
	return c;
}