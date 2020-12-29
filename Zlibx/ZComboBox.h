#pragma once

#include "ZControl.h"

enum class DLLAPI ComboBoxStyle
{
	DropDown,
	Simple,
	DropDownList
};

class DLLAPI ZComboBox :
	public ZControl
{
	static ZString type;
	static BOOL isRegistered;

	static std::map<HWND, ZComboBox*> comboBoxList;
	static ZComboBox* GetComboBox(HWND hWnd);

	ZFont font;
	void SetDefFont();

	DWORD style;
	void SetStyle(ComboBoxStyle style);
public:
	ZComboBox(int x, int y, int w, int h, ComboBoxStyle style = ComboBoxStyle::DropDownList);

	void Init(HWND hWnd);

	void SetFont(ZFont font);

	void AddItem(ZString text);
	void RemoveAt(UINT pos);
	UINT Find(ZString text);
	void Update(UINT pos, ZString text);
	void Insert(UINT pos, ZString text);
	ZString GetText(UINT pos);

	void SetSelectedIndex(UINT index);
	UINT GetSelectedIndex();

	void RemoveAll();
	UINT Count();
};
