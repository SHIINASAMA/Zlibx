/**
 * \file   ZIcon.h
 * \brief  图标类声明
 *
 * \author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * \date   2020-12-29
 */

#pragma once

#include "ZResource.h"

 /**
  * \brief ZIcon 类
  */
class ZIcon :
	public ZResource
{
	HICON hIcon{ 0 };
public:
	/**
	 * \brief 默认构造函数，创建一个空ZIcon对象
	 *
	 */
	ZIcon();

	/**
	 * \brief 从资源中加载一个图标
	 *
	 * \param ID 资源ID
	 */
	ZIcon(WORD ID);

	/**
	 * \brief 从文件中加载一个图标
	 *
	 * \param Path 资源路径
	 */
	ZIcon(ZString Path);

	/**
	 * \brief 从资源中加载一个图标
	 *
	 * \param ID 资源ID
	 */
	void Load(WORD ID);

	/**
	 * \brief 从文件中加载一个图标
	 *
	 * \param Path 资源路径
	 */
	void LoadFromFile(ZString Path);

	operator HICON();

	void operator=(HICON hIcon);
};
