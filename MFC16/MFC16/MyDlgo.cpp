// MyDlgo.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC16.h"
#include "MyDlgo.h"
#include "afxdialogex.h"


// MyDlgo �Ի���

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


// MyDlgo ��Ϣ�������


void MyDlgo::OnClose()
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);


	CString s = _T("�رնԻ���");
	dc.TextOutW(400, 200, s);
	Invalidate();

	CDialogEx::OnClose();
}


void MyDlgo::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	
	CDialogEx::OnOK();
}
