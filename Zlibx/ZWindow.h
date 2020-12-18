#pragma once

#include "ZControl.h"
#include <map>

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

class DLLAPI ZWindow
{
protected:
	HWND hWnd;
	DWORD style;
	ZRect rect;
	ZString text;
	HINSTANCE hInstance;

private:
	void SetStyle(WindowStyle style);

	static std::map<HWND, const ZWindow*> windowMap;

	static const ZWindow* GetWindow(HWND hWnd);

	static LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	~ZWindow();
public:
	ZWindow(ZString text, int x, int y, int w, int h, WindowStyle style = WindowStyle::Sizable);

	void Create();

	void Run();

	void Add(ZControl* con);
};