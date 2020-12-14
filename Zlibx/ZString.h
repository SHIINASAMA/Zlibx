/**	@file	ZString.h
*	@brief	字符串类定义
*	@author kaoru(SHIINA_KAORU@OUTLOOK.COM)
*	@date	2020-12-09
*/

#pragma once

#include <Windows.h>
#include "main.h"

/**@brief 宽字符串
*/
#define WString LPCWSTR

/**@brief 宽字符
*/
#define WChar wchar_t

/**@brief 窄字符串
*/
#define AString char*

/**@brief 窄字符
*/
#define AChar char

/**	@brief ZString 类定义
*/
class DLLAPI ZString
{
private:
	WString str;

public:
	/** @brief 注意，这会创建一个空的ZString对象
	*/
	ZString();

	/** @brief			利用WString初始化一个ZString对象
	*	@param	objStr	目标WString对象
	*/
	ZString(WString objStr);

	/** @brief			利用AString初始化一个ZString对象
	*	@param	objStr	目标AString对象
	*/
	ZString(AString objStr);

	/** @brief	得到ZString的WString对象
	*	@retval 目标对象
	*/
	WString ToWString();

	/** @brief	得到ZString的AString对象
	*	@retval	目标对象
	*/
	AString ToAString();

	/** @brief	ZString对象的字符串长度
	*	@retval	字符串长度
	*	\deprecated 存在内存风险，替代使用 ZString::Strlen
	*	\lnk Strlen
	*/
	int Len();

	/**	@brief			转换一个WString对象
	*	@param	srcStr	源字符串
	*/
	void Pause(WString srcStr);

	/**	@brief			转换一个AString对象
	*	@param	srcStr	源字符串
	*/
	void Pause(AString srcStr);

	/**
	 * 比较字符串大小
	 *
	 * \param str1 字符串1
	 * \param str2 字符串2
	 * \return 与标准库返回值相同
	 */
	static int Strcmp(ZString str1, ZString str2);

	/**
	 * 获取字符串长度
	 *
	 * \param str 目标字符串
	 * \return	  字符串长度
	 */
	static int Strlen(ZString str);

	void operator=(WString str);
	void operator=(WChar str[]);
	operator WString();
	WChar operator[](int index);
};
