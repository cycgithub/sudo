#pragma once
#include "afxwin.h"
class NewButton :
	public CButton
{
public:
	NewButton(void);
	~NewButton(void);
	void  PreSubclassWindow();
	void setpos(int k);
	void setColor(COLORREF rgb);
	NewButton *m_pbtn1;
	NewButton *m_pbtn2;
	DECLARE_MESSAGE_MAP()
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnBnClicked();
protected:
	void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
private:
	 COLORREF m_TextColor, m_DownColor,m_UpColor;

	 int pos;
};

