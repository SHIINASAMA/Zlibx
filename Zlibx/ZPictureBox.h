/**
 * \file   ZPictureBox.h
 * \brief  图片控件类声明
 *
 * \author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * \date   2020-12-24
 */

#pragma once

#include "ZControl.h"
#include "ZBitmap.h"

 /** \brief 图片的显示方式枚举 */
enum class DisplayMode
{
	/** \brief 不做任何处理 */
	None,
	/** \brief 拉伸 */
	Stretch,
	/** \brief 缩放 */
	Zoom
};

/** \brief ZPictureBox 类 */
class DLLAPI ZPictureBox : public ZControl
{
	ZString type = L"Zlibx_pictureBox";
	BOOL isRegistered = FALSE;

	DisplayMode mode = DisplayMode::Stretch;
	BOOL hasImage = FALSE;
	ZBitmap bmp;

	static std::map<HWND, const ZPictureBox*> pictureBoxList;

	static const ZPictureBox* GetPictureBox(HWND hWnd);

	static LRESULT CALLBACK ConProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	~ZPictureBox();
public:
	/**
	 * 初始化一个图片控件对象
	 *
	 * \param x		x坐标
	 * \param y		y坐标
	 * \param w		宽
	 * \param h		高
	 * \param mode	显示模式
	 */
	ZPictureBox(int x, int y, int w, int h, DisplayMode mode = DisplayMode::Stretch);

	/**
	 * 该函数由窗口调用
	 *
	 * \param hWnd 窗口句柄
	 */
	void Init(HWND hWnd);

	/**
	 * 设置图像
	 *
	 * \param bmp 目标图像
	 */
	void SetImage(ZBitmap bmp);

	/**
	 * \brief 清除图像
	 *
	 */
	void ClearIamge();
};