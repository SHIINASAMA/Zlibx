/**@file	ZDebug.h
* @brief	����������
* @author	kaoru(SHIINA_KAORU@OUTLOOK.COM)
* @date		2020-11-30
*/

#pragma once
#include <Windows.h>
#include "ZString.h"
#include "main.h"

/**@brief ZDebug ��
*/
class DLLAPI ZDebug
{
public:
	/**@brief			������ʾ������Ϣ
	* @param nodeTag	��������
	*/
	static void ShowLastError(ZString nodeTag);
};