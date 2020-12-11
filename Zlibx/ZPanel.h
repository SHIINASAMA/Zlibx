/**@file   ZPanel.h
 * @brief  面板类定义
 *
 * @author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * @date   2020-12-11
 */

#pragma once

#include <map>
#include <Windows.h>
#include "ZControl.h"
#include "main.h"

 /**
  * @brief ZPanel 类定义
  */
class DLLAPI ZPanel
{
protected:
	//TODO:映射关系有误
	/**
	 * @brief ID与句柄的映射集合
	 */
	std::map<DWORDLONG, HANDLE> IDMAP;

public:
	/**
	 * @brief 向面板添加控件
	 *
	 * @param con 目标控件
	 */
	virtual void AddControl(ZControl* con) = 0;

	/**
	 * 从面板移除控件
	 *
	 * @param id 目标id
	 */
	virtual void RemoveControl(DWORDLONG id) = 0;
};
