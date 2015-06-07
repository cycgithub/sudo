#include "stdafx.h"
#include "NewButton.h"


NewButton::NewButton(void)
{
	m_TextColor=RGB(255,255,255);
}


NewButton::~NewButton(void)
{
}
BEGIN_MESSAGE_MAP(NewButton, CButton)
	ON_WM_MOUSEMOVE()
	ON_CONTROL_REFLECT(BN_CLICKED, &NewButton::OnBnClicked)
END_MESSAGE_MAP()


void NewButton::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	/*ShowWindow(SW_HIDE);
	m_pbtn1->ShowWindow(SW_SHOW);*/
	CButton::OnMouseMove(nFlags, point);
}

void NewButton::PreSubclassWindow()
{
	CButton::PreSubclassWindow();
	ModifyStyle(0,BS_OWNERDRAW);
}
void NewButton::OnBnClicked()
{
	//CClientDC cd(this);
	//CClientDC *cd1;
	////cd1=GetWindowDC();
	////cd=GetDC();
	//CPen cp(PS_SOLID,3,RGB(255,0,0));
	//
	//cd.MoveTo(1,1);
	//cd.LineTo(100,100);
	//cd.SelectObject(&cp);
	SetWindowText(text);
	char c=text[0];
	sudo.setdata(c,pos);
	
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
void NewButton::setColor(COLORREF rgb)
{
	m_TextColor=rgb;
	//Invalidate();
	CRect cr;
	GetClientRect(&cr);
	InvalidateRect(&cr);
}

void NewButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
   CDC dc;
   CFont myFont;
   myFont.CreateFont(
56, //����߶�(��ת���������)=56
20, //������(��ת�������߶�)=20
2700, //������ʾ�Ƕ�=270��
0, //nOrientation=0
10, //�������=10
FALSE, //��б��
FALSE, //���»���
FALSE, //��ɾ����
DEFAULT_CHARSET, //ʹ��ȱʡ�ַ���
OUT_DEFAULT_PRECIS, //ȱʡ�������
CLIP_DEFAULT_PRECIS,//ȱʡ�ü�����
DEFAULT_QUALITY, //nQuality=ȱʡֵ
DEFAULT_PITCH, //nPitchAndFamily=ȱʡֵ
L"����"); //������=@system


  // CDC *pdc=CDC::FromHandle(lpDrawItemStruct->hDC);
   dc.Attach(lpDrawItemStruct->hDC);//�õ����Ƶ��豸����CDC
   //CBrush  brush(RGB(169,169,169));
   CBitmap bitmap;
   bitmap.LoadBitmapW(142);
   CBrush brush1(&bitmap);
   CBrush  brush(RGB(250,250,250));
   CRect rc ;
   GetClientRect(&rc);
   dc.FillRect(&rc,&brush1);
   CPen cp(PS_SOLID,1,RGB(0,0,255));
    dc.SelectObject(&cp);
	
   dc.MoveTo(1,1);
   dc.LineTo(1,38);
  // dc.MoveTo(1,38);
   dc.LineTo(38,38);
  // dc.MoveTo(40,40);
   dc.LineTo(38,1);
  // dc.MoveTo(40,1);
   dc.LineTo(1,1);
  
   //dc.SetBkColor(RGB(0,191,255));
   dc.SetTextColor(m_TextColor);
   // VERIFY(lpDrawItemStruct->CtlType==ODT_BUTTON);
   ////�õ�Button������,����Ĳ�����:1,�ȵõ�����Դ��༭�İ�ť������,
   ////Ȼ�󽫴��������»��Ƶ���ť��,
   // //ͬʱ�������ֵı���ɫ��Ϊ͸��,����,��ť�Ͻ�����ʾ����
    const int bufSize = 512;
   TCHAR  buffer[bufSize];
    GetWindowText(buffer, bufSize);
  // int size=strlen(buffer);//�õ�����
	  SetBkMode(lpDrawItemStruct->hDC,TRANSPARENT);//͸��
	  //dc.SelectObject(&myFont);
	 // TextOut(lpDrawItemStruct->hDC,rc.Width(),rc.Height(),L"dsf",4);
   DrawText(lpDrawItemStruct->hDC,buffer,1,&lpDrawItemStruct->rcItem,DT_CENTER|DT_VCENTER|DT_SINGLELINE|DT_TABSTOP);//��������
 
   //ModifyStyle(0,BS_PUSHBUTTON);
  // if (lpDrawItemStruct->itemState&ODS_SELECTED)//�����°�ťʱ�Ĵ���
  // {////�ػ���������
  //       CBrush brush(m_DownColor);
  //        dc.FillRect(&(lpDrawItemStruct->rcItem),&brush);//���û�ˢbrush�������ο�
  //       //��Ϊ����������ػ�,��������ҲҪ�ػ�
  //       DrawText(lpDrawItemStruct->hDC,buffer,1,&lpDrawItemStruct->rcItem,DT_CENTER|DT_VCENTER|DT_SINGLELINE|DT_TABSTOP);
  //        SetBkMode(lpDrawItemStruct->hDC,TRANSPARENT);
  //  }
  //else//����ť���������ߵ���ʱ
  //  {
  //         CBrush brush(m_UpColor);
  //          dc.FillRect(&(lpDrawItemStruct->rcItem),&brush);//
  //          DrawText(lpDrawItemStruct->hDC,buffer,1,&lpDrawItemStruct->rcItem,DT_CENTER|DT_VCENTER|DT_SINGLELINE|DT_TABSTOP);
  //          SetBkMode(lpDrawItemStruct->hDC,TRANSPARENT);
  //   }
  //  if ((lpDrawItemStruct->itemState&ODS_SELECTED)&&(lpDrawItemStruct->itemAction &(ODA_SELECT|ODA_DRAWENTIRE)))
  //   {//ѡ���˱��ؼ�,�����߿�
  //             COLORREF fc=RGB(255-GetRValue(m_UpColor),255-GetGValue(m_UpColor),255-GetBValue(m_UpColor));
  //           CBrush brush(fc);
  //          dc.FrameRect(&(lpDrawItemStruct->rcItem),&brush);//�û�ˢbrush�������α߿�
  //     }
  //   if (!(lpDrawItemStruct->itemState &ODS_SELECTED) &&(lpDrawItemStruct->itemAction & ODA_SELECT))
  //       {
  //        CBrush brush(m_UpColor); //���Ƶ�ѡ��״̬����,ȥ���߿�
  //       dc.FrameRect(&lpDrawItemStruct->rcItem,&brush);//}
  //      dc.Detach();
	 //}
}

void NewButton::setpos(int k)
{
	pos=k;
}
