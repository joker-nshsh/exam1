// MyDlgo.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC17.h"
#include "MyDlgo.h"
#include "afxdialogex.h"


// MyDlgo 对话框

IMPLEMENT_DYNAMIC(MyDlgo, CDialogEx)

MyDlgo::MyDlgo(CWnd* pParent /*=NULL*/)
	: CDialogEx(MyDlgo::IDD, pParent)
	, x(_T(""))
	, y(_T(""))
{

}

MyDlgo::~MyDlgo()
{
}

void MyDlgo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, x);
	DDX_Text(pDX, IDC_EDIT2, y);
}


BEGIN_MESSAGE_MAP(MyDlgo, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &MyDlgo::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &MyDlgo::OnBnClickedButton1)
END_MESSAGE_MAP()


// MyDlgo 消息处理程序


void MyDlgo::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void MyDlgo::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	this->UpdateData(true);
	z = x;
	x = y;
	y = z;
	UpdateData(false);

}
