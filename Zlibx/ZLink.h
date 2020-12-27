#pragma once
#pragma warning(disable:4351)

#include "ZControl.h"

class DLLAPI ZLink :
	public ZControl
{
	static ZString type;
	static BOOL isRegistered;

	ZString text;
	ZString url;
	ZFont font;
	ZColor textColor = { 83,150,206 };

	BOOL isPress = FALSE;

	static std::map<HWND, const ZLink*> linkList;

	static const ZLink* GetLink(HWND hWnd);

	static LRESULT CALLBACK ConProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	void SetDefFont();

	~ZLink();
public:
	/**
	 * \brief ��ʼ��һ�����ӿؼ�
	 *
	 * \param text	��ʾ�ı�
	 * \param url	Ŀ���ַ
	 * \param x		x����
	 * \param y		y����
	 * \param w		��
	 * \param h		��
	 */
	ZLink(ZString text, ZString url, int x, int y, int w, int h);

	/**
	 * �ú����ɴ��ڵ���
	 *
	 * \param hWnd ���ھ��
	 */
	void Init(HWND hWnd);

	/**
	 * \brief ���ÿؼ��ı�
	 *
	 * \param text Ŀ���ı�
	 */
	void SetText(ZString text);

	/**
	 * \brief ��ȡ�ؼ��ı�
	 *
	 * \return �ռ��ı�
	 */
	ZString GetText();

	/**
	 * \brief ����URL
	 *
	 * \param url Ŀ��URL
	 */
	void SetUrl(ZString url);

	/**
	 * \brief ��ȡURL
	 *
	 * \return Ŀ��URL
	 */
	ZString GetUrl();
};
