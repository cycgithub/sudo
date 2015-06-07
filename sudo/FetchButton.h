#pragma once
#include "afxwin.h"
#include "SudoAlgorithm.h"
#include <string>

class FetchButton :
	public CButton
{
private:
	SudoAlgorithm  *Psudo;
	bool **flag;
public:
	// CString  text;
	void  PreSubclassWindow();
	void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
public:
	FetchButton(void);
	~FetchButton(void);
	void gettext();
	DECLARE_MESSAGE_MAP()
	//afx_msg void OnBnClicked();
};

