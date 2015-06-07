#include "stdafx.h"
#include "StaticButton.h"


StaticButton::StaticButton(void)
{
}


StaticButton::~StaticButton(void)
{
}
BEGIN_MESSAGE_MAP(StaticButton, CButton)
	ON_CONTROL_REFLECT(BN_CLICKED, &StaticButton::OnBnClicked)
END_MESSAGE_MAP()


void StaticButton::PreSubclassWindow()
{
	CButton::PreSubclassWindow();
	ModifyStyle(0,BS_OWNERDRAW);
}


void StaticButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	CDC dc;
	dc.Attach(lpDrawItemStruct->hDC);

	CBitmap bitmap;
   bitmap.LoadBitmapW(142);
   CBrush brush1(&bitmap);

    CRect rc ;
   GetClientRect(&rc);
   dc.FillRect(&rc,&brush1);
     dc.SetTextColor(RGB(0,0,0));
   // VERIFY(lpDrawItemStruct->CtlType==ODT_BUTTON);
   ////得当Button上文字,这里的步骤是:1,先得到在资源里编辑的按钮的文字,
   ////然后将此文字重新绘制到按钮上,
   // //同时将此文字的背景色设为透明,这样,按钮上仅会显示文字
    const int bufSize = 512;
   TCHAR  buffer[bufSize];
    GetWindowText(buffer, bufSize);
  // int size=strlen(buffer);//得到长度
	  SetBkMode(lpDrawItemStruct->hDC,TRANSPARENT);//透明
   DrawText(lpDrawItemStruct->hDC,buffer,1,&lpDrawItemStruct->rcItem,DT_CENTER|DT_VCENTER|DT_SINGLELINE|DT_TABSTOP);//绘制文字
 
	//CBrush cb(
}

void StaticButton::OnBnClicked()
{
	GetWindowText(text);
	// TODO: 在此添加控件通知处理程序代码
}
