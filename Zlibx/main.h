/**	@file	main.h
*	@brief	文档主页和通用声明
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

/**@brief 导出API开关
*/
#ifdef DLL
#define DLLAPI __declspec(dllexport)
#else
#define DLLAPI __declspec(dllimport)
/**
 * 隐藏控制台
 * 当将Zlibx作为DLL使用时，请勿打开此开关
 */
#ifdef HIDE_CONSOLE
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )
#endif
#endif