/**	@file	ZThread.h
*	@brief	线程类声明
*	@author kaoru(SHIINA_KAORU@OUTLOOK.COM)
*	@date	2020-12-10
*/

#pragma once

#include <Windows.h>
#include "main.h"

/**@brief 函数地址
*/
#define FUNC LPTHREAD_START_ROUTINE

/**@brief 参数
*/
#define PARAM LPVOID

/**@brief	参数转换宏
* @param X	原参数
*/
#define MAKEPARAM(X) ((LPVOID)X)

/**@brief ZThread 类
*/
class DLLAPI ZThread
{
private:
	DWORD Id = NULL;
	HANDLE hThread = NULL;
	FUNC func;
	PARAM param;

public:
	/**@brief		初始化一个ZThread对象
	* @param func	函数地址
	* @param param	函数参数
	*/
	ZThread(FUNC func, PARAM param);

	/**@brief 启动线程
	*/
	void Run();

	/**@brief 结束线程 \n 注意：\n线程的结束应该在执行函数内部先退出，而不是靠使用该函数强制退出
	*/
	void Stop();
};