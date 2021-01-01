/**
 * \file   ZProgressBar.h
 * \brief  �������ؼ�������
 *
 * \author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * \date   2021-01-01
 */

#pragma once
#include "ZControl.h"
#include "ZRange.h"

 /**
  * \brief ZProgressBar ��
  *
  * \brief һ���������ؼ�
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
	 * \brief ʵ����һ����������
	 *
	 * \param x	x����
	 * \param y	y����
	 * \param w	��
	 * \param h	��
	 */
	ZProgressBar(int x, int y, int w, int h);

	/**
	 * �ú����ɴ��ڵ���
	 *
	 * \param hWnd ���ھ��
	 */
	void Init(HWND hWnd);

	/**
	 * \brief ���ý���ֵ
	 *
	 * \param pos ����ֵ
	 */
	void SetValue(int pos);

	/**
	 * \brief ����
	 */
	void MakeStep();

	/**
	 * \brief ��ȡ��ǰ����ֵ
	 *
	 * \return ����ֵ
	 */
	int GetValue();
};
