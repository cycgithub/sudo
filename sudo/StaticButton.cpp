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
   ////�õ�Button������,����Ĳ�����:1,�ȵõ�����Դ��༭�İ�ť������,
   ////Ȼ�󽫴��������»��Ƶ���ť��,
   // //ͬʱ�������ֵı���ɫ��Ϊ͸��,����,��ť�Ͻ�����ʾ����
    const int bufSize = 512;
   TCHAR  buffer[bufSize];
    GetWindowText(buffer, bufSize);
  // int size=strlen(buffer);//�õ�����
	  SetBkMode(lpDrawItemStruct->hDC,TRANSPARENT);//͸��
   DrawText(lpDrawItemStruct->hDC,buffer,1,&lpDrawItemStruct->rcItem,DT_CENTER|DT_VCENTER|DT_SINGLELINE|DT_TABSTOP);//��������
 
	//CBrush cb(
}

void StaticButton::OnBnClicked()
{
	GetWindowText(text);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
