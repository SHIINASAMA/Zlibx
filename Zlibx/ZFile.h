/**@file	ZFile.h
* @brief	文件类声明
* @author	kaoru(SHIINA_KAORU@OUTLOOK.COM)
* @date		2020-11-28
*/

#pragma once

#include "ZString.h"
#include "main.h"
#include <iostream>
#include <fstream>
#include <istream>

/**@brief ZFile 类
*/
class DLLAPI ZFile
{
public:
	/**@brief		向特定文件写入一行
	* @param path	外部资源路径
	* @param str	写入的字符串
	* @param append 是否添加到尾部
	* @retval		写入是否成功
	*/
	static BOOL WriteLine(ZString path, ZString str, BOOL append = TRUE);

	/**@brief		向特定文件写入字符
	* @param path	外部资源路径
	* @param ch		写入的字符
	* @param append	写入是否成功
	*/
	static BOOL Write(ZString path, WChar ch, BOOL append = TRUE);

	/**@brief		从特定文件读取一行
	* @param path	外部文件路径
	* @retval		读取的字符串
	*/
	static ZString ReadLine(ZString path);

	/**@brief		从特定文件读取字符
	* @param path	外部文件路径
	*/
	static WChar Read(ZString path);

	/**@brief		判断文件是否存在
	* @param path	文件路径
	* @retval		结果
	*/
	static BOOL Exists(ZString path);

private:
	FILE* file;

public:
	/**@brief		以文件路径初始化一个ZFile对象
	*/
	ZFile(ZString path);

	/**@brief		判断文件是否打开成功，初始化后应该手动调用
	* @retval		结果
	*/
	BOOL IsGood();

	/**@brief		写入一个字符
	* @param ch		要写入的字符
	* @retval		写入是否成功
	*/
	BOOL Write(WChar ch);

	/**@brief		写入字符串
	* @param str	要写入的字符串
	* @retval		写入是否成功
	*/
	BOOL WriteLine(ZString str);

	/**@brief		读取一个字符
	* @retval		读取到的字符，需要判断非空
	*/
	WChar Read();

	/**@brief		读取字符串
	* @retval		读取到的字符串，需要判断非空
	*/
	ZString ReadLine();

	/**@brief		关闭当前文件
	*/
	void Close();
};