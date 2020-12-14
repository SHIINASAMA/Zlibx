/**@file	ZDebug.cpp
* @brief	调试类实现
* @author	kaoru(SHIINA_KAORU@OUTLOOK.COM)
* @date		2020-12-09
*/

#include "ZDebug.h"

void ZDebug::ShowLastError(ZString nodeTag)
{
	UINT result = GetLastError();
	if (result == 0)
	{
		MessageBox(NULL, L"GetLastError()返回值为0", nodeTag, MB_OK | MB_ICONINFORMATION);
	}
	else
	{
		LPWSTR str = new WCHAR[1024];
		wsprintf(str, L"GetLastError返回值为%d，是否跳转网页查看详情？", result, sizeof(str));
		LRESULT sel = MessageBox(NULL, str, nodeTag, MB_YESNO | MB_ICONWARNING);
		if (sel == IDYES)
		{
			LPSTR url = new CHAR[1024];
			wsprintfA(url, "start https://docs.microsoft.com/en-us/search/?terms=SystemErrorCodes%d", result, sizeof(url));
			system(url);
		}
		else
		{
			return;
		}
	}
}