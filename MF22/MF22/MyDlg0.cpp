// MyDlg0.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MF22.h"
#include "MyDlg0.h"
#include "afxdialogex.h"


// MyDlg0 �Ի���

IMPLEMENT_DYNAMIC(MyDlg0, CDialogEx)

MyDlg0::MyDlg0(CWnd* pParent /*=NULL*/)
	: CDialogEx(MyDlg0::IDD, pParent)
	, a(0)
	, b(0)
	, c(0)
{

}

MyDlg0::~MyDlg0()
{
}

void MyDlg0::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, a);
	DDX_Text(pDX, IDC_EDIT2, b);
	DDX_Text(pDX, IDC_EDIT3, c);
}


BEGIN_MESSAGE_MAP(MyDlg0, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &MyDlg0::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &MyDlg0::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &MyDlg0::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &MyDlg0::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &MyDlg0::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &MyDlg0::OnBnClickedButton6)
END_MESSAGE_MAP()


// MyDlg0 ��Ϣ�������


void MyDlg0::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	this->UpdateData(true);
	c = a + b;
	UpdateData(false);
	

}


void MyDlg0::OnBnClickedButton2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	this->UpdateData(true);
	c = a*b;
	UpdateData(false);
}


void MyDlg0::OnBnClickedButton3()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	this->UpdateData(true);
	c = a-b;
	UpdateData(false);
}


void MyDlg0::OnBnClickedButton4()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	this->UpdateData(true);
	c = a / b;
	UpdateData(false);
}


void MyDlg0::OnBnClickedButton5()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	this->UpdateData(true);
	c = 1/a;
	UpdateData(false);
}


void MyDlg0::OnBnClickedButton6()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	this->UpdateData(true);
	
	while (c<=999)
	{
		int d = c*c;
		if (d == a || d == b)
		{
			break;
		}
		c++;
	}
	UpdateData(false);
}
