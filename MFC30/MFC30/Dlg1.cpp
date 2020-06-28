// Dlg1.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC30.h"
#include "Dlg1.h"
#include "afxdialogex.h"
#include "afxwin.h"
#include "afxcoll.h"
#include "MFC30Doc.h"
#include "MFC30View.h"
#include"Dlg1.h"
#include"fstream"
#include "string"
#include"iostream"
#include"vector"
#include"windows.h"
using namespace std;

// Dlg1 对话框

IMPLEMENT_DYNAMIC(Dlg1, CDialogEx)

Dlg1::Dlg1(CWnd* pParent /*=NULL*/)
	: CDialogEx(Dlg1::IDD, pParent)
	, q(0)
	, s(_T(""))
{

}

Dlg1::~Dlg1()
{
}

void Dlg1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, Box);
	DDX_Control(pDX, IDC_EDIT1, edit);
}


BEGIN_MESSAGE_MAP(Dlg1, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Dlg1::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Dlg1::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &Dlg1::OnBnClickedButton3)
END_MESSAGE_MAP()


// Dlg1 消息处理程序


void Dlg1::OnBnClickedButton1()
{
	q = Box.GetCurSel();
Box.GetText(q, s);
	edit.SetWindowTextW(s);
	// TODO:  在此添加控件通知处理程序代码
}


BOOL Dlg1::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	for (int i = 0; i < j.GetSize(); i++)
	{
		CString z = j.GetAt(i);
		Box.AddString(z);
	}
	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


void Dlg1::OnBnClickedButton2()
{
	edit.GetWindowTextW(s);
	Box.DeleteString(q);
Box.InsertString(-1, s);
	// TODO:  在此添加控件通知处理程序代码
}


void Dlg1::OnBnClickedButton3()
{
	ofstream ofs("学生名单.txt", ios::ate);
	int count = Box.GetCount();
	CString k;



	for (int i = 0; i < count; i++)
	{

		Box.GetText(i, k);

		USES_CONVERSION;
		string l = W2CA((LPCWSTR)k);

		ofs << l << endl;
	}
	ofs.close();
	// TODO:  在此添加控件通知处理程序代码
}
