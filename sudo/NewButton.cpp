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
	// TODO: 在此添加消息处理程序代码和/或调用默认值
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
	
	// TODO: 在此添加控件通知处理程序代码
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
56, //字体高度(旋转后的字体宽度)=56
20, //字体宽度(旋转后的字体高度)=20
2700, //字体显示角度=270°
0, //nOrientation=0
10, //字体磅数=10
FALSE, //非斜体
FALSE, //无下划线
FALSE, //无删除线
DEFAULT_CHARSET, //使用缺省字符集
OUT_DEFAULT_PRECIS, //缺省输出精度
CLIP_DEFAULT_PRECIS,//缺省裁减精度
DEFAULT_QUALITY, //nQuality=缺省值
DEFAULT_PITCH, //nPitchAndFamily=缺省值
L"宋体"); //字体名=@system


  // CDC *pdc=CDC::FromHandle(lpDrawItemStruct->hDC);
   dc.Attach(lpDrawItemStruct->hDC);//得到绘制的设备环境CDC
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
   ////得当Button上文字,这里的步骤是:1,先得到在资源里编辑的按钮的文字,
   ////然后将此文字重新绘制到按钮上,
   // //同时将此文字的背景色设为透明,这样,按钮上仅会显示文字
    const int bufSize = 512;
   TCHAR  buffer[bufSize];
    GetWindowText(buffer, bufSize);
  // int size=strlen(buffer);//得到长度
	  SetBkMode(lpDrawItemStruct->hDC,TRANSPARENT);//透明
	  //dc.SelectObject(&myFont);
	 // TextOut(lpDrawItemStruct->hDC,rc.Width(),rc.Height(),L"dsf",4);
   DrawText(lpDrawItemStruct->hDC,buffer,1,&lpDrawItemStruct->rcItem,DT_CENTER|DT_VCENTER|DT_SINGLELINE|DT_TABSTOP);//绘制文字
 
   //ModifyStyle(0,BS_PUSHBUTTON);
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

void NewButton::setpos(int k)
{
	pos=k;
}
