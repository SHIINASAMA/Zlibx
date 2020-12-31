/**
 * \file   ZComboBox.h
 * \brief  ������ؼ�������
 *
 * \author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * \date   2020-12-29
 */

#pragma once
#pragma warning(disable: 4251)

#include "ZControl.h"

 /**
  * \brief ��������
  */
enum class DLLAPI ComboBoxStyle
{
	/**
	 * \brief �������ı����������б���ѡ��
	 */
	DropDown,
	/**
	 * \brief �������ı������б���ѡ���б��һֱ��ʾ
	 */
	 Simple,
	 /**
	  * \brief ֻ���������б���ѡ��
	  */
	  DropDownList
};

/**
 * \brief ZComboBox ��
 *
 * \brief һ���������ؼ���
 *
 * \image html ZComboBox.png
 */
class DLLAPI ZComboBox :
	public ZControl
{
	static ZString type;
	static BOOL isRegistered;

	static std::map<HWND, ZComboBox*> comboBoxList;
	static ZComboBox* GetComboBox(HWND hWnd);

	ZFont font;
	void SetDefFont();

	DWORD style;
	void SetStyle(ComboBoxStyle style);
public:
	/**
	 * \brief ��ʼ��һ��������ؼ�
	 *
	 * \param x		x����
	 * \param y		y����
	 * \param w		��
	 * \param h		��
	 * \param style �ؼ����
	 */
	ZComboBox(int x, int y, int w, int h, ComboBoxStyle style = ComboBoxStyle::DropDownList);

	/**
	 * �ú����ɴ��ڵ���
	 *
	 * \param hWnd ���ھ��
	 */
	void Init(HWND hWnd);

	/**
	 * \brief ���ÿؼ�����
	 *
	 * \param font Ŀ������
	 */
	void SetFont(ZFont font);

	/**
	 * \brief �����
	 *
	 * \param text ���ı�
	 */
	void AddItem(ZString text);

	/**
	 * \brief �Ƴ���
	 *
	 * \param pos ������
	 */
	void RemoveAt(UINT pos);

	/**
	 * \brief ������
	 *
	 * \param text ���ı�
	 * \return
	 */
	int Find(ZString text);

	//void Update(UINT pos, ZString text);

	/**
	 * \brief		������
	 *
	 * \param pos	Ŀ��λ������
	 * \param text	���ı�
	 */
	void Insert(UINT pos, ZString text);

	/**
	 * \brief		��ȡ���ı�
	 *
	 * \param pos	λ������
	 * \return		�ı�
	 */
	ZString GetText(UINT pos);

	/**
	 * \brief		���õ�ǰ����ֵ
	 *
	 * \param index ����ֵ
	 */
	void SetSelectedIndex(UINT index);

	/**
	 * \brief		��ȡ��ǰ����ֵ
	 *
	 * \return		��ǰ��Ӱֵ
	 */
	UINT GetSelectedIndex();

	/**
	 * \brief �Ƴ�������
	 *
	 */
	void RemoveAll();

	/**
	 * \brief ��ȡ��ǰ������
	 *
	 * \return ������
	 */
	UINT Count();
};
