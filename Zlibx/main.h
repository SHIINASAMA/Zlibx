/**	@file	main.h
*	@brief	�ĵ���ҳ��ͨ�ö���
*	@author kaoru(SHIINA_KAORU@OUTLOOK.COM)
*	@date	2020-12-09
*/

#pragma once

#define DLL

/**@brief ����API����
*/
#ifdef DLL
#define DLLAPI __declspec(dllexport)
#else
#define DLLAPI __declspec(dllimport)
#endif

/**
 * ���ؿ���̨
 * ����Zlibx��ΪDLLʹ��ʱ������򿪴˿���
 */
#ifdef HIDE_CONSOLE
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )
#endif