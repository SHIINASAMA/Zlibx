/**
 * \file   ZTextBox.h
 * \brief  �ı��ؼ��ඨ��
 *
 * \author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * \date   2020-12-13
 */

#pragma once

#include "ZControl.h"

 /**
  * @brief �ؼ���ʽö��
  */
enum DLLAPI TextBoxType {
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
enum DLLAPI TextBoxTextStyle {
	/** @brief �ı����� */
	Center,
	/** @brief �ı��Ҷ��� */
	Right,
	/** @brief �ı������ */
	Left
};

/**
 * @brief ZTextBox �ඨ��
 */
class DLLAPI ZTextBox :
	public ZControl
{
public:
	/**
	 * ʵ����һ���ı�����
	 *
	 * \param x			x����
	 * \param y			y����
	 * \param w			��
	 * \param h			��
	 * \param type		�ؼ���ʽ
	 * \param textStyle �ı���ʽ
	 */
	ZTextBox(int x, int y, int w, int h,
		TextBoxType type = TextBoxType::Normal,
		TextBoxTextStyle textStyle = TextBoxTextStyle::Left);

	/**
	 * ���ÿؼ����
	 *
	 * \param type		�ؼ���ʽ
	 * \param textStyle �ı���ʽ
	 * \deprecated		��ò�Ҫʹ�øú���
	 */
	void SetStyle(TextBoxType type,
		TextBoxTextStyle textStyle);

	/**
	 * �����ı����Ƿ����
	 *
	 * \param enable �Ƿ����
	 */
	void SetEnable(BOOL enable);

	/**
	 * ���ظ��ؼ����غ���
	 *
	 * \param hWnd ���ؼ����
	 */
	void Init(HWND hWnd);
};