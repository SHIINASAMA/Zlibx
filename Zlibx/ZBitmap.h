/**
 * \file   ZBitmap.h
 * \brief  位图类声明
 *
 * \author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * \date   2020-12-17
 */

#pragma once
#include "ZResource.h"

 /** \brief ZBitmap 类 */
class DLLAPI ZBitmap :
	public ZResource
{
private:
	HBITMAP hbmp{ 0 };

public:
	/**
	 * \brief 创建空对象
	 */
	ZBitmap();

	/**
	 * \brief 从资源文件中加载位图
	 *
	 * \param ID 位图资源ID
	 */
	ZBitmap(WORD ID);

	/**
	 * \brief 从外部文件中加载位图
	 *
	 * \param Path 位图路径
	 */
	ZBitmap(ZString Path);

	/**
	 * \brief 从资源文件中加载位图
	 *
	 * \param ID 位图资源ID
	 */
	void Load(WORD ID);

	/**
	 * \brief 从外部文件中加载位图
	 *
	 * \param Path 位图路径
	 */
	void LoadFromFile(ZString Path);

	void operator=(HBITMAP hBmp);
	operator HBITMAP();
	operator BITMAP();
};
