/**	@file	ZWindow.h
*	@brief	�����ඨ��
*	@author	kaoru(SHIINA_KAORU@OURLOOK.COM)
*	@date	2020-12-10
*/

#pragma once
#include "ZControl.h"
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
class DLLAPI ZWindow : public ZControl
{
public:
	ZWindow(ZString text);

	ZWindow(ZString text, int x, int y, int w, int h);

	ZWindow(ZString text, int x, int y, int w, int h, WindowType type = Sizable);

	void SetWindowType(WindowType type);

	/** @brief ��Ҫ���øú���
	*/
	void Init(HANDLE handle);

	/** @brief ע�Ტ��������
	*/
	void Create();
};
