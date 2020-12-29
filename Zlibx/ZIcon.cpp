/**
 * \file   ZIcon.cpp
 * \brief  图标类定义
 *
 * \author kaoru(SHIINA_KAORU@OUTLOOK.COM)
 * \date   2020-12-29
 */

#include "ZIcon.h"

ZIcon::ZIcon()
{
}

ZIcon::ZIcon(WORD ID)
{
	Load(ID);
}

ZIcon::ZIcon(ZString Path)
{
	LoadFromFile(Path);
}

void ZIcon::Load(WORD ID)
{
	this->hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(ID));
}

void ZIcon::LoadFromFile(ZString Path)
{
	this->hIcon = (HICON)LoadImage(
		NULL,
		Path,
		IMAGE_ICON,
		0, 0,
		LR_DEFAULTCOLOR |
		LR_CREATEDIBSECTION |
		LR_LOADFROMFILE
	);
}

ZIcon::operator HICON()
{
	return this->hIcon;
}

void ZIcon::operator=(HICON hIcon)
{
	this->hIcon = hIcon;
}