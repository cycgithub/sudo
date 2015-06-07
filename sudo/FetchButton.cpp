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
//	/*if(text==L"简单模式")
//	{
//
//	}
//	else if(text==L"中等模式")
//	{
//	}
//	else
//	{
//	}*/
//	// TODO: 在此添加控件通知处理程序代码
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
   dc.Attach(lpDrawItemStruct->hDC);//得到绘制的设备环境CDC
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
  // //得当Button上文字,这里的步骤是:1,先得到在资源里编辑的按钮的文字,
  // //然后将此文字重新绘制到按钮上,
  //  //同时将此文字的背景色设为透明,这样,按钮上仅会显示文字
    const int bufSize = 512;
   TCHAR  buffer[bufSize];
    GetWindowText(buffer, bufSize);
	SetBkMode(lpDrawItemStruct->hDC,TRANSPARENT);//透明
  //// int size=strlen(buffer);//得到长度
   DrawText(lpDrawItemStruct->hDC,buffer,4,&lpDrawItemStruct->rcItem,DT_CENTER|DT_VCENTER|DT_SINGLELINE|DT_TABSTOP);//绘制文字
  // SetBkMode(lpDrawItemStruct->hDC,TRANSPARENT);//透明
   
  // ModifyStyle(0,BS_AUTOCHECKBOX);
  // if (lpDrawItemStruct->itemState&ODS_SELECTED)//当按下按钮时的处理
  // {////重绘整个控制
  //       CBrush brush(m_DownColor);
  //        dc.FillRect(&(lpDrawItemStruct->rcItem),&brush);//利用画刷brush，填充矩形框
  //       //因为这里进行了重绘,所以文字也要重绘
  //       DrawText(lpDrawItemStruct->hDC,buffer,1,&lpDrawItemStruct->rcItem,DT_CENTER|DT_VCENTER|DT_SINGLELINE|DT_TABSTOP);
  //        SetBkMode(lpDrawItemStruct->hDC,TRANSPARENT);
  //  }
  //else//当按钮不操作或者弹起时
  //  {
  //         CBrush brush(m_UpColor);
  //          dc.FillRect(&(lpDrawItemStruct->rcItem),&brush);//
  //          DrawText(lpDrawItemStruct->hDC,buffer,1,&lpDrawItemStruct->rcItem,DT_CENTER|DT_VCENTER|DT_SINGLELINE|DT_TABSTOP);
  //          SetBkMode(lpDrawItemStruct->hDC,TRANSPARENT);
  //   }
  //  if ((lpDrawItemStruct->itemState&ODS_SELECTED)&&(lpDrawItemStruct->itemAction &(ODA_SELECT|ODA_DRAWENTIRE)))
  //   {//选中了本控件,高亮边框
  //             COLORREF fc=RGB(255-GetRValue(m_UpColor),255-GetGValue(m_UpColor),255-GetBValue(m_UpColor));
  //           CBrush brush(fc);
  //          dc.FrameRect(&(lpDrawItemStruct->rcItem),&brush);//用画刷brush，填充矩形边框
  //     }
  //   if (!(lpDrawItemStruct->itemState &ODS_SELECTED) &&(lpDrawItemStruct->itemAction & ODA_SELECT))
  //       {
  //        CBrush brush(m_UpColor); //控制的选中状态结束,去掉边框
  //       dc.FrameRect(&lpDrawItemStruct->rcItem,&brush);//}
  //      dc.Detach();
	 //}
}
