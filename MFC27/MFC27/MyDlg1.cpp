// MyDlg1.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC27.h"
#include "MyDlg1.h"
#include "afxdialogex.h"


// MyDlg1 对话框

IMPLEMENT_DYNAMIC(MyDlg1, CDialogEx)

MyDlg1::MyDlg1(CWnd* pParent /*=NULL*/)
	: CDialogEx(MyDlg1::IDD, pParent)
{

}

MyDlg1::~MyDlg1()
{
}

void MyDlg1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, Box);
	DDX_Control(pDX, IDC_EDIT1, edit);
}


BEGIN_MESSAGE_MAP(MyDlg1, CDialogEx)
END_MESSAGE_MAP()


// MyDlg1 消息处理程序


BOOL MyDlg1::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CString s2 = s;
	edit.ReplaceSel(s);
	Box.AddString(s);
	
	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}
