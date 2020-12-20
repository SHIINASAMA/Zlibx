/**@file	ZDebug.h
* @brief	调试类声明
* @author	kaoru(SHIINA_KAORU@OUTLOOK.COM)
* @date		2020-11-30
*/

#pragma once
#include <Windows.h>
#include "ZString.h"
#include "main.h"

/**@brief ZDebug 类
*/
class DLLAPI ZDebug
{
public:
	/**@brief			快速显示错误信息
	* @param nodeTag	弹窗标题
	*/
	static void ShowLastError(ZString nodeTag);
};