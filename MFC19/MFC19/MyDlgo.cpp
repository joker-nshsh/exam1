// MyDlgo.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC19.h"
#include "MyDlgo.h"
#include "afxdialogex.h"


// MyDlgo �Ի���

IMPLEMENT_DYNAMIC(MyDlgo, CDialogEx)

MyDlgo::MyDlgo(CWnd* pParent /*=NULL*/)
	: CDialogEx(MyDlgo::IDD, pParent)
	, a(_T(""))
	, b(0)
	, c(_T(""))
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


// MyDlgo ��Ϣ�������


void MyDlgo::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	this->UpdateData(true);
	c.Format(a+_T("%d"),b );
	UpdateData(false);
}
