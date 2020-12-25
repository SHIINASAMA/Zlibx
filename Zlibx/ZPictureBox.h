/**
 * \file   ZPictureBox.h
 * \brief  ͼƬ�ؼ�������
 *
 * \author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * \date   2020-12-24
 */

#pragma once

#include "ZControl.h"
#include "ZBitmap.h"

 /** \brief ͼƬ����ʾ��ʽö�� */
enum class DisplayMode
{
	/** \brief �����κδ��� */
	None,
	/** \brief ���� */
	Stretch,
	/** \brief ���� */
	Zoom
};

/** \brief ZPictureBox �� */
class DLLAPI ZPictureBox : public ZControl
{
	ZString type = L"Zlibx_pictureBox";
	BOOL isRegistered = FALSE;

	DisplayMode mode = DisplayMode::Stretch;
	BOOL hasImage = FALSE;
	ZBitmap bmp;

	static std::map<HWND, const ZPictureBox*> pictureBoxList;

	static const ZPictureBox* GetPictureBox(HWND hWnd);

	static LRESULT CALLBACK ConProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	~ZPictureBox();
public:
	/**
	 * ��ʼ��һ��ͼƬ�ؼ�����
	 *
	 * \param x		x����
	 * \param y		y����
	 * \param w		��
	 * \param h		��
	 * \param mode	��ʾģʽ
	 */
	ZPictureBox(int x, int y, int w, int h, DisplayMode mode = DisplayMode::Stretch);

	/**
	 * �ú����ɴ��ڵ���
	 *
	 * \param hWnd ���ھ��
	 */
	void Init(HWND hWnd);

	/**
	 * ����ͼ��
	 *
	 * \param bmp Ŀ��ͼ��
	 */
	void SetImage(ZBitmap bmp);

	/**
	 * \brief ���ͼ��
	 *
	 */
	void ClearIamge();
};