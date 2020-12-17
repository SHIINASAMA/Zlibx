/**
 * \file   ZBitmap.cpp
 * \brief  位图类实现
 *
 * \author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * \date   2020-12-17
 */
#include "ZBitmap.h"

void ZBitmap::Load(WORD ID)
{
	this->hbmp = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(ID));
}

void ZBitmap::LoadFromFile(ZString Path)
{
	this->hbmp = (HBITMAP)LoadImage(
		NULL,
		Path,
		IMAGE_BITMAP,
		0, 0,
		LR_LOADFROMFILE | LR_CREATEDIBSECTION
	);
}

BITMAP ZBitmap::GetBitmap()
{
	BITMAP bmp;
	GetObject(hbmp, sizeof(bmp), &bmp);
	return  bmp;
}

void ZBitmap::operator=(HBITMAP hBmp)
{
	this->hbmp = hBmp;
}

ZBitmap::operator HBITMAP()
{
	return this->hbmp;
}