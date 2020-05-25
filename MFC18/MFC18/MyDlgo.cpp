// MyDlgo.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC18.h"
#include "MyDlgo.h"
#include "afxdialogex.h"


// MyDlgo 对话框

IMPLEMENT_DYNAMIC(MyDlgo, CDialogEx)

MyDlgo::MyDlgo(CWnd* pParent /*=NULL*/)
	: CDialogEx(MyDlgo::IDD, pParent)
	, a(0)
	, b(0)
	, c(0)
{

}

MyDlgo::~MyDlgo()
{
}

void MyDlgo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, a);
	DDX_Text(pDX, IDC_EDIT2, b);
	DDX_Text(pDX, IDC_EDIT3, c);
}


BEGIN_MESSAGE_MAP(MyDlgo, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &MyDlgo::OnBnClickedButton1)
END_MESSAGE_MAP()


// MyDlgo 消息处理程序


void MyDlgo::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	this->UpdateData(true);
	c = a + b;
	UpdateData(false);


}
