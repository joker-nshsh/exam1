// MyDlgo.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC16.h"
#include "MyDlgo.h"
#include "afxdialogex.h"


// MyDlgo 对话框

IMPLEMENT_DYNAMIC(MyDlgo, CDialogEx)

MyDlgo::MyDlgo(CWnd* pParent /*=NULL*/)
	: CDialogEx(MyDlgo::IDD, pParent)
{

}

MyDlgo::~MyDlgo()
{
}

void MyDlgo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MyDlgo, CDialogEx)
	ON_WM_CLOSE()

	ON_BN_CLICKED(IDOK, &MyDlgo::OnBnClickedOk)
END_MESSAGE_MAP()


// MyDlgo 消息处理程序


void MyDlgo::OnClose()
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);


	CString s = _T("关闭对话框");
	dc.TextOutW(400, 200, s);
	Invalidate();

	CDialogEx::OnClose();
}


void MyDlgo::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	
	CDialogEx::OnOK();
}
