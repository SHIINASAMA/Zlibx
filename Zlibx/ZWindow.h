/**	@file	ZWindow.h
*	@brief	�����ඨ��
*	@author	kaoru(SHIINA_KAORU@OURLOOK.COM)
*	@date	2020-12-10
*/

#pragma once
#include "ZControl.h"
#include "ZPanel.h"
#include "main.h"

/** @brief ��������ö��
*/
enum DLLAPI WindowType {
	/**@brief �ޱ߿�*/
	None,
	/**@brief �̶��ĵ��б߿�*/
	FixedSingle,
	/**@brief �̶�����ά�߿�*/
	Fixed3D,
	/**@brief �̶��ĶԻ�����ʽ�Ĵֱ߿�*/
	FixedDialog,
	/**@brief �ɵ�����С�ı�*/
	Sizable,
	/**@brief ���ɵ�����С�Ĺ��ߴ��ڱ߿�*/
	FixedToolWindow,
	/**@brief �ɵ�����С�Ĺ��ߴ��ڱ߿�*/
	SizableToolWindow,
};

/**	@brief ZWindow �ඨ��
*/
class DLLAPI ZWindow : public ZControl, public ZPanel
{
private:
	/** @brief ��Ҫ���øú���
	*/
	HANDLE Init(HANDLE handle);

	/**
	 * �ͷ���Դ
	 *
	 */
	~ZWindow();

public:
	/** @brief		ʵ���� ZWindow ����
	*	@param text �������
	*/
	ZWindow(ZString text, WindowType type = Sizable);

	/**
	 * ʵ���� ZWindow ����
	 *
	 * \param text	�������
	 * \param x		x����
	 * \param y		y����
	 * \param w		��
	 * \param h		��
	 * \param type	������
	 */
	ZWindow(ZString text, int x, int y, int w, int h, WindowType type = Sizable);

	/**	@brief ���ô�����
	*	\deprecated
	*/
	void SetWindowType(WindowType type);

	/** @brief ע�Ტ��������
	*/
	void Create();

	/**
	 * չʾ����
	 */
	void Run();

	/**
	 * ������ӿؼ�
	 *
	 * \param con
	 */
	void AddControl(ZControl* con);

	/**
	 * �Ӵ����Ƴ��ؼ�
	 *
	 * \param id
	 */
	void RemoveControl(DWORDLONG id);
};
