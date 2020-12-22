/**
 * \file   ZWindow.h
 * \brief  ����������
 *
 * \author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * \date   2020-12-19
 */

#pragma once

#include "ZControl.h"

 /** \brief ��������ö�� */
enum class DLLAPI WindowStyle
{
	/** \brief �ޱ߿�*/
	None,
	/** \brief �̶��ĵ��б߿�*/
	FixedSingle,
	/** \brief �̶�����ά�߿�*/
	Fixed3D,
	/** \brief �̶��ĶԻ�����ʽ�Ĵֱ߿�*/
	FixedDialog,
	/** \brief �ɵ�����С�ı߿�*/
	Sizable,
	/** \brief ���ɵ�����С�Ĺ��ߴ��ڱ߿�*/
	FixedToolWindow,
	/** \brief �ɵ�����С�Ĺ��ߴ��ڱ߿�*/
	SizableToolWindow,
};

/** \brief ���巵��ֵ���� */
enum class DLLAPI DialogResult {
	/** \brief �� */
	Ok,
	/** \brief �� */
	No
};

/** \brief ZWindow �� */
class DLLAPI ZWindow
{
protected:
	/** \brief ������ */
	HWND hWnd;
	/** \brief ������ */
	DWORD style;
	/** \brief �������� */
	ZRect rect;
	/** \brief �����ı� */
	ZString text;
	/** \brief ����ʵ����� */
	HINSTANCE hInstance;

private:
	static ZString type;
	static BOOL isRegistered;

	//GDI+
	static GdiplusStartupInput	gdiplusStartupInput;
	static ULONG_PTR			gdiplusToken;
	static UINT					count;

	void SetStyle(WindowStyle style);

	static LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	~ZWindow();
public:
	/**
	 * ��ʼ��һ���������
	 *
	 * \param text	�������
	 * \param x		x����
	 * \param y		y����
	 * \param w		��
	 * \param h		��
	 * \param style ������
	 */
	ZWindow(ZString text, int x, int y, int w, int h, WindowStyle style = WindowStyle::Sizable);

	/** \brief ע�Ტ�������� */
	void Create();

	/** \brief ���д��� */
	void Run();

	/**
	 * \brief ������ӿؼ�.
	 *
	 * \param con Ŀ��ؼ�
	 */
	void Add(ZControl* con);

	/**
	 * \brief ��Ŀ�괰���Ƴ��ؼ�
	 *
	 * \param con Ŀ��ؼ�
	 */
	void Remove(ZControl* con);
};