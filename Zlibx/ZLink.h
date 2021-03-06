/**
 * \file   ZLink.h
 * \brief  链接控件类声明
 *
 * \author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * \date   2020-12-27
 */

#pragma once
#pragma warning(disable:4251)

#include "ZControl.h"

 /**
  * \brief ZLink 类
  *
  * \brief 一个文本链接控件类
  *
  * \image html ZLink.png
  */
class DLLAPI ZLink :
	public ZControl
{
	static ZString type;
	static BOOL isRegistered;

	ZString text;
	ZString url;
	ZFont font;
	ZColor textColor = { 83,150,206 };

	BOOL isPress = FALSE;

	static std::map<HWND, const ZLink*> linkList;

	static const ZLink* GetLink(HWND hWnd);

	static LRESULT CALLBACK ConProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	void SetDefFont();

	~ZLink();
public:
	/**
	 * \brief 初始化一个链接控件
	 *
	 * \param text	显示文本
	 * \param url	目标地址
	 * \param x		x坐标
	 * \param y		y坐标
	 * \param w		宽
	 * \param h		高
	 */
	ZLink(ZString text, ZString url, int x, int y, int w, int h);

	/**
	 * 该函数由窗口调用
	 *
	 * \param hWnd 窗口句柄
	 */
	void Init(HWND hWnd);

	/**
	 * \brief 设置控件文本
	 *
	 * \param text 目标文本
	 */
	void SetText(ZString text);

	/**
	 * \brief 获取控件文本
	 *
	 * \return 控件文本
	 */
	ZString GetText();

	/**
	 * \brief 设置URL
	 *
	 * \param url 目标URL
	 */
	void SetUrl(ZString url);

	/**
	 * \brief 获取URL
	 *
	 * \return 目标URL
	 */
	ZString GetUrl();
};
