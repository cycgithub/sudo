#include "stdafx.h"
#include "FetchButton.h"


FetchButton::FetchButton(void)
{
}


FetchButton::~FetchButton(void)
{
}
void FetchButton::gettext()
{
	//CString str;
	GetWindowText(text);
}
BEGIN_MESSAGE_MAP(FetchButton, CButton)
	//ON_CONTROL_REFLECT(BN_CLICKED, &FetchButton::OnBnClicked)
END_MESSAGE_MAP()


//void FetchButton::OnBnClicked()
//{
//	//gettext();
//	/*if(text==L"��ģʽ")
//	{
//
//	}
//	else if(text==L"�е�ģʽ")
//	{
//	}
//	else
//	{
//	}*/
//	// TODO: �ڴ���ӿؼ�֪ͨ����������
//}

void FetchButton::PreSubclassWindow()
{
	CButton::PreSubclassWindow();
	ModifyStyle(0,BS_OWNERDRAW);
	 //SetButtonStyle(BS_AUTORADIOBUTTON,0);
	//SetBkColor(RGB(0,0,255));

}

void FetchButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
   CDC dc;
   //SetButtonStyle(BS_AUTORADIOBUTTON,1);
  // CDC *pdc=CDC::FromHandle(lpDrawItemStruct->hDC);
   dc.Attach(lpDrawItemStruct->hDC);//�õ����Ƶ��豸����CDC
   //SetBkColor(lpDrawItemStruct->hDC,RGB(255,0,0));
   //CBrush  brush(RGB(169,169,169));
   CBitmap bitmap;
   bitmap.LoadBitmapW(142);
   CBrush brush1(&bitmap);
 //  CBrush  brush(RGB(250,0,0));
   CRect rc ;
   GetClientRect(&rc);
   dc.FillRect(&rc,&brush1);
   /*DrawFrameControl(lpDrawItemStruct->hDC, &lpDrawItemStruct->rcItem, 
	   DFCS_BUTTONRADIO, BS_AUTORADIOBUTTON);*/
  // SetButtonStyle(BS_AUTORADIOBUTTON,1);
/*
  // CPen cp(PS_SOLID,1,RGB(0,0,255));
  //  dc.SelectObject(&cp);
  // dc.MoveTo(1,1);
  // dc.LineTo(1,38);
  //// dc.MoveTo(1,38);
  // dc.LineTo(38,38);
  //// dc.MoveTo(40,40);
  // dc.LineTo(38,1);
  //// dc.MoveTo(40,1);
  // dc.LineTo(1,1);
  */
  
  // dc.SetBkColor(RGB(250,0,0));
   dc.SetTextColor(RGB(255,0,0));
  //  VERIFY(lpDrawItemStruct->CtlType==ODT_BUTTON);
  // //�õ�Button������,����Ĳ�����:1,�ȵõ�����Դ��༭�İ�ť������,
  // //Ȼ�󽫴��������»��Ƶ���ť��,
  //  //ͬʱ�������ֵı���ɫ��Ϊ͸��,����,��ť�Ͻ�����ʾ����
    const int bufSize = 512;
   TCHAR  buffer[bufSize];
    GetWindowText(buffer, bufSize);
	SetBkMode(lpDrawItemStruct->hDC,TRANSPARENT);//͸��
  //// int size=strlen(buffer);//�õ�����
   DrawText(lpDrawItemStruct->hDC,buffer,4,&lpDrawItemStruct->rcItem,DT_CENTER|DT_VCENTER|DT_SINGLELINE|DT_TABSTOP);//��������
  // SetBkMode(lpDrawItemStruct->hDC,TRANSPARENT);//͸��
   
  // ModifyStyle(0,BS_AUTOCHECKBOX);
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
