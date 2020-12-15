/**
 * \file   ZControl.h
 * \brief  �ؼ����ඨ��
 *
 * \author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * \date   2020-12-15
 */
#pragma once

#include <Windows.h>
#include <map>
#include <vector>
#include "main.h"
#include "ZFont.h"
#include "ZRect.h"

 /** \brief ��Ϣ���� */
enum class DLLAPI MessageType
{
	/** \brief ������Ϣ */
	Clicked,
};

/** \brief �������� */
typedef struct DLLAPI Param
{
	/** \brief ���ھ�� */
	HWND hWnd;
	/** \brief ��Ϣ���� */
	UINT uMsg;
	/** \brief ����1 */
	WPARAM wParam;
	/** \brief ����2 */
	LPARAM lParam;
}Param;

/** \brief �ص����� */
typedef DLLAPI LRESULT(*CallbackFunc)(Param);

/** \brief �ؼ�����Ϣ���ͺͻص����� */
typedef struct DLLAPI ControlFunc
{
	/** ��Ϣ������ */
	MessageType type;
	/** �ص����� */
	CallbackFunc func;
}ControlFunc;

/**
 * \brief ZControl �ඨ��
 */
class DLLAPI ZControl
{
protected:
	HWND hWnd;
	HWND phWnd;

	ZString type;
	ZString text;
	ZRect rect;
	DWORD style;

public:
	UINT id;
	std::vector<ControlFunc> funcs;

	/**
	 * ZWindow::AddControl �����øú���
	 * ������Ӧ����ɿؼ���CreateWindow�ͱ��游����ľ��
	 *
	 * \param hWnd �����ھ��
	 */
	virtual void Init(HWND hWnd) = 0;

	/**
	 * ����Ϣ
	 *
	 * \param type ��Ϣ����
	 * \param func �ص�����
	 */
	void Bind(MessageType type, CallbackFunc func);

	/**
	 * ��������
	 *
	 * \param font Ŀ������
	 */
	void SetFont(ZFont font);

	/** \brief ����Ĭ������λ������ */
	void SetDefFont();

	/**
	 * ��ȡ�ؼ��ı�
	 *
	 * \return �ؼ��ı�
	 */
	ZString GetText();

	/**
	 * ���ÿؼ��ı�
	 *
	 * \param text Ŀ���ı�
	 */
	void SetText(ZString text);

	/**
	 * �������Ͻǵ�����
	 *
	 * \param point ����
	 */
	void SetPoint(ZPoint point);

	/**
	 * ��ȡ���Ͻǵ�����
	 *
	 * \return ����
	 */
	ZPoint GetPoint();

	/**
	 * ���ÿؼ��ߴ�
	 *
	 * \param size �ߴ�
	 */
	void SetSize(ZSize size);

	/**
	 * ��ȡ�ؼ��ߴ�
	 *
	 * \return �ߴ�
	 */
	ZSize GetSize();
};
