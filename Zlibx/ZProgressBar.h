/**
 * \file   ZProgressBar.h
 * \brief	�������ؼ��ඨ��
 *
 * \author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * \date   2020-12-16
 */
#pragma once
#include "ZControl.h"
#include "ZRange.h"

 /**
  * \brief ����������
  */
enum class DLLAPI ProgressBarType
{
	/** ����ˮƽ */
	Normal,
	/** ����ƽ�� */
	Smooth,
	/** ���洹ֱ */
	NormalV,
	/** ƽ����ֱ */
	SmoothV
};

/** \brief ZProgressBar �ඨ�� */
class DLLAPI ZProgressBar : public ZControl
{
	UINT min;
	UINT max;
public:
	/**
	 * ʵ����һ���������ؼ�����
	 *
	 * \param x		x����
	 * \param y		y����
	 * \param w		��
	 * \param h		��
	 * \param min	��Сֵ
	 * \param max	���ֵ
	 * \param type	����������
	 */
	ZProgressBar(int x, int y, int w, int h, UINT min = 0, UINT max = 100, ProgressBarType type = ProgressBarType::Normal);

	/**
	 * ���ÿؼ����
	 *
	 * \param type		�ؼ���ʽ
	 * \deprecated		��ò�Ҫʹ�øú���
	 */
	void SetStyle(ProgressBarType type);

	/**
	 * ��д���ؼ����õĳ�ʼ������
	 *
	 * \param hWnd ���ؼ����
	 */
	void Init(HWND hWnd);

	/**
	 * ���ص�ǰ�Ľ���ֵ
	 *
	 * \return ����ֵ
	 */
	UINT GetValue();

	/**
	 * ���õ�ǰ�Ľ���ֵ
	 *
	 * \param value
	 */
	void SetValue(UINT value);

	/**
	 * ��ȡ��������
	 *
	 * \return ��������
	 */
	ZRange GetRange();

	/**
	 * ���ý�������
	 *
	 * \param range ��������
	 */
	void SetRange(ZRange range);

	/**
	 * ���ý�������
	 *
	 * \param min ��˵�
	 * \param max �Ҷ˵�
	 */
	void SetRange(UINT min, UINT max);
};
