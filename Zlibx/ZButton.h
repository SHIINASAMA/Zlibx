/**
 * \file   ZButton.h
 * \brief  ��ť�ؼ�������
 *
 * \author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * \date   2020-12-19
 */
#pragma once
#include "ZControl.h"
#include <map>
class ZButton :
	public ZControl
{
	ZString type = L"Zlibx_button";
	BOOL isRegistered = FALSE;

	ZString text;
	ZFont font;
	ZColor textColor{ 0,0,0 };
	BOOL isPress = FALSE;

	CallBackFunc func;

	static std::map<HWND, const ZButton*> buttonMap;

	static const ZButton* GetButton(HWND hWnd);

	static LRESULT CALLBACK ConProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	void SetDefFont();

	~ZButton();

public:
	/**
	 * ��ʼ��һ����ť����
	 *
	 * \param text	��ť�ı�
	 * \param x		x����
	 * \param y		y����
	 * \param w		��
	 * \param h		��
	 */
	ZButton(ZString text, int x, int y, int w, int h);

	/**
	 * �ú����ɴ��ڵ���
	 *
	 * \param hWnd ���ھ��
	 */
	void Init(HWND hWnd);

	/**
	 * �󶨻ص�����
	 *
	 * \param func Ŀ�꺯��
	 */
	void Bind(CallBackFunc func);

	/**
	 * ��������
	 *
	 * \param font Ŀ������
	 */
	void SetFont(ZFont font);

	/**
	 * ����������ɫ
	 *
	 * \param color Ŀ����ɫ
	 */
	void SetTextColor(ZColor color);
};
