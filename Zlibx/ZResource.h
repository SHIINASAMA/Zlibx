/**	@file	ZResource.h
*	@brief	��Դ��������
*	@author kaoru(SHIINA_KAORU@OUTLOOK.COM)
*	@date	2020-12-10
*/

#pragma once

#include <Windows.h>
#include "ZString.h"
#include "main.h"

/** @brief ZResource ��
*/
class DLLAPI ZResource
{
public:
	/** @brief		����Դ�ļ��м���
	*	@param	ID	��ԴID
	*/
	virtual void Load(WORD ID) = 0;

	/** @brief			���ļ��м���
	*	@param	Path	�ļ�·��
	*/
	virtual void LoadFromFile(ZString Path) = 0;
};
