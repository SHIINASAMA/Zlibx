/**
 * \file   ZLabel.h
 * \brief  �ı��ؼ�������
 *
 * \author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * \date   2020-12-19
 */

#pragma once

#include "ZControl.h"

 /**
  * \brief ZLabel ��
  */
class ZLabel :
	public ZControl
{
	static ZString type;
	static BOOL isRegistered;
	WNDCLASSEX wcex;

	ZString text;
	ZFont font;
	ZColor textColol{ 0,0,0 };

	static std::map<HWND, const ZLabel*> labelMap;

	static const ZLabel* GetLabel(HWND hWnd);

	static LRESULT CALLBACK ConProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	void SetDefFont();

	~ZLabel();

public:
	/**
	 * ��ʼ��һ���ı��ؼ�����
	 *
	 * \param text	�ı�����
	 * \param x		x����
	 * \param y		y����
	 * \param w		��
	 * \param h		��
	 */
	ZLabel(ZString text, int x, int y, int w, int h);

	/**
	 * �ú����ɴ��ڵ���
	 *
	 * \param hWnd ���ھ��
	 */
	void Init(HWND hWnd);

	/**
	 * ��������
	 *
	 * \param font Ŀ������
	 */
	void SetFont(ZFont font);
};