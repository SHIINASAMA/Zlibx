/**@file   ZPanel.h
 * @brief  ����ඨ��
 *
 * @author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * @date   2020-12-11
 */

#pragma once

#include <map>
#include <Windows.h>
#include "ZControl.h"
#include "main.h"

 /**
  * @brief ZPanel �ඨ��
  */
class DLLAPI ZPanel
{
protected:
	//TODO:ӳ���ϵ����
	/**
	 * @brief ID������ӳ�伯��
	 */
	std::map<DWORDLONG, HANDLE> IDMAP;

public:
	/**
	 * @brief �������ӿؼ�
	 *
	 * @param con Ŀ��ؼ�
	 */
	virtual void AddControl(ZControl* con) = 0;

	/**
	 * ������Ƴ��ؼ�
	 *
	 * @param id Ŀ��id
	 */
	virtual void RemoveControl(DWORDLONG id) = 0;
};
