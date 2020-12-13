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
  * ��ID����Ӧ����ת����IDMAP��Ӧ��ʽ
  *
  * \param x ID
  * \param y CALLBACKFUN
  */
#define IDMAPITEM(x, y) std::pair<UINT,CALLBACKFUNC>(x, y)

  /**
   * @brief ZPanel �ඨ��
   */
class DLLAPI ZPanel
{
protected:
	/**
	 * @brief ID������ӳ�伯��
	 */
	static std::map<UINT, CALLBACKFUNC> IDMAP;

	/**
	 * ID������
	 */
	UINT count = 0;

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
	 * @param handle Ŀ����
	 */
	virtual void RemoveControl(ZControl* con) = 0;
};

std::map<UINT, CALLBACKFUNC> ZPanel::IDMAP;
