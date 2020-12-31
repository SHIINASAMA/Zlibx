/**
 * \file   ZTextBox.h
 * \brief  �ı��༭�ؼ�������
 *
 * \author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * \date   2020-12-22
 */

#pragma once
#pragma warning(disable:4251)

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

/**
 * \brief ZTextBox ��
 *
 * \brief һ���ı���ؼ���
 *
 * \image html ZTextBox.png
 */
class DLLAPI ZTextBox :
	public ZControl
{
	static ZString type;
	static BOOL isRegistered;

	DWORD style;
	void SetStyle(TextBoxStyle style, TextBoxTextStyle textStyle);

	static std::map<HWND, const ZTextBox*> textBoxList;

	static const ZTextBox* GetTextBox(HWND hWnd);

	static WNDPROC oldProc;

	static LRESULT CALLBACK ConProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	void SetDefFont();

	~ZTextBox();
public:
	/**
	 * \brief ��ʼ��һ���ı��༭����
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
	 * \brief �����ı����Ƿ����
	 *
	 * \param enable Ŀ��״̬
	 */
	void SetEnable(BOOL enable);

	/**
	 * \brief ���ÿؼ��ı�
	 */
	void SetText(ZString text);

	/**
	 * \brief ��ȡ�ؼ��ı�
	  *
	 * \return �ؼ��ı�
	 */
	ZString GetText();
};
