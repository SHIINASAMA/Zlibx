/**
 * \file   ZListBox.h
 * \brief  �б�ؼ�������
 *
 * \author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * \date   2020-12-31
 */

#pragma once
#pragma warning(disable: 4251)
#include "ZControl.h"

 /**
  * \brief ZListBox ��
  *
  * \brief һ���б�ؼ���
  *
  * \image html ZListBox.png
  */
class DLLAPI ZListBox :
	public ZControl
{
	static ZString type;
	static BOOL isRegistered;

	static std::map<HWND, ZListBox*> listBoxList;
	static ZListBox* GetListBox(HWND hWnd);

	static WNDPROC oldProc;
	static LRESULT CALLBACK ConProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	void SetDefFont();

	void SetFont(ZFont font);

	~ZListBox();
public:
	/**
	 * \brief ��ʼ��һ���б�ؼ�����
	 *
	 * \param x	x����
	 * \param y	y����
	 * \param w	��
	 * \param h	��
	 */
	ZListBox(int x, int y, int w, int h);

	/**
	 * \brief �ú����ɴ��ڵ���
	 *
	 * \param hWnd ���ھ��
	 */
	void Init(HWND hWnd);

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
