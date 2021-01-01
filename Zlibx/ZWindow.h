/**
 * \file   ZWindow.h
 * \brief  ����������
 *
 * \author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * \date   2020-12-19
 */

#pragma once
#pragma warning(disable:4251)

#include "ZControl.h"
#include "ZIcon.h"

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
enum class DLLAPI DialogResult
{
	/** \brief �� */
	Ok,
	/** \brief �� */
	No
};

/**
 * \brief ZWindow ��
 *
 * \brief ������
 *
 * \image html SimpleDemo.png
 */
class DLLAPI ZWindow : public ZControl
{
protected:
	/** \brief ������ */
	HWND hWnd{ 0 };
	/** \brief ������ */
	DWORD style{ 0 };
	/** \brief �������� */
	ZRect rect;
	/** \brief �����ı� */
	ZString text;
	/** \brief ����ʵ����� */
	HINSTANCE hInstance{ 0 };

	/**
	 * \brief �����������
	 *
	 * \param hWnd ��������
	 *
	 */
	void Init(HWND hWnd);
	//todo:������
private:
	static ZString type;
	static BOOL isRegistered;

	//GDI+
	static GdiplusStartupInput	gdiplusStartupInput;
	static ULONG_PTR			gdiplusToken;
	static UINT					count;

	void SetStyle(WindowStyle style);

	static std::map<HWND, const ZWindow*> windowList;

	static const ZWindow* GetWindow(HWND hWnd);

	static LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	~ZWindow();

	static void UpdateRect(ZWindow* win);
public:
	/**
	 * \brief ��ʼ��һ���������
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

	/**
	 * \brief ���ô��������ʾ��֧�ֶ���ʾ��
	 *
	 */
	void ShowCenter();

	/**
	 * \brief ���ÿؼ�λ��
	 *
	 * \param point ԭ������
	 */
	void SetPosition(ZPoint point);

	/**
	 * \brief ��ȡ�ؼ�λ��
	 *
	 * \return ԭ������
	 */
	ZPoint GetPosition();

	/**
	 * \brief ���ÿؼ����
	 *
	 * \param w ��
	 */
	void SetWidth(UINT w);

	/**
	 * \brief ��ȡ�ؼ����
	 *
	 * \return ��
	 */
	UINT GetWidth();

	/**
	 * \brief ���ÿؼ��߶�
	 *
	 * \param h ��
	 */
	void SetHeight(UINT h);

	/**
	 * \brief ��ȡ�ؼ��߶�
	 *
	 * \return ��
	 */
	UINT GetHeight();

	/**
	 * \brief ���ÿؼ��ı�
	 *
	 * \param text �ı�
	 */
	void SetText(ZString text);

	/**
	 * \brief ��ȡ�ؼ��ı�
	 *
	 * \return �ı�
	 */
	ZString GetText();

	/**
	 * \brief ���ô���ͼ��
	 *
	 * \param icon Ŀ��ͼ��
	 */
	void SetIcon(ZIcon icon);
};