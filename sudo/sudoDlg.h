
// sudoDlg.h : ͷ�ļ�
//

#pragma once
#include "NewButton.h"
//#include "MyButton.h"
#include "stdafx.h"
#include "FetchButton.h"
#include "StaticButton.h"
#include "afxwin.h"

// CsudoDlg �Ի���
class CsudoDlg : public CDialogEx
{
// ����
public:
	CsudoDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_SUDO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��
	


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	
	DECLARE_MESSAGE_MAP()
public:
	NewButton m_btn1;
	NewButton m_btn2;
	CButton m2;
	//CMyButton mybtn;
	//NewButton 
	CImage C_mage;
	NewButton m_btns[81];
	StaticButton s_btns[9];
	FetchButton  f_btn0;
	FetchButton  f_btn1;
	FetchButton  f_btn2;
	CString tempstr;
	afx_msg void OnBnClickedButton3();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedRadio1();
//	HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) ;
	//afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedButton2();
	CButton m_check;
	FetchButton m_fetch;
	afx_msg void OnBnClickedButton1();
	FetchButton m_fetch1;
	FetchButton m_fetch2;
	afx_msg void OnBnClickedButton4();
};
