// MyDlg0.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC26.h"
#include "MyDlg0.h"
#include "afxdialogex.h"


// MyDlg0 对话框

IMPLEMENT_DYNAMIC(MyDlg0, CDialogEx)

MyDlg0::MyDlg0(CWnd* pParent /*=NULL*/)
	: CDialogEx(MyDlg0::IDD, pParent)
	, a1(0)
	, a2(0)
	, a3(0)
{

}

MyDlg0::~MyDlg0()
{
}

void MyDlg0::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, a1);
	DDX_Text(pDX, IDC_EDIT3, a2);
	DDX_Text(pDX, IDC_EDIT1, a3);
}


BEGIN_MESSAGE_MAP(MyDlg0, CDialogEx)
END_MESSAGE_MAP()


// MyDlg0 消息处理程序
