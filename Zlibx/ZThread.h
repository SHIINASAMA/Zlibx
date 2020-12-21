/**	@file	ZThread.h
*	@brief	�߳�������
*	@author kaoru(SHIINA_KAORU@OUTLOOK.COM)
*	@date	2020-12-10
*/

#pragma once

#include <Windows.h>
#include "main.h"

/**@brief ������ַ
*/
#define FUNC LPTHREAD_START_ROUTINE

/**@brief ����
*/
#define PARAM LPVOID

/**@brief	����ת����
* @param X	ԭ����
*/
#define MAKEPARAM(X) ((LPVOID)X)

/**@brief ZThread ��
*/
class DLLAPI ZThread
{
private:
	DWORD Id = NULL;
	HANDLE hThread = NULL;
	FUNC func;
	PARAM param;

public:
	/**@brief		��ʼ��һ��ZThread����
	* @param func	������ַ
	* @param param	��������
	*/
	ZThread(FUNC func, PARAM param);

	/**@brief �����߳�
	*/
	void Run();

	/**@brief �����߳� \n ע�⣺\n�̵߳Ľ���Ӧ����ִ�к����ڲ����˳��������ǿ�ʹ�øú���ǿ���˳�
	*/
	void Stop();
};