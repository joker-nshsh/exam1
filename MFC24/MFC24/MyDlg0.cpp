// MyDlg0.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC24.h"
#include "MyDlg0.h"
#include "afxdialogex.h"


// MyDlg0 对话框

IMPLEMENT_DYNAMIC(MyDlg0, CDialogEx)

MyDlg0::MyDlg0(CWnd* pParent /*=NULL*/)
	: CDialogEx(MyDlg0::IDD, pParent)
	, top1(0)
	, left1(0)
	, bottom1(0)
	, right1(0)
{

}

MyDlg0::~MyDlg0()
{
}

void MyDlg0::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, top1);
	DDX_Text(pDX, IDC_EDIT2, left1);
	DDX_Text(pDX, IDC_EDIT3, bottom1);
	DDX_Text(pDX, IDC_EDIT4, right1);
}


BEGIN_MESSAGE_MAP(MyDlg0, CDialogEx)
END_MESSAGE_MAP()


// MyDlg0 消息处理程序
