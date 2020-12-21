/**	@file	ZResource.h
*	@brief	资源基类声明
*	@author kaoru(SHIINA_KAORU@OUTLOOK.COM)
*	@date	2020-12-10
*/

#pragma once

#include <Windows.h>
#include "ZString.h"
#include "main.h"

/** @brief ZResource 类
*/
class DLLAPI ZResource
{
public:
	/** @brief		从资源文件中加载
	*	@param	ID	资源ID
	*/
	virtual void Load(WORD ID) = 0;

	/** @brief			从文件中加载
	*	@param	Path	文件路径
	*/
	virtual void LoadFromFile(ZString Path) = 0;
};
