// MyDlgo.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC17.h"
#include "MyDlgo.h"
#include "afxdialogex.h"


// MyDlgo �Ի���

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


// MyDlgo ��Ϣ�������


void MyDlgo::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void MyDlgo::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	this->UpdateData(true);
	z = x;
	x = y;
	y = z;
	UpdateData(false);

}
