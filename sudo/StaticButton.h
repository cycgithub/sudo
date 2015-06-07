#pragma once
#include "afxwin.h"
class StaticButton :
	public CButton
{
public:
	StaticButton(void);
	~StaticButton(void);

	void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);

	void PreSubclassWindow();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnBnClicked();
};

