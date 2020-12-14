/**
 * \file   ZWindow.h
 * \brief  �����ඨ��
 *
 * \author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * \date   2020-12-14
 */

#pragma once

#include "ZControl.h"

 /** @brief ��������ö��
 */
enum class DLLAPI WindowType
{
	/**@brief �ޱ߿�*/
	None,
	/**@brief �̶��ĵ��б߿�*/
	FixedSingle,
	/**@brief �̶�����ά�߿�*/
	Fixed3D,
	/**@brief �̶��ĶԻ�����ʽ�Ĵֱ߿�*/
	FixedDialog,
	/**@brief �ɵ�����С�ı߿�*/
	Sizable,
	/**@brief ���ɵ�����С�Ĺ��ߴ��ڱ߿�*/
	FixedToolWindow,
	/**@brief �ɵ�����С�Ĺ��ߴ��ڱ߿�*/
	SizableToolWindow,
};

/**
 * @brief ���巵��ֵ����
 */
enum class DialogResult {
	Ok,
	No
};

class DLLAPI ZWindow
{
protected:
	HWND hWnd;

	ZString text;
	DWORD style;
	ZRect rect;

	static UINT conut;
	//static std::map<HANDLE, ZControl> controlMap;
	static LRESULT WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	static std::map<UINT, ControlFunc> ClickedFuncs;

public:
	ZWindow(ZString text,
		WindowType type = WindowType::Sizable);

	ZWindow(ZString text,
		int x, int y, int w, int h,
		WindowType type = WindowType::Sizable);

	/**	@brief ���ô�����
	*	\deprecated �ú���������ÿ���Լ����ã��û�Ҳ�����Լ���Create��������ǰ���øú���
	*/
	void SetWindowType(WindowType type);

	void Create();
	void Run();
	DialogResult RunDialog();

	void AddControl(ZControl* con);
	void RemoveControl(ZControl* con);
};
