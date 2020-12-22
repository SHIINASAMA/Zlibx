/**
 * \file   ZTextBox.h
 * \brief  �ı��༭�ؼ�������
 *
 * \author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * \date   2020-12-22
 */

#pragma once
#include "ZControl.h"

 /**
  * @brief �ؼ���ʽö��
  */
enum class DLLAPI TextBoxStyle {
	/** @brief ��ͨ����*/
	Normal,
	/** @brief �Զ����¹���*/
	MultiV,
	/** @brief �Զ������ı�*/
	Multi,
	/** @brief �������� */
	Num,
	/** @brief �������� */
	Pwd
};

/**
 * @brief �ؼ��ı���ʽö��
 */
enum class DLLAPI TextBoxTextStyle {
	/** @brief �ı����� */
	Center,
	/** @brief �ı��Ҷ��� */
	Right,
	/** @brief �ı������ */
	Left
};

/** \brief ZTextBox �� */
class ZTextBox :
	public ZControl
{
	ZString type = L"edit";
	DWORD style;

	void SetStyle(TextBoxStyle style, TextBoxTextStyle textStyle);

	void SetDefFont();

public:
	/**
	 * ��ʼ��һ���ı��༭����
	 *
	 * \param x			x����
	 * \param y			y����
	 * \param w			��
	 * \param h			��
	 * \param style		�ı�����
	 * \param textStyle �ı�������
	 */
	ZTextBox(int x, int y, int w, int h, TextBoxStyle style = TextBoxStyle::Normal, TextBoxTextStyle textStyle = TextBoxTextStyle::Left);

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

	/**
	 * �����ı����Ƿ����
	 *
	 * \param enable Ŀ��״̬
	 */
	void SetEnable(BOOL enable);
};
