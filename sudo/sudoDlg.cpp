
// sudoDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "sudo.h"
#include "sudoDlg.h"
#include "SudoAlgorithm.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CsudoDlg �Ի���



CsudoDlg::CsudoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CsudoDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CsudoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);


	DDX_Control(pDX, IDC_BUTTON2, m_check);
	DDX_Control(pDX, IDC_BUTTON1, m_fetch);
	DDX_Control(pDX, IDC_BUTTON3, m_fetch1);
	DDX_Control(pDX, IDC_BUTTON4, m_fetch2);
}

BEGIN_MESSAGE_MAP(CsudoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON3, &CsudoDlg::OnBnClickedButton3)
	ON_WM_ERASEBKGND()
	//ON_WM_DRAWITEM()
	ON_WM_LBUTTONDBLCLK()
	//ON_BN_CLICKED(IDC_RADIO1, &CsudoDlg::OnBnClickedRadio1)
	//ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON2, &CsudoDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CsudoDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, &CsudoDlg::OnBnClickedButton4)
END_MESSAGE_MAP()

#include <string>
std::string ws2s(const std::wstring& ws)
{
   
    std::string result ;
  
    return result;
}
std::wstring s2ws(const std::string& s)
{
   
    std::wstring result;

    return result;
}
// CsudoDlg ��Ϣ�������

BOOL CsudoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	C_mage.LoadFromResource(AfxGetInstanceHandle(),144);
	//ShowWindow(5);
	
  
	/*m_btn1.m_pbtn1=&m_btn2;
	m_btn2.m_pbtn1=&m_btn1;*/
	int i1=0,j1=0;
	
	CString se;
	int x=20000;
	for(int i=0;i<9;++i)
	{

		for(int j=0;j<9;++j)
		{
			char a=' ';
			se.Format(L"%c",sudo.getdata(i,j));
			//se.Format(L"%c",a);
		m_btns[i*9+j].Create(se,WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,CRect(10+j*44,10+i*44,50+j*44,50+i*44),this,x++);
				i1=50+i*44;j1=50+j*44;
		m_btns[i*9+j].ShowWindow(5);
		m_btns[i*9+j].setpos(i*9+j);
		if(se!=' ')
			m_btns[i*9+j].EnableWindow(false);
		
		}
	}

	for(int i=0;i<9;++i)
	{
		char a=i+49;
		char b=' ';
		se.Format(L"%c",a);
		s_btns[i].Create(se,WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,CRect(8+i*46,420,50+i*46,460),this,i*20000+10);
		s_btns[i].ShowWindow(5);
		//if(as_btns[i].EnableWindow(
	}
	/*f_btn0.Create(L"��ģʽ",WS_CHILD|WS_VISIBLE|BS_AUTORADIOBUTTON,CRect(i1+10,j1-300,i1+100,j1-270),this,i1*2000+j1+10);
	f_btn0.ShowWindow(5);*/
	m_fetch.Create(L"��ģʽ",WS_CHILD|WS_VISIBLE|BS_AUTORADIOBUTTON,CRect(i1+10,j1-300,i1+100,j1-270),this,IDC_BUTTON1);
	m_fetch.ShowWindow(5);
//	m_btns[0].SetWindowTextW(L"dsgdf");
	m_fetch1.Create(L"�е�ģʽ",WS_CHILD|WS_VISIBLE|BS_AUTORADIOBUTTON,CRect(i1+10,j1-225,i1+100,j1-195),this,IDC_BUTTON3);
	m_fetch1.ShowWindow(5);
	m_fetch2.Create(L"����ģʽ",WS_CHILD|WS_VISIBLE|BS_AUTORADIOBUTTON,CRect(i1+10,j1-150,i1+100,j1-120),this,IDC_BUTTON4);
	m_fetch2.ShowWindow(5);
	
	//m2=new CButton();
//	mybtn.Create(L"dsfsd",WS_CHILD,CRect(10,10,50,50),this,34);
	//mybtn.ShowWindow(5);
	
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}
//BOOL CsudoDlg::OnEraseBkgnd(CDC* pDC)
//{
//	/*CRect rc;
//	GetClientRect(&rc);
//	C_mage.BitBlt(pDC->GetSafeHdc(),rc,CPoint(0,0),SRCCOPY);
//	return TRUE;*/
//	return CDialog::OnEraseBkgnd(pDC);
//}
void CsudoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CsudoDlg::OnPaint()
{
	
	CClientDC dc(this) ;
	CPen cp;//(PS_SOLID,1,RGB(255,0,0));
	cp.CreatePen(PS_SOLID,5,RGB(255,0,0));
	dc.SelectObject(&cp);

	dc.MoveTo(8,8);
	dc.LineTo(8,400);
	for(int i=3;i<=9;i=i+3)
	{
		dc.MoveTo(8+44*i,8);
		dc.LineTo(8+44*i,400);
	}
	CPen cp1;
	cp1.CreatePen(PS_SOLID,5,RGB(0,255,0));
	dc.SelectObject(&cp);
	dc.MoveTo(8,8);
	dc.LineTo(400,8);
	for(int i=3;i<=9;i=i+3)
	{
		dc.MoveTo(8,8+44*i);
		dc.LineTo(400,8+44*i);
	}
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CsudoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CsudoDlg::OnBnClickedButton3()
{
	sudo.reset(40);
	//m_btns[0].EnableWindow(1);
	CString s1;
	for(int i=0;i<9;++i)
	{
		for(int j=0;j<9;++j)
		{
			s1.Format(L"%c",sudo.getdata(i,j));
			m_btns[i*9+j].EnableWindow(1);
	         m_btns[i*9+j].SetWindowTextW(s1);
			 if(s1!=' ')
			 {
				 m_btns[i*9+j].EnableWindow(0);
				 m_btns[i*9+j].setColor(RGB(255,0,0));
			 }
			 else
				 m_btns[i*9+j].setColor(RGB(0,0,0));
		}
	}
	/* m2.Create(L"yes",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,CRect(50,50,100,100),this,123);
	m2.ShowWindow(5);
	*/
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


BOOL CsudoDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
		CRect rc;
	GetClientRect(&rc);
	C_mage.BitBlt(pDC->GetSafeHdc(),rc,CPoint(0,0),SRCCOPY);

	// CBitmap bitmap;
	// bitmap.LoadBitmap(143);
	//CClientDC dc(this) ;
	//CBrush cb(&bitmap);
	//CRect cr;
	////GetClientRect(cr);
	//GetUpdateRect(cr);
	//dc.FillRect(cr,&cb);
	return TRUE;
	return CDialogEx::OnEraseBkgnd(pDC);
}


//void CsudoDlg::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct)
//{
//	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
//	//if(nIDCtl==IDC_BUTTON1)         //checking for the button 
// //   {
//    CDC dc;
//    RECT rect;
//    dc.Attach(lpDrawItemStruct ->hDC);   // Get the Button DC to CDC
//    
//    rect = lpDrawItemStruct->rcItem;     //Store the Button rect to our local rect.
//    
//    dc.Draw3dRect(&rect,RGB(255,255,255),RGB(0,0,0)); 
//
//    dc.FillSolidRect(&rect,RGB(100,100,255));//Here you can define the required color to appear on the Button.
//
//    UINT state=lpDrawItemStruct->itemState; //This defines the state of the Push button either pressed or not. 
//
//    if((state & ODS_SELECTED))
//    {
//        dc.DrawEdge(&rect,EDGE_SUNKEN,BF_RECT);
//
//    }
//    else
//    {
//        dc.DrawEdge(&rect,EDGE_RAISED,BF_RECT);
//    }
//
//    dc.SetBkColor(RGB(100,100,255));   //Setting the Text Background color
//    dc.SetTextColor(RGB(255,0,0));     //Setting the Text Color
//
//
//    TCHAR buffer[MAX_PATH];           //To store the Caption of the button.
//    ZeroMemory(buffer,MAX_PATH );     //Intializing the buffer to zero
//        ::GetWindowText(lpDrawItemStruct->hwndItem,buffer,MAX_PATH); //Get the Caption of Button Window 
//    
//    dc.DrawText(buffer,&rect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);//Redraw the Caption of Button Window 
//    
//    dc.Detach(); // Detach the Button DC
//  //  }                
//	CDialogEx::OnDrawItem(nIDCtl, lpDrawItemStruct);
//}

//HBRUSH CsudoDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
//{
	/* CBitmap bitmap;
	 bitmap.LoadBitmap(143);
	CClientDC dc(this) ;
	CBrush cb(&bitmap);
	CRect cr;
	GetClientRect(cr);
	dc.FillRect(cr,&cb);
	CPen cp(PS_SOLID,1,RGB(255,0,0));
	
	dc.MoveTo(9,9);
	dc.LineTo(9,450);
	dc.SelectObject(&cp);*/
//HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
//
//if(pWnd->GetDlgCtrlID()==ID)
//{
//pDC->SetTextColor(RGB(255,0,0));
//pDC->SetBkMode(TRANSPARENT);
//return (HBRUSH)GetStockObject(BLACK_BRUSH);
//}
//return hbr;
//}
void CsudoDlg::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	//CClientDC cd(this);
	//CClientDC *cd1;
	////cd1=GetWindowDC();
	////cd=GetDC();
	//CPen cp(PS_SOLID,5,RGB(255,0,0));
	//
	//cd.MoveTo(1,1);
	//cd.LineTo(1,100);
	//cd.SelectObject(&cp);
	//// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//MessageBox(L"345");w
	CDialogEx::OnLButtonDblClk(nFlags, point);
}


void CsudoDlg::OnBnClickedRadio1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


//HBRUSH CsudoDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
//{
//	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
//	 CBitmap bitmap;
//	 bitmap.LoadBitmap(143);
//	CClientDC dc(this) ;
//	CBrush cb(&bitmap);
//	CRect cr;
//	GetClientRect(cr);
////	dc.FillRect(cr,&cb);
//	pDC->FillRect(cr,&cb);
//	/*CPen cp(PS_SOLID,8,RGB(255,0,0));
//	
//	dc.MoveTo(9,9);
//	dc.LineTo(9,450);
//	dc.SelectObject(&cp);*/
//	//return (HBRUSH)GetStockObject(BLACK_BRUSH);
//	// TODO:  �ڴ˸��� DC ���κ�����
//
//
//	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
//	return hbr;
//}


void CsudoDlg::OnBnClickedButton2()
{
	//MessageBox(L"fg");
	int i;
	for(i=0;i<81;++i)
	{
		int x,y;
		if(!sudo.check1(i))
		{
			x=i/9;
			y=i%9;
			CString s;
			s.Format(L"��������ȷ������x:%d y:%d ",x+1,y+1);
			MessageBox(s);
			break;
		}
		

	}
	if(i==81)
	MessageBox(L"��ϲ�������һ��");

	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CsudoDlg::OnBnClickedButton1()
{
	//MessageBox(L"sdgfds");
	sudo.reset(50);
	//m_btns[0].EnableWindow(1);
	CString s1;
	for(int i=0;i<9;++i)
	{
		for(int j=0;j<9;++j)
		{
			s1.Format(L"%c",sudo.getdata(i,j));
			m_btns[i*9+j].EnableWindow(1);
	         m_btns[i*9+j].SetWindowTextW(s1);
			if(s1!=' ')
			 {
				 m_btns[i*9+j].EnableWindow(0);
				 m_btns[i*9+j].setColor(RGB(255,0,0));
			 }
			 else
				 m_btns[i*9+j].setColor(RGB(0,0,0));
		}
	}
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CsudoDlg::OnBnClickedButton4()
{
	sudo.reset(30);
	CClientDC dc(this);
	CDC dc1;
	//dc1.getdlgi
	//m_btns[0].EnableWindow(1);
	CString s1;
	for(int i=0;i<9;++i)
	{
		for(int j=0;j<9;++j)
		{
			s1.Format(L"%c",sudo.getdata(i,j));
			m_btns[i*9+j].EnableWindow(1);
	         m_btns[i*9+j].SetWindowTextW(s1);
			 if(s1!=' ')
			 {
				 m_btns[i*9+j].EnableWindow(0);
				 m_btns[i*9+j].setColor(RGB(255,0,0));
			 }
			 else
				 m_btns[i*9+j].setColor(RGB(0,0,0));
		}
	}
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
