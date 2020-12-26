/**
 * \file   ZButton.h
 * \brief  ��ť�ؼ�������
 *
 * \author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * \date   2020-12-19
 */

#pragma once
#pragma warning(disable:4251)

#include "ZControl.h"

 /** \brief ZButton �� */
class DLLAPI ZButton :
	public ZControl
{
	static ZString type;
	static BOOL isRegistered;

	ZString text;
	ZFont font;
	ZColor textColor{ 0,0,0 };
	BOOL isPress = FALSE;
	BOOL isEnable = TRUE;
	CallBackFunc func;

	static std::map<HWND, const ZButton*> buttonMap;

	static const ZButton* GetButton(HWND hWnd);

	static LRESULT CALLBACK ConProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	void SetDefFont();

	~ZButton();

public:
	/**
	 * \brief ��ʼ��һ����ť����
	 *
	 * \param text	��ť�ı�
	 * \param x		x����
	 * \param y		y����
	 * \param w		��
	 * \param h		��
	 */
	ZButton(ZString text, int x, int y, int w, int h);

	/**
	 * \brief �ú����ɴ��ڵ���
	 *
	 * \param hWnd ���ھ��
	 */
	void Init(HWND hWnd);

	/**
	 * \brief �󶨻ص�����
	 *
	 * \param func Ŀ�꺯��
	 */
	void Bind(CallBackFunc func);

	/**
	 * \brief ��������
	 *
	 * \param font Ŀ������
	 */
	void SetFont(ZFont font);

	/**
	 * \brief ����������ɫ
	 *
	 * \param color Ŀ����ɫ
	 */
	void SetTextColor(ZColor color);

	/**
	 * \brief ���ð�ť�Ƿ����
	 *
	 * \param enable Ŀ��״̬
	 */
	void SetEnable(BOOL enable);

	/**
	 * \brief ���ð�ť�ı�
	 *
	 * \param text Ŀ���ı�
	 */
	void SetText(ZString text);

	/**
	 * \brief ���ð�ť�ı�
	 *
	 * \retval �ؼ��ı�
	 */
	ZString GetText();
};
