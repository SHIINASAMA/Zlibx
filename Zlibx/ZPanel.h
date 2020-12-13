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
  * 将ID和响应函数转换成IDMAP对应格式
  *
  * \param x ID
  * \param y CALLBACKFUN
  */
#define IDMAPITEM(x, y) std::pair<UINT,CALLBACKFUNC>(x, y)

  /**
   * @brief ZPanel 类定义
   */
class DLLAPI ZPanel
{
protected:
	/**
	 * @brief ID与句柄的映射集合
	 */
	static std::map<UINT, CALLBACKFUNC> IDMAP;

	/**
	 * ID计数器
	 */
	UINT count = 0;

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
	 * @param handle 目标句柄
	 */
	virtual void RemoveControl(ZControl* con) = 0;
};

std::map<UINT, CALLBACKFUNC> ZPanel::IDMAP;
