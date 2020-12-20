/**	@file	main.h
*	@brief	�ĵ���ҳ��ͨ������
*	@author kaoru(SHIINA_KAORU@OUTLOOK.COM)
*	@date	2020-12-09
*/

#include <map>
#include <comdef.h>
#include <gdiplus.h>
#pragma comment(lib, "gdiplus.lib")
using namespace Gdiplus;

#pragma once

#define DLL

/**@brief ����API����
*/
#ifdef DLL
#define DLLAPI __declspec(dllexport)
#else
#define DLLAPI __declspec(dllimport)
/**
 * ���ؿ���̨
 * ����Zlibx��ΪDLLʹ��ʱ������򿪴˿���
 */
#ifdef HIDE_CONSOLE
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )
#endif
#endif