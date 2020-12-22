/**@file	ZFile.cpp
* @brief	文件类定义
* @author	kaoru(SHIINA_KAORU@OUTLOOK.COM)
* @date		2020-11-28
*/

#include "ZFile.h"

BOOL ZFile::WriteLine(ZString path, ZString str, BOOL append)
{
	ZString formatStr;
	if (append)
	{
		formatStr = L"a+,ccs=utf-8";
	}
	else
	{
		formatStr = L"w,ccs=utf-8";
	}

	FILE* file = _wfsopen(path, formatStr, _SH_DENYNO);
	if (file == NULL)
	{
		return FALSE;
	}

	fwprintf_s(file, L"%s", (WString)str);
	fclose(file);
	return TRUE;
}

BOOL ZFile::Write(ZString path, WChar ch, BOOL append)
{
	ZString formatStr;
	if (append)
	{
		formatStr = L"a+,css=utf-8";
	}
	else
	{
		formatStr = L"w,css=utf-8";
	}

	FILE* file = _wfsopen(path, formatStr, _SH_DENYNO);
	if (file == NULL)
	{
		return FALSE;
	}

	fwprintf_s(file, L"%c", ch);
	fclose(file);
	return TRUE;
}

ZString ZFile::ReadLine(ZString path)
{
	FILE* file = _wfsopen(path, L"r,ccs=utf-8", _SH_DENYNO);
	if (file)
	{
		int len = -1;
		WChar ch;
		do
		{
			fwscanf_s(file, L"%c", &ch, (UINT)sizeof(WChar));
			len++;
		} while (ch != L'\n');
		if (len == 0)
		{
			return ZString();
		}
		else
		{
			fseek(file, 0, SEEK_SET);
			WChar* str = new WChar[len];
			fwscanf_s(file, L"%s", str, (UINT)sizeof(str));
			fclose(file);
			ZString zstr = str;
			return zstr;
		}
	}
	else
	{
		return ZString();
	}
}

WChar ZFile::Read(ZString path)
{
	FILE* file = _wfsopen(path, L"r,ccs=utf-8", _SH_DENYNO);
	if (file)
	{
		WChar ch;
		fwscanf_s(file, L"%c", &ch, (UINT)sizeof(WChar));
		return ch;
	}
	else
	{
		return NULL;
	}
}

BOOL ZFile::Exists(ZString path)
{
	FILE* file = _wfsopen(path, L"r", _SH_DENYNO);
	if (file)
	{
		fclose(file);
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

ZFile::ZFile(ZString path)
{
	file = _wfsopen(path, L"a+", _SH_DENYNO);
}

BOOL ZFile::IsGood()
{
	if (file)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

BOOL ZFile::Write(WChar ch)
{
	int len = fwprintf_s(file, L"%c", ch);
	if (len == -1)
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}

BOOL ZFile::WriteLine(ZString str)
{
	int len = fwprintf_s(file, L"%s", (WString)str);
	if (len == -1)
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}

WChar ZFile::Read()
{
	WChar ch;
	fwscanf_s(file, L"%c", &ch, (UINT)sizeof(WChar));
	return ch;
}

ZString ZFile::ReadLine()
{
	int pos = fseek(file, 0L, SEEK_CUR);
	int len = -1;
	WChar ch;
	do
	{
		fwscanf_s(file, L"%c", &ch, (UINT)sizeof(WChar));
		len++;
	} while (ch != L'\n');

	WChar* str = new WChar[len];
	fwscanf_s(file, L"%s", str, (UINT)sizeof(str));
	ZString zstr = str;
	return zstr;
}

void ZFile::Close()
{
	fclose(file);
}