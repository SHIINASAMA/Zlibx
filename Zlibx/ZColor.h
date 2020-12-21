/**@file	ZColor.h
* @brief	颜色类声明
* @author	kaoru(SHIINA_KAORU@OUTLOOK.COM)
* @date		2020-12-09
*/

#pragma once

#include <Windows.h>
#include "main.h"

/**	@brief ZColor 类
*/
class DLLAPI ZColor
{
private:
	COLORREF color;

public:
	/**@brief 根据RGB值初始化一个ZColor对象
	* @param R 红
	* @param G 绿
	* @param B 蓝
	*/
	ZColor(BYTE R, BYTE G, BYTE B);

	operator COLORREF();
	void operator=(COLORREF color);

	/**@brief 获取红值
	* @retval 结果
	*/
	BYTE GetRVar();

	/**@brief 获取绿值
	* @retval 结果
	*/
	BYTE GetGVar();

	/**@brief 获取蓝值
	* @retval 结果
	*/
	BYTE GetBVar();
};
