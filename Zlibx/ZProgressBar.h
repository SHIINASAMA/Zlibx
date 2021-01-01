/**
 * \file   ZProgressBar.h
 * \brief  进度条控件类声明
 *
 * \author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * \date   2021-01-01
 */

#pragma once
#include "ZControl.h"
#include "ZRange.h"

 /**
  * \brief ZProgressBar 类
  *
  * \brief 一个进度条控件
  *
  * \image html ZProgressBar.png
  */
class DLLAPI ZProgressBar :
	public ZControl
{
	static ZString type;
	static BOOL isRegistered;

	static std::map<HWND, ZProgressBar*> progressBarList;
	static ZProgressBar* GetProgressBar(HWND hWnd);

	static LRESULT CALLBACK ConProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	~ZProgressBar();

	ZFont font;

	ZRange range{ 0,100 };
	int pos = 0;
public:
	/**
	 * \brief 实例化一个进度条类
	 *
	 * \param x	x坐标
	 * \param y	y坐标
	 * \param w	宽
	 * \param h	高
	 */
	ZProgressBar(int x, int y, int w, int h);

	/**
	 * 该函数由窗口调用
	 *
	 * \param hWnd 窗口句柄
	 */
	void Init(HWND hWnd);

	/**
	 * \brief 设置进度值
	 *
	 * \param pos 进度值
	 */
	void SetValue(int pos);

	/**
	 * \brief 步进
	 */
	void MakeStep();

	/**
	 * \brief 获取当前进度值
	 *
	 * \return 进度值
	 */
	int GetValue();
};
