/**
 * \file   ZProgressBar.h
 * \brief	进度条控件类定义
 *
 * \author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * \date   2020-12-16
 */
#pragma once
#include "ZControl.h"
#include "ZRange.h"

 /**
  * \brief 进度条类型
  */
enum class DLLAPI ProgressBarType
{
	/** 常规水平 */
	Normal,
	/** 常规平滑 */
	Smooth,
	/** 常规垂直 */
	NormalV,
	/** 平滑垂直 */
	SmoothV
};

/** \brief ZProgressBar 类定义 */
class DLLAPI ZProgressBar : public ZControl
{
	UINT min;
	UINT max;
public:
	/**
	 * 实例化一个进度条控件对象
	 *
	 * \param x		x坐标
	 * \param y		y坐标
	 * \param w		宽
	 * \param h		高
	 * \param min	最小值
	 * \param max	最大值
	 * \param type	进度条类型
	 */
	ZProgressBar(int x, int y, int w, int h, UINT min = 0, UINT max = 100, ProgressBarType type = ProgressBarType::Normal);

	/**
	 * 设置控件风格
	 *
	 * \param type		控件样式
	 * \deprecated		最好不要使用该函数
	 */
	void SetStyle(ProgressBarType type);

	/**
	 * 重写父控件调用的初始化函数
	 *
	 * \param hWnd 父控件句柄
	 */
	void Init(HWND hWnd);

	/**
	 * 返回当前的进度值
	 *
	 * \return 进度值
	 */
	UINT GetValue();

	/**
	 * 设置当前的进度值
	 *
	 * \param value
	 */
	void SetValue(UINT value);

	/**
	 * 获取进度区间
	 *
	 * \return 进度区间
	 */
	ZRange GetRange();

	/**
	 * 设置进度区间
	 *
	 * \param range 进度区间
	 */
	void SetRange(ZRange range);

	/**
	 * 设置进度区间
	 *
	 * \param min 左端点
	 * \param max 右端点
	 */
	void SetRange(UINT min, UINT max);
};
