// Dlg1.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC28.h"
#include "Dlg1.h"
#include "afxdialogex.h"


// Dlg1 对话框

IMPLEMENT_DYNAMIC(Dlg1, CDialogEx)

Dlg1::Dlg1(CWnd* pParent /*=NULL*/)
	: CDialogEx(Dlg1::IDD, pParent)
	, s3(_T(""))
{

}

Dlg1::~Dlg1()
{
}

void Dlg1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Dlg1, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &Dlg1::OnBnClickedButton2)
END_MESSAGE_MAP()


// Dlg1 消息处理程序


void Dlg1::foo2(CImage& img, int &sx, int& sy, int& w, int& h)
{
	CRect rect;
	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);
	float rect_ratio = 1.0*rect.Width() / rect.Height();
	float img_ratio = 1.0*img.GetWidth() / img.GetHeight();
	if (rect_ratio>img_ratio)
	{
		h = rect.Height();
		w = img_ratio*h;
		sx = (rect.Width() - w) / 2;
		sy = 0;
	}
	else
	{
		w = rect.Width();
		h = w / img_ratio;
		sx = 0;
		sy = (rect.Height() - h) / 2;

	}
}


void Dlg1::OnBnClickedButton2()
{
	// TODO:  在此添加控件通知处理程序代码
	CImage img;
	img.Load(s3);
	int sx = 0, sy = 0, w = 0, h = 0;
	foo2(img, sx, sy, w, h);

	CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
}



