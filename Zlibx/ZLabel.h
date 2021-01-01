/**
 * \file   ZLabel.h
 * \brief  �ı��ؼ�������
 *
 * \author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * \date   2020-12-19
 */

#pragma once
#pragma warning(disable:4251)

#include "ZControl.h"

 /**
  * \brief ZLabel ��
  *
  * \brief һ����ǩ�ؼ���
  *
  * \image html ZLabel.png
  */
class DLLAPI ZLabel :
	public ZControl
{
	static ZString type;
	static BOOL isRegistered;

	ZString text;
	ZFont font;
	ZColor textColor{ 0,0,0 };

	static std::map<HWND, const ZLabel*> labelMap;

	static const ZLabel* GetLabel(HWND hWnd);

	static LRESULT CALLBACK ConProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	void SetDefFont();

	~ZLabel();

public:
	/**
	 * \brief ��ʼ��һ���ı��ؼ�����
	 *
	 * \param text	�ı�����
	 * \param x		x����
	 * \param y		y����
	 * \param w		��
	 * \param h		��
	 */
	ZLabel(ZString text, int x, int y, int w, int h);

	/**
	 * \brief �ú����ɴ��ڵ���
	 *
	 * \param hWnd ���ھ��
	 */
	void Init(HWND hWnd);

	/**
	 * \brief ��������
	 *
	 * \param font Ŀ������
	 */
	void SetFont(ZFont font);

	/**
	 * \brief ���ÿؼ���ʾ�ı�
	 *
	 * \param text Ŀ���ı�
	 */
	void SetText(ZString text);

	/**
	 * \brief ��ȡ�ؼ��ı�
	 *
	 * \retval �ؼ��ı�
	 */
	ZString GetText();

	/**
	 * \brief ���ÿؼ��ı���ɫ
	 *
	 * \param color
	 */
	void SetTextColor(ZColor color);

	/**
	 * \brief ��ȡ�ؼ��ı���ɫ
	 *
	 * \return �ؼ��ı���ɫ
	 */
	ZColor GetTextColor();
};